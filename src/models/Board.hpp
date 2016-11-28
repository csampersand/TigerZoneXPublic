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
    TileRelation* firstTile;
    //Make sure to start at 153,153
    void placeLandmarks(int, int, Tile*);
public:
    Board(Tile*);
    
    TileLandmark* getTileLandmark(int,int,int);
    TileRelation* getTileRelation(int,int);
    void setTileLandmark(int,int,int,TileLandmark*);
    void setTileRelation(int,int,TileRelation*);
};

#endif /* Board_hpp */
