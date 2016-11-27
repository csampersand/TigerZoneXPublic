#include "GameController.hpp"
#include <stdio.h>
#include "iostream"
#include <vector>
#include "Player.hpp"
#include "Board.hpp"

GameController::GameController(int playerCount) {
	
	startGame(playerCount);

}

void GameController::nextTurn() {
	++this->turnIndex;
	if (this->turnIndex >= players.size()) {
		this->turnIndex = 0;
	}
}

void GameController::startGame(int playerCount) {
	this->turnIndex = 0;
	if (playerCount >= 2) {
		std::vector<Player*> players(playerCount);
		for (int i = 0; i < playerCount; i++) {
			Player *temp = new Player();
			players[i] = temp;
		}
		this->players = players;
	}
	else {
		std::cout << "ERROR: the player count needs to be 2 or greater!\n";
	}
	//initilalize board
	Board *newBoard = new Board();
	this->board = newBoard;
	//initialize tileDeck
}

int GameController::endGame() { // Choose winner, call end game scoring
	//return the index of the player that won
	


	return 0;
}

void GameController::scoreGame() {
	
}
