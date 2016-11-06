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