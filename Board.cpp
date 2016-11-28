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

void Board::placeLandmarks(int x, int y, Tile* tile) {
    // Trails
    
    // Count the number of trail sides
    int trailSides = 0;
    if (tile->getNType() == Tile::sideTrail)
        trailSides++;
    if (tile->getEType() == Tile::sideTrail)
        trailSides++;
    if (tile->getSType() == Tile::sideTrail)
        trailSides++;
    if (tile->getWType() == Tile::sideTrail)
        trailSides++;
    
    // Create trails with proper zones
    if (trailSides > 0 && trailSides <= 2) {
        TileLandmark* newTrail = TileLandmark::createTileLandmark(landmarkTrail);
        if (tile->getNType() == Tile::sideTrail) {
            landmarks[x][y][N] = newTrail;
        }
        else if (tile->getWType() == Tile::sideTrail) {
            landmarks[x][y][E] = newTrail;
        }
        else if (tile->getEType() == Tile::sideTrail) {
            landmarks[x][y][W] = newTrail;
        }
        else if (tile->getSType() == Tile::sideTrail) {
            landmarks[x][y][S] = newTrail;
        }
        static_cast<TileTrail&>(*newTrail).trailEnd(trailSides == 1);
    }
    else if (trailSides == 3 || trailSides == 4) {
        if (tile->getNType() == Tile::sideTrail) {
            landmarks[x][y][N] = TileLandmark::createTileLandmark(landmarkTrail);
            static_cast<TileTrail&>(*landmarks[x][y][N]).trailEnd(true);
        }
        if (tile->getWType() == Tile::sideTrail) {
            landmarks[x][y][E] = TileLandmark::createTileLandmark(landmarkTrail);
            static_cast<TileTrail&>(*landmarks[x][y][E]).trailEnd(true);
        }
        if (tile->getEType() == Tile::sideTrail) {
            landmarks[x][y][W] = TileLandmark::createTileLandmark(landmarkTrail);
            static_cast<TileTrail&>(*landmarks[x][y][W]).trailEnd(true);
        }
        if (tile->getSType() == Tile::sideTrail) {
            landmarks[x][y][S] = TileLandmark::createTileLandmark(landmarkTrail);
            static_cast<TileTrail&>(*landmarks[x][y][S]).trailEnd(true);
        }
    }
    
    // Append adjacent landmarks
    if (landmarks[x][y+1] != NULL) {
        if (landmarks[x][y+1][S]->type == landmarks[x][y][N]->type) {
            landmarks[x][y+1][S]->append(landmarks[x][y][N]);
        }
    }
    if (landmarks[x+1][y] != NULL) {
        if (landmarks[x+1][y][W]->type == landmarks[x][y][E]->type) {
            landmarks[x+1][y][W]->append(landmarks[x][y][E]);
        }
    }
    if (landmarks[x][y-1] != NULL) {
        if (landmarks[x][y-1][N]->type == landmarks[x][y][S]->type) {
            landmarks[x][y-1][N]->append(landmarks[x][y][S]);
        }
    }
    if (landmarks[x-1][y] != NULL) {
        if (landmarks[x-1][y][E]->type == landmarks[x][y][W]->type) {
            landmarks[x-1][y][E]->append(landmarks[x][y][W]);
        }
    }
    
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
