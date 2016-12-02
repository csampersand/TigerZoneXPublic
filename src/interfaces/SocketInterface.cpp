//
//  SocketInterface.cpp
//  TigerZoneX
//
//  Created by Chris on 11/30/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "SocketInterface.hpp"

using boost::asio::ip::tcp;

SocketInterface::SocketInterface(std::string server, std::string port, std::string tournamentPassword, std::string teamUsername, std::string teamPassword)
	: IP(server), PORT(port), TOURNAMENT_PASSWORD(tournamentPassword), TEAM_USERNAME(teamUsername), TEAM_PASSWORD(teamPassword){
	connect();
}

boost::system::system_error SocketInterface::getErrorCode()
{
	return error;
}

void SocketInterface::connect()
{
    tcp::resolver res(io_service);
	tcp::resolver::query query(IP, PORT);
    tcp::resolver::iterator end_point_iterator = res.resolve(query);
    sock = tcp::socket(io_service);
	boost::system::error_code error = boost::asio::error::host_not_found;
	while (error && end_point_iterator != end) {
		socket.close();
		socket.connect(*end_point_iterator++, error);
	}
	if (error)
		throw boost::system::system_error(error);
}

std::string SocketInterface::readLineFromSocket() {
	boost::asio::read_until(socket, buf, "\r\n", error);
	std::istream is(&buf);
	std::string line;
	std::getline(is, line);
	return line;
}

void SocketInterface::writeLineToSocket(std::string message) {
    boost::asio::write(socket, boost::asio::buffer(message), error);
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
    if (regexMatchNextMessage("THIS IS SPARTA!")) {
        writeLineToSocket("JOIN " + TOURNAMENT_PASSWORD);
    }
    if (regexMatchNextMessage("HELLO!")) {
        writeLineToSocket("I AM " + TEAM_USERNAME + " " + TEAM_PASSWORD);
    }
    regexMatchNextMessage("WELCOME (.+) PLEASE WAIT FOR THE NEXT CHALLENGE");
}

//void SocketInterface::receiveChallenge()
//{
//    int numOfRounds = stoi(regexSearchNextMessage("NEW CHALLENGE (\d+) YOU WILL PLAY (\d+) MATCHES")[2]);
//	for (int i = 0; i < numOfRounds; ++i) {
//		beginRound();
//	}
//    regexMatchNextMessage("END OF CHALLENGES");
//}
//
//void SocketInterface::beginRound() {
//	int rid = regexSearchNextMessage("BEGIN ROUND (\d+) OF (\d+)")[1];
//	beginMatch();
//    regexMatchNextMessage("END OF ROUND (\d+) OF (\d+) PLEASE WAIT FOR THE NEXT MATCH");
//}
//
//void SocketInterface::beginMatch() {
//	regexMatchNextMessage("YOUR OPPONENT IS PLAYER (.+)");
//    regexSearchNextMessage("STARTING TILE IS <tile> AT <x> <y> <orientation>");
//	//TODO forward this info to GameInteractor
//	std::string line3 = readLineFromSocket(); //'THE REMAINING <number_tiles> TILES ARE [ <tiles> ]'
//	//TODO set deck through GameInteractor and set numOfTiles
//	std::string line4 = readLineFromSocket(); //'MATCH BEGINS IN <timeplan> SECONDS'
//	for (int i = 0; i < numOfTiles; ++i) {
//		//TODO
//	}
//	std::string line5 = readLineFromSocket(); //'GAME <gid> OVER PLAYER <pid> <score> PLAYER <pid> <score>'
//	std::string line6 = readLineFromSocket(); //'GAME <gid> OVER PLAYER <pid> <score> PLAYER <pid> <score>'
//}
//
//void SocketInterface::playTournament() {
//    //
//}
