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
    TileRelation* board[145][145];
    TileLandmark* landmarks[145][145][9];
    TileDeck deck;
    TileRelation* firstTile;
    //Make sure to start at 45,45
    void placeLandmarks(int, int, Tile*);
public:
    Board();
    bool isPlacementValid(int, int, Tile*);
    bool placeTile(int, int, Tile*);
    static int getLowestZone(int, int, TileLandmark*);
private:
    TileRelation* board[153][153];    
};

#endif /* Board_hpp */
