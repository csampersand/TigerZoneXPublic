//
//  SocketInterface.cpp
//  TigerZoneX
//
//  Created by Chris on 11/30/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "SocketInterface.hpp"
#include <regex>
#include <sstream>
#include <vector>
#include <chrono>
#include <random>

using boost::asio::ip::tcp;

SocketInterface::SocketInterface(std::string server, std::string port, std::string tournamentPassword, std::string teamUsername, std::string teamPassword)
:IP(server), PORT(port), TOURNAMENT_PASSWORD(tournamentPassword), TEAM_USERNAME(teamUsername), TEAM_PASSWORD(teamPassword){
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
    numOfRounds = stoi(challengeMatch[2]);
	do {
		beginMatch();
	} while (readLineFromSocket().find_last_of('H') == std::string::npos);
}

void SocketInterface::beginRound() {
    std::smatch beginRoundMatch = regexSearchNextMessage("BEGIN ROUND (.+) OF <rounds>");
    RID = stoi(beginRoundMatch[1]);
    roundCount = stoi(beginRoundMatch[2]);
    beginMatch();
    readLineFromSocket(); //'END OF ROUND <rid> OF <rounds> PLEASE WAIT FOR THE NEXT MATCH'
}

void SocketInterface::beginMatch() {
    opponent = regexSearchNextMessage("YOUR OPPONENT IS PLAYER (.+)")[1];
    std::string startTile;
    std::string startOrientation;
    std::smatch line2 = regexSearchNextMessage("STARTING TILE IS (.+) AT (.+) (.+) <orientation>"); //'STARTING TILE IS <tile> AT <x> <y> <orientation>'
	startX = stoi(line2[2]);
	startY = stoi(line2[3]);
	int rotations;
	if (line2[4].compare("0") == 0) rotations = 0;
	else if (line2[4].compare("90") == 0) rotations = 3;
	else if (line2[4].compare("180") == 0) rotations = 2;
	else rotations = 1;

    
    std::string line3 = readLineFromSocket(); //'THE REMAINING <number_tiles> TILES ARE [ <tiles> ]'
	std::stringstream stream(line3);
	std::string buffer;
	stream >> buffer; //THE
	stream >> buffer; //Remaining
	stream >> buffer; //<number_tiles>
	numOfTiles = stoi(buffer);
	stream >> buffer; //TILES
	stream >> buffer; //ARE
	std::vector<Tile*> deckTiles;
	while (!stream.eof()) {
		stream >> buffer;
		deckTiles.push_back(GameInteractor::createTileFromSequence(buffer));
	}
	a.second.setupGame(GameInteractor::createTileFromSequence(line2[1]), 0, 0, deckTiles);
	b.second.setupGame(GameInteractor::createTileFromSequence(line2[1]), 0, 0, deckTiles);
    std::string line4 = readLineFromSocket(); //'MATCH BEGINS IN <timeplan> SECONDS'

	std::smatch firstGameReq = regexSearchNextMessage("MAKE YOUR MOVE IN GAME (.+) WITHIN (.+) SECOND: MOVE (.+) PLACE (.+)");
	a.first = firstGameReq[1];
	makeMove(1, firstGameReq[4]);
	

    for (int i = 2; i <= numOfTiles; ++i) { //i represents move count
		

		//MAKE YOUR MOVE IN GAME <gid> WITHIN <timemove> SECOND: MOVE <#> PLACE <tile>
		//THE MOVE
		//
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

void SocketInterface::makeMove(int moveNum, std::string tile) {
	std::vector<Move> moves = a.second.listPossibleMoves();
	typedef std::chrono::high_resolution_clock myclock;
	myclock::time_point beginning = myclock::now();
	myclock::duration d = myclock::now() - beginning;
	unsigned seed = d.count();
	auto engine = std::default_random_engine{};
	engine.seed(seed);
	std::shuffle(std::begin(moves), std::end(moves), engine);
	Move move;
	if (moves.size() > 0) {
		move = moves.front();
		a.second.playTurn(move.x, move.y, move.rotations);
		std::string rotations;
		if (move.rotations == 1) rotations = "270";
		else if (move.rotations == 3) rotations = "90";
		else if (move.rotations == 2) rotations = "180";
		else rotations = "0";
		writeLineToSocket("GAME " + a.first + " MOVE " + std::to_string(moveNum) + " PLACE " + tile + " AT " + std::to_string(move.x) + " " + std::to_string(move.y) + " " + rotations + " NONE\n");
	}
	else {
		move.pass = true;
	}
}

void SocketInterface::readMoves() {
	//std::smatch line1 = regexSearchNextMessage("MAKE YOUR MOVE IN GAME (.+) WITHIN (.+) SECOND: MOVE (.+) PLACE (.+)");
}
