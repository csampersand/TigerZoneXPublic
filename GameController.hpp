#pragma once

#ifndef Game_hpp
#define GameController_hpp

#include <stdio.h>
#include <vector>
#include "TileRelation.hpp" //Change to Board? TODO: 
#include "Player.hpp"
#include "Board.hpp"
#include "TileDeck.hpp"

class GameController {
public:
	GameController(int);//call Startgame
	void nextTurn();//iterate through
	void startGame(int); //pass in playerCount
	//initialize board
	//initialize tileDeck
	//init player objects
	int endGame(); // Choose winner, call end game scoring
	void scoreGame();
	//TODO
private:
	Board* board;
	TileDeck Deck;
	std::vector<Player*> players;
	int turnIndex;
};


#endif /* Game_hpp */
