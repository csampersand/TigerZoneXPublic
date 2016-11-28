//
//  Board.cpp
//  TigerZoneX
//
//  Created by Jacob on 11/5/16.
//

#include "Board.hpp"
#include "Landmark.hpp"

Board::Board(Tile* startingTile) {
    this->firstTile = new TileRelation(startingTile);
    board[76][76] = this->firstTile;
}

TileDeck Board::getDeck(){
    return this->deck;
};

TileRelation* Board::getTileRelation(int x, int y){
    return this->board[x][y];
};

TileLandmark* Board::getTileLandmark(int x, int y, int c){
    return this->landmarks[x][y][c];
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
    
    this->placeLandmarks(x, y, tile);
    
    return true;
}
