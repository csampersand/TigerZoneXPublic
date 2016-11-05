//
//  TileRelation.cpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "TileRelation.hpp"

TileRelation* TileRelation::getNorthTile() {
    return this->nTileRelation;
}
TileRelation* TileRelation::getEastTile() {
    return this->eTileRelation;
}
TileRelation* TileRelation::getSouthTile() {
    return this->sTileRelation;
}
TileRelation* TileRelation::getWestTile() {
    return this->wTileRelation;
}
