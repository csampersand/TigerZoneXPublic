#pragma once

#ifndef Player_hpp
#define Player_hpp

#include "Tile.hpp"
#include "TileRelation.hpp"


class Player {
public:
	Player(TileRelation***);
	void incrementScore(int);
	int getScore();

protected:
	TileRelation*** Board;

private:
	int tigerCount;
	int crocodileCount;
	int score;
};


#endif /* Player_hpp */
