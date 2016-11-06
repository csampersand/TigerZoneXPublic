//
//  TileRelation.cpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "TileRelation.hpp"

Tile* TileRelation::getTile() {
    return this->tile;
}
TileRelation* TileRelation::getNTile() {
    return this->nTileRelation;
}
TileRelation* TileRelation::getETile() {
    return this->eTileRelation;
}
TileRelation* TileRelation::getSTile() {
    return this->sTileRelation;
}
TileRelation* TileRelation::getWTile() {
    return this->wTileRelation;
}
