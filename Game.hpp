#pragma once

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <vector>
#include "TileRelation.hpp" //Change to Board? TODO: 
#include "Player.hpp"
<<<<<<< HEAD
#include "Board.hpp"
=======
>>>>>>> b0b627c... Added skeleton code for Game and Player objects


class Game {
public:
<<<<<<< HEAD
	Game(int);//call Startgame
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
=======
	Game(int);
	void nextTurn();
	void startGame(int); //pass in playerCount
	void endGame(); // Choose winner, call end game scoring
	void scoreGame();
private:
	TileRelation* board[145][145];
>>>>>>> b0b627c... Added skeleton code for Game and Player objects
	std::vector<Player*> players;
	int turnIndex;
};


#endif /* Game_hpp */