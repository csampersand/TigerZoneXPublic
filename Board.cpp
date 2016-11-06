//
//  Board.cpp
//  TigerZoneX
//
//  Created by Jacob on 11/5/16.
//

#include "Board.hpp"

Board::Board() {
    this->firstTile = new TileRelation(this->deck.drawTile());
    board[72][72] = this->firstTile;
}

bool Board::isPlacementValid(int x, int y, Tile* tile) {
    // TODO: Make sure this doesn't break things by checking tiles off the board
    if(x > 142 || y > 142) return false;    //Invalid Board coordinate
    if(board[x][y] != NULL) return false;  //Tile already placed in coordinate
    
    // Check for at least 1 neighbor
    if (board[x][y+1] == NULL && board[x+1][y] == NULL && board[x][y-1] == NULL && board[x-1][y] == NULL)
        return false;
    
    // Check to make sure all neighbor sides match
    if (board[x][y+1] != NULL && board[x][y+1]->getTile()->getSType() != tile->getNType())
        return false;
    else if (board[x+1][y] != NULL && board[x+1][y]->getTile()->getWType() != tile->getEType())
        return false;
    else if (board[x][y-1] != NULL && board[x][y-1]->getTile()->getNType() != tile->getSType())
        return false;
    else if (board[x-1][y] != NULL && board[x-1][y]->getTile()->getEType() != tile->getWType())
        return false;
    
    return true;
}

bool Board::placeTile(int x, int y, Tile* tile) {
    if (!this->isPlacementValid(x, y, tile))
        return false;
    
    TileRelation* newTile = new TileRelation(tile, board[x][y+1], board[x+1][y], board[x][y-1], board[x-1][y]);
    
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
