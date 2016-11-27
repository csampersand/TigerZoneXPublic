//
//  Board.cpp
//  TigerZoneX
//
//  Created by Jacob on 11/5/16.
//

#include "Board.hpp"

Board::Board(Tile* startingTile) {
    this->firstTile = new TileRelation(startingTile);
    board[76][76] = this->firstTile;
}

bool Board::isPlacementValid(int x, int y, Tile* tile) {
	// Either coordinate cant be > 144 or < 1
	// Board configured so that edge will have an extra row and column to check
    if(x > 152 || x < 0 || y < 0 || y > 152) return false;    //Invalid Board coordinate
    if(board[x][y] != NULL) return false;  //Tile already placed in coordinate

    /*
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
    */
    bool adjacentTileFound = false;
    //Check south edge
    if(y - 1 >= 0){
        if(board[x][y-1] != NULL){
            adjacentTileFound = true;
            if(board[x][y-1]->getTile()->getNType() != tile->getSType()) return false;
        }
    }

    //Check north edge
    if(y + 1 <= 142){
        if(board[x][y+1] != NULL){
            adjacentTileFound = true;
            if(board[x][y+1]->getTile()->getSType() != tile->getNType()) return false;
        }
    }

    //Check east edge
    if(x + 1 <= 142){
        if(board[x+1][y] != NULL){
            adjacentTileFound = true;
            if(board[x+1][y]->getTile()->getWType() != tile->getEType()) return false;
        }
    }

    //Check west edge
    if(x - 1 >= 0){
        if(board[x-1][y] != NULL){
            adjacentTileFound = true;
            if(board[x-1][y]->getTile()->getEType() != tile->getWType()) return false;
        }
    }

    return adjacentTileFound;
}

bool Board::placeTile(int x, int y, Tile* tile) {
    if (!this->isPlacementValid(x, y, tile))
        return false;
    
    TileRelation* newTile = new TileRelation(tile, board[x][y+1], board[x+1][y], board[x][y-1], board[x-1][y]);
    board[x][y] = newTile;
    
    // Have all neighbors reference the newTile
    if (newTile->getNTileRelation() != NULL) {
        newTile->getNTileRelation()->setSTileRelation(newTile);
    }
    if (newTile->getETileRelation() != NULL) {
        newTile->getETileRelation()->setWTileRelation(newTile);
    }
    if (newTile->getSTileRelation() != NULL) {
        newTile->getSTileRelation()->setNTileRelation(newTile);
    }
    if (newTile->getWTileRelation() != NULL) {
        newTile->getWTileRelation()->setETileRelation(newTile);
    }
    return true;
}
