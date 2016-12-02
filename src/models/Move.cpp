//
//  Move.cpp
//  TigerZoneX
//
//  Created by Chris on 12/1/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "Move.hpp"
#include <string>

Move::Move(int playerId, int x, int y, Tile* tile, int rotations, bool croc, int tigerZone) {
    this->playerId = playerId;
    this->tile = tile;
    this->rotations = rotations;
    this->x = x;
    this->y = y;
    this->croc = croc;
    this->tigerZone = tigerZone;
}
