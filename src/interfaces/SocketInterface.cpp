//
//  SocketInterface.cpp
//  TigerZoneX
//
//  Created by Chris on 11/30/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "SocketInterface.hpp"
#include <regex>

using boost::asio::ip::tcp;

SocketInterface::SocketInterface(GameInteractor& gi, std::string server, std::string port, std::string tournamentPassword, std::string teamUsername, std::string teamPassword)
:Interface(gi), IP(server), PORT(port), TOURNAMENT_PASSWORD(tournamentPassword), TEAM_USERNAME(teamUsername), TEAM_PASSWORD(teamPassword){
    playTournament();
}

void SocketInterface::update() {
    
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
    std::smatch challengeMatch = regexSearchNextMessage("NEW CHALLENGE (.+) YOU WILL PLAY (.+) MATCHES");
    std::string cid = challengeMatch[1];
    roundCount = stoi(challengeMatch[2]);
    for (int i = 0; i < numOfRounds; ++i) {
        beginRound();
    }
    readLineFromSocket(); //'END OF CHALLENGES'
}

void SocketInterface::beginRound() {
    std::smatch beginRoundMatch = regexSearchNextMessage("BEGIN ROUND <rid> OF <rounds>");
    rid = stoi(beginRoundMatch[1]);
    roundCount = stoi(beginRoundMatch[2]);
    beginMatch();
    readLineFromSocket(); //'END OF ROUND <rid> OF <rounds> PLEASE WAIT FOR THE NEXT MATCH'
}

void SocketInterface::beginMatch() {
    opponent = regexSearchNextMessage("YOUR OPPONENT IS PLAYER (.)+")[1];
    std::string startTile;
    std::string startX;
    std::string startY;
    std::string startOrientation;
    Game* a = new Game();
    Game* b = new Game();
    std::string line2 = readLineFromSocket(); //'STARTING TILE IS <tile> AT <x> <y> <orientation>'
    
    std::string line3 = readLineFromSocket(); //'THE REMAINING <number_tiles> TILES ARE [ <tiles> ]'
    //TODO set deck through GameInteractor and set numOfTiles
    //std::string tiles;
    std::string line4 = readLineFromSocket(); //'MATCH BEGINS IN <timeplan> SECONDS'

    for (int i = 1; i < numOfTiles; ++i) {
        
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
