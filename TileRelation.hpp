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
    TileRelation(Tile*);
    TileRelation(Tile*, TileRelation*, TileRelation*, TileRelation*, TileRelation*);
    Tile* getTile();
    void setTile(Tile*);
    TileRelation* getNTileRelation();
    TileRelation* getETileRelation();
    TileRelation* getSTileRelation();
    TileRelation* getWTileRelation();
    void setNTileRelation(TileRelation*);
    void setETileRelation(TileRelation*);
    void setSTileRelation(TileRelation*);
    void setWTileRelation(TileRelation*);
};

#endif /* TileRelation_hpp */
