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

SocketInterface::SocketInterface(std::string server, std::string port, std::string tournamentPassword, std::string teamUsername, std::string teamPassword)
:IP(server), PORT(port), TOURNAMENT_PASSWORD(tournamentPassword), TEAM_USERNAME(teamUsername), TEAM_PASSWORD(teamPassword){
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

void SocketInterface::authenticate() {
    readLineFromSocket(); //'THIS IS SPARTA'
    writeLineToSocket("JOIN " + TOURNAMENT_PASSWORD);
    readLineFromSocket(); //'HELLO!'
    writeLineToSocket("I AM " + TEAM_USERNAME + ' ' + TEAM_PASSWORD);
    std::string contains_PID = readLineFromSocket(); //'WELCOME <pid> PLEASE WAIT FOR THE NEXT CHALLENGE'
    //TODO set pid
    //receiveChallenge();
}

void SocketInterface::receiveChallenge()
{
    std::string contains_CID_numOfRounds = readLineFromSocket(); //'NEW CHALLENGE <cid> YOU WILL PLAY <rounds> MATCHES'
    //TODO set numOfRounds
    for (int i = 0; i < numOfRounds; ++i) {
        beginRound();
    }
    readLineFromSocket(); //'END OF CHALLENGES'
}

void SocketInterface::beginRound() {
    std::string contains_RID = readLineFromSocket(); //'BEGIN ROUND <rid> OF <rounds>'
    beginMatch();
    readLineFromSocket(); //'END OF ROUND <rid> OF <rounds> PLEASE WAIT FOR THE NEXT MATCH'
}

void SocketInterface::beginMatch() {
    std::string line1 = readLineFromSocket(); //'YOUR OPPONENT IS PLAYER <pid>'
    std::string line2 = readLineFromSocket(); //'STARTING TILE IS <tile> AT <x> <y> <orientation>'
    //TODO forward this info to GameInteractor
    std::string line3 = readLineFromSocket(); //'THE REMAINING <number_tiles> TILES ARE [ <tiles> ]'
    //TODO set deck through GameInteractor and set numOfTiles
    //std::string tiles;
    std::string line4 = readLineFromSocket(); //'MATCH BEGINS IN <timeplan> SECONDS'
    
    a = GameInteractor();
    for (int i = 1; i < numOfTiles; ++i) {
        
    }
    std::string line5 = readLineFromSocket(); //'GAME <gid> OVER PLAYER <pid> <score> PLAYER <pid> <score>'
    std::string line6 = readLineFromSocket(); //'GAME <gid> OVER PLAYER <pid> <score> PLAYER <pid> <score>'
}

void SocketInterface::playTournament() {
    io_service = new boost::asio::io_service();
//    tcp::resolver resolver(io_service);
//    tcp::resolver::query query(IP, PORT);
//    tcp::resolver::iterator end_point_iterator = resolver.resolve(query);
//    tcp::resolver::iterator end;
    socket = new tcp::socket(*io_service);
//    boost::system::error_code error = boost::asio::error::host_not_found;
//    while (error && end_point_iterator != end) {
//        socket->close();
//        socket->connect(*end_point_iterator++, error);
//    }
//    if (error)
//        throw boost::system::system_error(error);
//    else
//        std::cout << "Successfully connected to tournament server." << std::endl; //DEBUG
    
    connect();
    authenticate();
    
}
