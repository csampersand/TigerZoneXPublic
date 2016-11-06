//
//  Board.hpp
//  TigerZoneX
//
//  Created by Jacob on 11/5/16.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include "TileRelation.hpp"

class Board {
public:
    bool placeTile(int, int, Tile*);
private:
    TileRelation* board[143][143];
    TileRelation* firstTile;
    bool isPlacementValid(int, int, Tile*);
};

#endif /* Board_hpp */
