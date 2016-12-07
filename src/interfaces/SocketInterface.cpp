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

void SocketInterface::gameOver() {
    std::string tempGameID;
    tempGameID = regexSearchNextMessage("GAME " + tempGameID + " OVER SEND OUTCOME")[1];
    if(tempGameID == gameId){
        sendOutcome();
    }

}

void SocketInterface::receiveChallenge()
{
    std::smatch challengeMatch = regexSearchNextMessage("NEW CHALLENGE (\\d+) YOU WILL PLAY (\\d+) MATCH(?:ES)?");
    std::string cid = challengeMatch[1];
    roundCount = stoi(challengeMatch[2]);
    for (int i = 0; i < roundCount; ++i) {
        beginRound();
    }
    readLineFromSocket(); //'END OF CHALLENGES'
}

void SocketInterface::beginRound() {
    std::smatch beginRoundMatch = regexSearchNextMessage("BEGIN ROUND (\\d+) OF (\\d+)");
    rid = stoi(beginRoundMatch[1]);
    roundCount = stoi(beginRoundMatch[2]);
    beginMatch();
    readLineFromSocket(); //'END OF ROUND <rid> OF <rounds> PLEASE WAIT FOR THE NEXT MATCH'
}

void SocketInterface::beginMatch() {
    opponent = regexSearchNextMessage("YOUR OPPONENT IS PLAYER (.+)")[1];
    std::smatch startTileMatch = regexSearchNextMessage("STARTING TILE IS (\\w{4}.) AT (\\d+) (\\d+) (\\d+)");
    std::string startTileSequence = startTileMatch[1];
    int startX = stoi(startTileMatch[2]) + 76;
    int startY = stoi(startTileMatch[3]) + 76;
    std::string startOrientation = startTileMatch[4];
    
    // TODO clean up this regex
    std::smatch defineDeckMatch = regexSearchNextMessage("THE REMAINING (.+) TILES ARE \\[ (.+) \\]");
    tileCount = stoi(defineDeckMatch[1]);
    std::string deckTilesString = defineDeckMatch[2];
    std::vector<Tile*> deckTiles;
    
    std::stringstream ss(deckTilesString);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> deckTilesSequences(end, begin);
    
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
        this->getInteractor().rotateTile(startTile, 1);
    }
    
    Game* a = new Game();
    Game* b = new Game();
    this->getInteractor().setGame(*a);
    this->getInteractor().setupGame(startTile, startX, startY, deckTiles);
    
    this->getInteractor().setGame(*b);
    this->getInteractor().setupGame(startTile, startX, startY, deckTiles);
    
    
    
    std::string line4 = readLineFromSocket(); //'MATCH BEGINS IN <timeplan> SECONDS'

    for (int i = 0; i < tileCount; ++i) {
        if (i > 0) {
            // Get moves and place
        }
        
        std::smatch moveMatch = regexSearchNextMessage("MAKE YOUR MOVE IN GAME (\\w) WITHIN (\\d+) SECONDS?: MOVE (\\d+) PLACE (\\w{4}.)");
        gameId = moveMatch[1];
        moveNumber = moveMatch[3];
        if (gameId == "A") {
            this->getInteractor().setGame(*a);
        }
        else {
            this->getInteractor().setGame(*b);
        }
        this->currentPlayer = pid;
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

void SocketInterface::update() {
    if (currentPlayer == pid) {
        Move aiMove = this->getInteractor().getLastMove();
        // GAME A MOVE 1 PLACE TLTTP AT 0 1 90 TIGER 8
        this->writeLineToSocket("GAME " + gameId + " MOVE " + moveNumber + " PLACE " + );
    }
}

void SocketInterface::sendOutcome(){
    this->writeLineToSocket("GAME " + gameId + " OVER PLAYER " + pid + " " + this->getInteractor()->getGame()->getPlayer(0)->getScore() + " PLAYER " + pid + this->getInteractor()->getGame()->getPlayer(1))->getScore());
    
}

void SocketInterface::playTournament() {
    io_service = new boost::asio::io_service();
    socket = new tcp::socket(*io_service);
    
    connect();
    authenticate();
    receiveChallenge();
    
}
