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
#include "TileLandmark.hpp"

class Board {
private:
    TileRelation* tiles[153][153];
    TileLandmark* landmarks[153][153][9];
    TileDeck deck;
    TileRelation* firstTile;
    //Make sure to start at 45,45
    void placeLandmarks(int, int, Tile*);
public:
    Board(Tile*);
    
    TileLandmark* getTileLandmark(int,int,int);
    TileRelation* getTileRelation(int,int);
    TileDeck getDeck();
};

#endif /* Board_hpp */
