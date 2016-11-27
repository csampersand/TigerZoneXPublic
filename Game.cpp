#include "Game.hpp"
#include <stdio.h>
#include "iostream"
#include <vector>
#include "Player.hpp"
#include "Board.hpp"

Game::Game(int playerCount) {
	
	startGame(playerCount);

}

void Game::nextTurn() {
	int numOfPlayers = players.size();
	if (this->turnIndex >= numOfPlayers) {
		this->turnIndex = 0;
	}
	else {
		this->turnIndex++;
	}
}

void Game::startGame(int playerCount) {
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

int Game::endGame() { // Choose winner, call end game scoring
	//return the index of the player that won
	


	return 0;
}

void Game::scoreGame() {
	
}