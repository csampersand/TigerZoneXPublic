#pragma once
#include "Tile.hpp"

struct MoveEntity {
	//Forfeit constructor
	MoveEntity() {	
		forfeit = true;
	}
	//Valid move constructor
	MoveEntity(Tile* tile, int numOfTileRotations, int x_coord, int y_coord, bool crocodile, int tigerZone) {
		this->tile = tile;
		this->numOfTileRotations = numOfTileRotations;
		this->x_coord = x_coord;
		this->y_coord = y_coord;
		this->crocodile = crocodile;
		this->tigerZone = tigerZone;
		this->forfeit = false;
	}

	bool forfeit;
	Tile* tile;
	int numOfTileRotations;
	int x_coord;
	int y_coord;
	bool crocodile;
	int tigerZone; //if tigerZone = -1, then no tiger was placed
};