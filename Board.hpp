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
    bool placeTile(int, int, TileRelation*);

private:
    TileRelation _board[143][143];
    bool isPlacementValid(int, int, TileRelation*);
};

#endif /* Board_hpp */