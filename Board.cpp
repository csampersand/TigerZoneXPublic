//
//  Board.cpp
//  TigerZoneX
//
//  Created by Jacob on 11/5/16.
//

#include "Board.hpp"

bool Board::placeTile(int x, int y, TileRelation* tileRelation) {
    if(x > 142 || y > 142) return false;    //Invalid Board coordinate
    if(_board[x][y] != null) return false;  //Tile already placed in coordinate


}

bool Board::isPlacementValid(int x, int y, TileRelation * tileRelation) {
    if(x > 142 || y > 142) return false;    //Invalid Board coordinate
    if(_board[x][y] != null) return false;  //Tile already placed in coordinate

    bool adjacentTileFound = false;

    //Check north edge
    if(x - 1 >= 0){

    }

    //Check south edge
    if(x + 1 >= 0){

    }

    //Check east edge
    if(y + 1 >= 0){

    }

    //Check west edge
    if(y - 1 >= 0){

    }
}