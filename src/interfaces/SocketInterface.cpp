//
//  SocketInterface.cpp
//  TigerZoneX
//
//  Created by Chris on 11/30/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "SocketInterface.hpp"
#include <regex>
#include "Tile.hpp"
#include <vector>

using boost::asio::ip::tcp;

SocketInterface::SocketInterface(GameInteractor& gi, std::string server, std::string port, std::string tournamentPassword, std::string teamUsername, std::string teamPassword)
:Interface(gi), IP(server), PORT(port), TOURNAMENT_PASSWORD(tournamentPassword), TEAM_USERNAME(teamUsername), TEAM_PASSWORD(teamPassword){
    myTurn = true;
    playTournament();
}

void SocketInterface::update() {
    if (myTurn) {
//        writeLineToSocket("GAME B MOVE 2 PLACE LJTJ- AT 0 2 180 TIGER 8");
    }
}

boost::system::system_error SocketInterface::getErrorCode()
{
    return error;
}

void SocketInterface::connect()
{
    tcp::resolver resolver(*io_service);
    tcp::resolver::query query(IP, PORT);
    tcp::resolver::iterator end_point_iterator = resolver.resolve(query);
    tcp::resolver::iterator end;
    boost::system::error_code error = boost::asio::error::host_not_found;
    while (error && end_point_iterator != end) {
        socket->close();
        socket->connect(*end_point_iterator++, error);
    }
    if (error)
        throw boost::system::system_error(error);
    else
        std::cout << "Successfully connected to tournament server." << std::endl; //DEBUG
}

std::string SocketInterface::readLineFromSocket() {
    boost::asio::streambuf buf;
    boost::asio::read_until(*socket, buf, '\n', error);
    std::istream is(&buf);
    std::string line;
    std::getline(is, line);
    std::cout << "Server: " + line << std::endl; //DEBUG
    return line;
}

void SocketInterface::writeLineToSocket(std::string message) {
    std::cout << "Client: " + message << std::endl; //DEBUG
    boost::asio::write(*socket, boost::asio::buffer(message + '\n'), error);
}

std::smatch SocketInterface::regexSearchNextMessage(const char* expression) {
    std::regex r(expression);
    std::smatch match;
    std::string message = readLineFromSocket();
    
    std::regex_search(message, match, r);
    
    return match;
}

bool SocketInterface::regexMatchNextMessage(const char* expression) {
    std::regex r(expression);
    std::smatch match;
    std::string message = readLineFromSocket();
    
    return std::regex_match(message, match, r);
}

void SocketInterface::authenticate() {
    readLineFromSocket(); //'THIS IS SPARTA'
    writeLineToSocket("JOIN " + TOURNAMENT_PASSWORD);
    readLineFromSocket(); //'HELLO!'
    writeLineToSocket("I AM " + TEAM_USERNAME + ' ' + TEAM_PASSWORD);
    pid = regexSearchNextMessage("WELCOME (.+) PLEASE WAIT FOR THE NEXT CHALLENGE")[1];
}

void SocketInterface::receiveChallenge()
{
    std::smatch challengeMatch = regexSearchNextMessage("NEW CHALLENGE (.+) YOU WILL PLAY (.+) MATCH(?:ES)?");
    std::string cid = challengeMatch[1];
    roundCount = stoi(challengeMatch[2]);
    for (int i = 0; i < roundCount; ++i) {
        beginRound();
    }
    readLineFromSocket(); //'END OF CHALLENGES'
}

void SocketInterface::beginRound() {
    std::smatch beginRoundMatch = regexSearchNextMessage("BEGIN ROUND (.+) OF (.+)");
    rid = stoi(beginRoundMatch[1]);
    roundCount = stoi(beginRoundMatch[2]);
    beginMatch();
    readLineFromSocket(); //'END OF ROUND <rid> OF <rounds> PLEASE WAIT FOR THE NEXT MATCH'
}

void SocketInterface::beginMatch() {
    opponent = regexSearchNextMessage("YOUR OPPONENT IS PLAYER (.+)")[1];
    std::smatch startTileMatch = regexSearchNextMessage("STARTING TILE IS (.+) AT (.+) (.+) (.+)");
    std::string startTileSequence = startTileMatch[1];
    int startX = stoi(startTileMatch[2]) + 76;
    int startY = stoi(startTileMatch[3]) + 76;
    std::string startOrientation = startTileMatch[4];
    
    std::smatch defineDeckMatch = regexSearchNextMessage("THE REMAINING (.+) TILES ARE \\[ (.+) \\]");
    tileCount = stoi(defineDeckMatch[1]);
    std::string deckTilesString = defineDeckMatch[2];
    std::vector<Tile*> deckTiles;
    
    std::stringstream ss(deckTilesString);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> deckTilesSequences(begin, end);
    
    for (auto i : deckTilesSequences) {
        deckTiles.push_back(GameInteractor::createTileFromSequence(i));
    }
    
//    Tile* startTile = GameInteractor::createTileFromSequence(startTileSequence);
    
    Tile* startTile = GameInteractor::createTileFromSequence("TLTJ-");
    
    if (startOrientation == "90") {
        this->getInteractor().rotateTile(startTile, 3);
    }
    else if (startOrientation == "180") {
        this->getInteractor().rotateTile(startTile, 2);
    }
    else if (startOrientation == "270") {
        this->getInteractor().rotateTile(startTile, 3);
    }
    
    Game* a = new Game();
    Game* b = new Game();
    this->getInteractor().setGame(*a);
    this->getInteractor().setupGame(startTile, startX, startY, deckTiles);
    
    this->getInteractor().setGame(*b);
    this->getInteractor().setupGame(startTile, startX, startY, deckTiles);
    
    
    
    std::string line4 = readLineFromSocket(); //'MATCH BEGINS IN <timeplan> SECONDS'

    for (int i = 1; i < tileCount; ++i) {
        std::string game = regexSearchNextMessage("MAKE YOUR MOVE IN GAME (.)")[1];
        if (game == "A") {
            this->getInteractor().setGame(*a);
        }
        else {
            this->getInteractor().setGame(*b);
        }
        
        this->getInteractor().notifyInterfaces();
        
        
        
        // TODO
        // Need to handle sequencing
        // call interactor.notifyInterfaces() to start the bot
        // Then skip the right amount of messages
        // Convert appropriate messages to playTurn
        // Convert interactor.getLastTurn() to data to write to socket
        // ^ do that every time we receive message prompting for turn
        // No need to write update function for socket interface
        // Bot will run automatically every time we play a turn from socket
        // so get messages will always be updated
        
        
        
    }
    
    std::string line5 = readLineFromSocket(); //'GAME <gid> OVER PLAYER <pid> <score> PLAYER <pid> <score>'
    std::string line6 = readLineFromSocket(); //'GAME <gid> OVER PLAYER <pid> <score> PLAYER <pid> <score>'
}

void SocketInterface::playTournament() {
    io_service = new boost::asio::io_service();
    socket = new tcp::socket(*io_service);
    
    connect();
    authenticate();
    receiveChallenge();
    
}
