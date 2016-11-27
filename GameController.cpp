#include "GameController.hpp"
#include <stdio.h>
#include "iostream"
#include <vector>
#include "Player.hpp"
#include "Board.hpp"

GameController::GameController(Player* playerOne, Player* playerTwo): turnIndex(0) {
	this->board = new Board(Deck.drawTile());
	this->players[0] = playerOne;
	this->players[1] = playerTwo;
}

void GameController::startGame() {
	MoveEntity currentMove;

	while (Deck.size() > 0) {
		//Request move from current player
		currentMove = players[turnIndex]->takeTurn(Deck.drawTile);
		
		if (!currentMove.forfeit) {
			//TODO
			//Attempt to play move
			//if the move is invalid the current player forfeits
		}
		else {
			endGame(turnIndex);
			return;
		}

		//update turn index
		turnIndex = ++turnIndex % 2;
	}

	endGame();
}

void GameController::endGame() { // Choose winner, call end game scoring
	//return the index of the player that won
	
}

void GameController::endGame(int forfeitingPlayer) {

}

void GameController::scoreGame() {
	
}