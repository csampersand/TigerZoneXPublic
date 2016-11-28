#pragma once

#ifndef Game_hpp
#define GameController_hpp

#include <stdio.h>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
#include "TileDeck.hpp"

class GameController {
public:
	GameController(Player*, Player*);
	void startGame();

private:
	Board* board;
	TileDeck Deck;
	Player* players[2];
	int turnIndex;

	void endGame(); // Choose winner, call end game scoring
	void endGame(int); //int indicates the index of the player who forfeited
	void scoreGame();
};


#endif /* Game_hpp */
