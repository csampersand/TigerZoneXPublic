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
#include "TileDeck.hpp"

class Board {
public:
    Board();
    bool isPlacementValid(int, int, Tile*);
    bool placeTile(int, int, Tile*);
private:
    TileRelation* board[153][153];
    TileDeck deck;
    TileRelation* firstTile;
	//Make sure to start at 45,45
};

#endif /* Board_hpp */
