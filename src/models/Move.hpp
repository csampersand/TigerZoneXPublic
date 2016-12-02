#ifndef Move_hpp
#define Move_hpp

#include "Tile.hpp"
#include <string>

struct Move {
    Move(int playerId, int x, int y, const std::string& tile, int rotations, bool croc, int tigerZone) {
        this->playerId = playerId;
        this->tile = tile;
        this->rotations = rotations;
        this->x = x;
        this->y = y;
        this->croc = croc;
        this->tigerZone = tigerZone;
    }
	int playerId;
    std::string tile;
	int rotations;
	int x;
	int y;
	bool croc;
	int tigerZone;
};

#endif
