//
//  TileRelation.hpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef TileRelation_hpp
#define TileRelation_hpp

#include <stdio.h>
#include "Tile.hpp"

class TileRelation {
private:
    Tile* tile;
    TileRelation* nTileRelation;
    TileRelation* eTileRelation;
    TileRelation* sTileRelation;
    TileRelation* wTileRelation;
public:
    TileRelation(Tile*, TileRelation*, TileRelation*, TileRelation*, TileRelation*);
    Tile* getTile();
    TileRelation* getNTile();
    TileRelation* getETile();
    TileRelation* getSTile();
    TileRelation* getWTile();
};

#endif /* TileRelation_hpp */
