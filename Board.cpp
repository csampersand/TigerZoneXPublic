//
//  Board.cpp
//  TigerZoneX
//
//  Created by Jacob on 11/5/16.
//

#include "Board.hpp"

bool Board::placeTile(int x, int y, Tile* tile) {
    if(x > 142 || y > 142) return false;    //Invalid Board coordinate
    if(board[x][y] != NULL) return false;  //Tile already placed in coordinate
    
    TileRelation* newTile = new TileRelation(tile, board[x][y+1], board[x+1][y], board[x][y-1], board[x-1][y]);
    
    // Check if has neighbor
    
    // Check if neighbor matches
    if(newTile->getNTile() != NULL && newTile->getNTile()->getTile()->getSType() != tile->getNType())
        return false;
    else if(newTile->getETile() != NULL && newTile->getETile()->getTile()->getWType() != tile->getEType())
        return false;
    else if(newTile->getSTile() != NULL && newTile->getSTile()->getTile()->getNType() != tile->getSType())
        return false;
    else if(newTile->getWTile() != NULL && newTile->getWTile()->getTile()->getEType() != tile->getWType())
        return false;
    
    else {
        
    }
}

//bool Board::isPlacementValid(int x, int y, Tile* tileRelation) {
//    if(x > 142 || y > 142) return false;    //Invalid Board coordinate
//    if(board[x][y] != NULL) return false;  //Tile already placed in coordinate
//
//    bool adjacentTileFound = false;
//
//    //Check north edge
//    if(x - 1 >= 0){
//
//    }
//
//    //Check south edge
//    if(x + 1 >= 0){
//
//    }
//
//    //Check east edge
//    if(y + 1 >= 0){
//
//    }
//
//    //Check west edge
//    if(y - 1 >= 0){
//
//    }
//}
