//
//  Board.cpp
//  TigerZoneX
//
//  Created by Jacob on 11/5/16.
//

#include "Board.hpp"

bool Board::placeTile(int x, int y, Tile* tile) {
    // TODO: Make sure this doesn't break things by checking tiles off the board
    if(x > 142 || y > 142) return false;    //Invalid Board coordinate
    if(board[x][y] != NULL) return false;  //Tile already placed in coordinate
    
    TileRelation* newTile = new TileRelation(tile, board[x][y+1], board[x+1][y], board[x][y-1], board[x-1][y]);
    
    // Check for at least 1 neighbor
    if (newTile->getNTileRelation() == NULL && newTile->getETileRelation() == NULL && newTile->getSTileRelation() == NULL && newTile->getWTileRelation() == NULL)
        return false;
    
    // Check to make sure all neighbor sides match
    if (newTile->getNTileRelation() != NULL && newTile->getNTileRelation()->getTile()->getSType() != tile->getNType())
        return false;
    else if (newTile->getETileRelation() != NULL && newTile->getETileRelation()->getTile()->getWType() != tile->getEType())
        return false;
    else if (newTile->getSTileRelation() != NULL && newTile->getSTileRelation()->getTile()->getNType() != tile->getSType())
        return false;
    else if (newTile->getWTileRelation() != NULL && newTile->getWTileRelation()->getTile()->getEType() != tile->getWType())
        return false;
    
    // Have all neighbors reference the newTile
    if (newTile->getNTileRelation() != NULL) {
        newTile->getNTileRelation()->setSTileRelation(newTile);
    }
    if (newTile->getETileRelation() != NULL) {
        newTile->getETileRelation()->setSTileRelation(newTile);
    }
    if (newTile->getSTileRelation() != NULL) {
        newTile->getSTileRelation()->setSTileRelation(newTile);
    }
    if (newTile->getWTileRelation() != NULL) {
        newTile->getWTileRelation()->setSTileRelation(newTile);
    }
    
    return true;
}
