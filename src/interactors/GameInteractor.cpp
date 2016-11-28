//
//  GameInteractor.cpp
//  TigerZoneX
//
//  Created by Chris on 11/27/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "GameInteractor.hpp"
#include "Game.hpp"
#include "Tile.hpp"
#include "TileDeck.hpp"
#include <algorithm>
#include <random>
#include <chrono>

void GameInteractor::shuffleDeck(TileDeck* deck) {
	typedef std::chrono::high_resolution_clock myclock;
	myclock::time_point beginning = myclock::now();
	myclock::duration d = myclock::now() - beginning;
	unsigned seed = d.count();
	auto engine = std::default_random_engine{};
	engine.seed(seed);
	std::shuffle(std::begin(deck), std::end(deck), engine);
}

void static GameInteractor::createTileFromTemplate() {

}

void static GameInteractor::defineTiles() {

}

void GameInteractor::rotateTile(Tile* tile) {
    Tile::SideType oldNType = tile->getNType();
    tile->setNType(tile->getWType());
    tile->setWType(tile->getSType());
    tile->setSType(tile->getEType());
    tile->setEType(oldNType);
}

void GameInteractor::rotateTile(Tile* tile, int rotations) {
    while(rotations--)
        rotateTile(tile);
}

bool GameInteractor::isPlacementValid(int x, int y, Tile* tile) {
    // Either coordinate cant be > 144 or < 1
    // Board configured so that edge will have an extra row and column to check
    if(x > 152 || x < 0 || y < 0 || y > 152) return false;    //Invalid Board coordinate
    if(game->board->getTileRelation(x,y) != NULL) return false;  //Tile already placed in coordinate
    
    bool adjacentTileFound = false;
    //Check south edge
    if(y - 1 >= 0){
        if(game->board->getTileRelation(x,y-1) != NULL){
            adjacentTileFound = true;
            if(game->board->getTileRelation(x,y-1)->getTile()->getNType() != tile->getSType()) return false;
        }
    }
    
    //Check north edge
    if(y + 1 <= 142){
        if(game->board->getTileRelation(x,y+1) != NULL){
            adjacentTileFound = true;
            if(game->board->getTileRelation(x,y+1)->getTile()->getSType() != tile->getNType()) return false;
        }
    }
    
    //Check east edge
    if(x + 1 <= 142){
        if(game->board->getTileRelation(x+1,y) != NULL){
            adjacentTileFound = true;
            if(game->board->getTileRelation(x+1,y)->getTile()->getWType() != tile->getEType()) return false;
        }
    }
    
    //Check west edge
    if(x - 1 >= 0){
        if(game->board->getTileRelation(x-1,y) != NULL){
            adjacentTileFound = true;
            if(game->board->getTileRelation(x-1,y)->getTile()->getEType() != tile->getWType()) return false;
        }
    }
    
    return adjacentTileFound;
}

void GameInteractor::placeLandmarks(int x, int y, Tile* tile) {
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
            landmarks(x,y)[N] = newTrail;
        }
        else if (tile->getWType() == Tile::sideTrail) {
            landmarks(x,y)[E] = newTrail;
        }
        else if (tile->getEType() == Tile::sideTrail) {
            landmarks(x,y)[W] = newTrail;
        }
        else if (tile->getSType() == Tile::sideTrail) {
            landmarks(x,y)[S] = newTrail;
        }
        static_cast<TileTrail&>(*newTrail).trailEnd(trailSides == 1);
    }
    else if (trailSides == 3 || trailSides == 4) {
        if (tile->getNType() == Tile::sideTrail) {
            landmarks(x,y)[N] = TileLandmark::createTileLandmark(landmarkTrail);
            static_cast<TileTrail&>(*landmarks(x,y)[N]).trailEnd(true);
        }
        if (tile->getWType() == Tile::sideTrail) {
            landmarks(x,y)[E] = TileLandmark::createTileLandmark(landmarkTrail);
            static_cast<TileTrail&>(*landmarks(x,y)[E]).trailEnd(true);
        }
        if (tile->getEType() == Tile::sideTrail) {
            landmarks(x,y)[W] = TileLandmark::createTileLandmark(landmarkTrail);
            static_cast<TileTrail&>(*landmarks(x,y)[W]).trailEnd(true);
        }
        if (tile->getSType() == Tile::sideTrail) {
            landmarks(x,y)[S] = TileLandmark::createTileLandmark(landmarkTrail);
            static_cast<TileTrail&>(*landmarks(x,y)[S]).trailEnd(true);
        }
    }
    
    // Append adjacent landmarks
    if (landmarks(x,y+1) != NULL) {
        if (landmarks(x,y+1)[S]->type == landmarks(x,y)[N]->type) {
            landmarks(x,y+1)[S]->append(landmarks(x,y)[N]);
        }
    }
    if (landmarks(x+1,y) != NULL) {
        if (landmarks(x+1,y)[W]->type == landmarks(x,y)[E]->type) {
            landmarks(x+1,y)[W]->append(landmarks(x,y)[E]);
        }
    }
    if (landmarks(x,y-1) != NULL) {
        if (landmarks(x,y-1)[N]->type == landmarks(x,y)[S]->type) {
            landmarks(x,y-1)[N]->append(landmarks(x,y)[S]);
        }
    }
    if (landmarks(x-1,y) != NULL) {
        if (landmarks(x-1,y)[E]->type == landmarks(x,y)[W]->type) {
            landmarks(x-1,y)[E]->append(landmarks(x,y)[W]);
        }
    }
    
}
