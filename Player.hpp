#pragma once

#ifndef Player_hpp
#define Player_hpp

#include "Tile.hpp"
#include "TileRelation.hpp"
#include "MoveEntity.hpp"


class Player {
public:
	Player(TileRelation***);
	void incrementScore(int);
	int getScore();
	virtual MoveEntity takeTurn(Tile*) const = 0;

protected:
	TileRelation*** Board;

private:
	int tigerCount;
	int crocodileCount;
	int score;
};


#endif /* Player_hpp */
