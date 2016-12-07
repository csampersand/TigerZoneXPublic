//
//  SocketInterface.hpp
//  TigerZoneX
//
//  Created by Chris on 11/30/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef SocketInterface_hpp
#define SocketInterface_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
#include <regex>
#include <boost/regex.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "GameInteractor.hpp"
#include "Game.hpp"
#include "Interface.hpp"
#include <unordered_map>
#include "Move.hpp"

using boost::asio::ip::tcp;

class SocketInterface : public Interface {
private:
    boost::system::error_code error;
    tcp::socket* socket;
    boost::asio::io_service* io_service;
    std::string IP;
    std::string PORT;
    std::string TOURNAMENT_PASSWORD;
    std::string TEAM_USERNAME;
    std::string TEAM_PASSWORD;
    std::string pid;
    std::string cid;
    std::string rid;
    int roundCount;
    int tileCount;
    std::string opponent;
    std::string currentPlayer;
    std::string moveNumber;
    std::string gameId;
    GameInteractor a;
    GameInteractor b;
    std::unordered_map<std::string, GameInteractor> activeGames;
    bool myTurn;
    
    int numOfRounds;
    int numOfTiles; //Not including starting tile
public:
    SocketInterface(GameInteractor& gi, std::string server, std::string port, std::string tournamentPassword, std::string teamUsername, std::string teamPassword);
    void update();
    std::string readLineFromSocket();
    void writeLineToSocket(std::string message);
    
    boost::system::system_error getErrorCode();
    std::smatch regexSearchNextMessage(const char*);
    bool regexMatchNextMessage(const char*);
    
    void connect();
    
    void gameOver();
    
    void authenticate();
    
    void receiveChallenge();
    
    void beginRound();
    
    void beginMatch();
    
    void receiveMove();
    
    void sendMove();
    
    void endMatch();
    
    void playTournament();
    
    void sendOutcome();
    
};

#endif /* SocketInterface_hpp */
