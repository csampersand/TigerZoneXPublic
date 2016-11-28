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

GameInteractor::GameInteractor() {
    this->game = new Game();
    this->setupTileDeck();
    this->setupBoard();
    this->setupPlayers();
}

void GameInteractor::shuffleDeck() {
    std::vector<Tile*> tiles = game->deck->getTiles();
	typedef std::chrono::high_resolution_clock myclock;
	myclock::time_point beginning = myclock::now();
	myclock::duration d = myclock::now() - beginning;
	unsigned seed = d.count();
	auto engine = std::default_random_engine{};
	engine.seed(seed);
	std::shuffle(std::begin(tiles), std::end(tiles), engine);
    game->deck->setTiles(tiles);
}

Tile* GameInteractor::createTileFromSequence(std::string str){
    Tile* tile = NULL;
    if(str == "JJJJ-"){
        tile = createTileFromTemplate('A');
    }
    if(str == "JJJJX"){
        tile = createTileFromTemplate('B');
    }
    if(str == "JJTJX"){
        tile = createTileFromTemplate('C');
    }
    if(str == "TTTT-"){
        tile = createTileFromTemplate('D');
    }
    if(str == "TJTJ-"){
        tile = createTileFromTemplate('E');
    }
    if(str == "TJJT-"){
        tile = createTileFromTemplate('F');
    }
    if(str == "TJTT-"){
        tile = createTileFromTemplate('G');
    }
    if(str == "LLLL-"){
        tile = createTileFromTemplate('H');
    }
    if(str == "JLLL-"){
        tile = createTileFromTemplate('I');
    }
    if(str == "LLJJ-"){
        tile = createTileFromTemplate('J');
    }
    if(str == "JLJL-"){
        tile = createTileFromTemplate('K');
    }
    if(str == "LJLJ-"){
        tile = createTileFromTemplate('L');
    }
    if(str == "LJJJ-"){
        tile = createTileFromTemplate('M');
    }
    if(str == "JLLJ-"){
        tile = createTileFromTemplate('N');
    }
    if(str == "TLJT-"){
        tile = createTileFromTemplate('O');
    }
    if(str == "TLJTP"){
        tile = createTileFromTemplate('P');
    }
    if(str == "JLTT-"){
        tile = createTileFromTemplate('Q');
    }
    if(str == "JLTTB"){
        tile = createTileFromTemplate('R');
    }
    if(str == "TLTJ-"){
        tile = createTileFromTemplate('S');
    }
    if(str == "TLTJD"){
        tile = createTileFromTemplate('T');
    }
    if(str == "TLLL-"){
        tile = createTileFromTemplate('U');
    }
    if(str == "TLTT-"){
        tile = createTileFromTemplate('V');
    }
    if(str == "TLTTP"){
        tile = createTileFromTemplate('W');
    }
    if(str == "TLLT-"){
        tile = createTileFromTemplate('X');
    }
    if(str == "TLLTB"){
        tile = createTileFromTemplate('Y');
    }
    if(str == "LJTJ-"){
        tile = createTileFromTemplate('Z');
    }
    if(str == "LJTJD"){
        tile = createTileFromTemplate('#');
    }
    if(str == "TLLLC"){
        tile = createTileFromTemplate('@');
    }
    
    
    
    return tile;
};

Tile* GameInteractor::createTileFromTemplate(char tileTemplate) {
    Tile* tile;
    switch(tileTemplate) {
        case 'A':
            tile = new Tile(Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'B':
            tile = new Tile(Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::centerDen,
                            Tile::null);
            break;
        case 'C':
            tile = new Tile(Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::sideTrail,
                            Tile::sideJungle,
                            Tile::centerDen,
                            Tile::null);
            break;
        case 'D':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideTrail,
                            Tile::sideTrail,
                            Tile::sideTrail,
                            Tile::centerTrailBlock,
                            Tile::null);
            break;
        case 'E':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideJungle,
                            Tile::sideTrail,
                            Tile::sideJungle,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'F':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::sideTrail,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'G':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideJungle,
                            Tile::sideTrail,
                            Tile::sideTrail,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'H':
            tile = new Tile(Tile::sideLake,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::centerLake,
                            Tile::null);
            break;
        case 'I':
            tile = new Tile(Tile::sideJungle,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::centerLake,
                            Tile::null);
            break;
        case 'J':
            tile = new Tile(Tile::sideLake,
                            Tile::sideLake,
                            Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::centerLake,
                            Tile::null);
            break;
        case 'K':
            tile = new Tile(Tile::sideJungle,
                            Tile::sideLake,
                            Tile::sideJungle,
                            Tile::sideLake,
                            Tile::centerLake,
                            Tile::null);
            break;
        case 'L':
            tile = new Tile(Tile::sideLake,
                            Tile::sideJungle,
                            Tile::sideLake,
                            Tile::sideJungle,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'M':
            tile = new Tile(Tile::sideLake,
                            Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::sideJungle,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'N':
            tile = new Tile(Tile::sideJungle,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::sideJungle,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'O':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideJungle,
                            Tile::sideTrail,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'P':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideJungle,
                            Tile::sideTrail,
                            Tile::centerJungle,
                            Tile::preyBoar);
            break;
        case 'Q':
            tile = new Tile(Tile::sideJungle,
                            Tile::sideLake,
                            Tile::sideTrail,
                            Tile::sideTrail,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'R':
            tile = new Tile(Tile::sideJungle,
                            Tile::sideLake,
                            Tile::sideTrail,
                            Tile::sideTrail,
                            Tile::centerJungle,
                            Tile::preyBuffalo);
            break;
        case 'S':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideTrail,
                            Tile::sideJungle,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case 'T':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideTrail,
                            Tile::sideJungle,
                            Tile::centerJungle,
                            Tile::preyDeer);
            break;
        case 'U':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::centerLake,
                            Tile::null);
            break;
        case 'V':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideTrail,
                            Tile::sideTrail,
                            Tile::centerTrailBlock,
                            Tile::null);
            break;
        case 'W':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideTrail,
                            Tile::sideTrail,
                            Tile::centerTrailBlock,
                            Tile::preyBoar);
            break;
        case 'X':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::sideTrail,
                            Tile::centerLake,
                            Tile::null);
            break;
        case 'Y':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::sideTrail,
                            Tile::centerLake,
                            Tile::preyBuffalo);
        case 'Z':
            tile = new Tile(Tile::sideLake,
                            Tile::sideJungle,
                            Tile::sideTrail,
                            Tile::sideJungle,
                            Tile::centerJungle,
                            Tile::null);
            break;
        case '#':
            tile = new Tile(Tile::sideLake,
                            Tile::sideJungle,
                            Tile::sideTrail,
                            Tile::sideJungle,
                            Tile::centerJungle,
                            Tile::preyDeer);
            break;
        case '@':
            tile = new Tile(Tile::sideTrail,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::sideLake,
                            Tile::centerLake,
                            Tile::preyCroc);
            break;
            
        default:
            tile = NULL;
            break;
    }
    
    return tile;
}

std::vector<Tile*> GameInteractor::defineTiles() {
    std::vector<Tile*> tiles;
        
        // Type A 1x
        tiles.push_back(createTileFromTemplate('A'));
        
        // Type B 4x
        tiles.push_back(createTileFromTemplate('B'));
        tiles.push_back(createTileFromTemplate('B'));
        tiles.push_back(createTileFromTemplate('B'));
        tiles.push_back(createTileFromTemplate('B'));
        
        //Type C 2x
        tiles.push_back(createTileFromTemplate('C'));
        tiles.push_back(createTileFromTemplate('C'));
        
        //Type D 1x
        tiles.push_back(createTileFromTemplate('D'));
        
        //Type E 8x
        tiles.push_back(createTileFromTemplate('E'));
        tiles.push_back(createTileFromTemplate('E'));
        tiles.push_back(createTileFromTemplate('E'));
        tiles.push_back(createTileFromTemplate('E'));
        tiles.push_back(createTileFromTemplate('E'));
        tiles.push_back(createTileFromTemplate('E'));
        tiles.push_back(createTileFromTemplate('E'));
        tiles.push_back(createTileFromTemplate('E'));
        
        
        //Type F 9x
        tiles.push_back(createTileFromTemplate('F'));
        tiles.push_back(createTileFromTemplate('F'));
        tiles.push_back(createTileFromTemplate('F'));
        tiles.push_back(createTileFromTemplate('F'));
        tiles.push_back(createTileFromTemplate('F'));
        tiles.push_back(createTileFromTemplate('F'));
        tiles.push_back(createTileFromTemplate('F'));
        tiles.push_back(createTileFromTemplate('F'));
        tiles.push_back(createTileFromTemplate('F'));
        
        //Type G 4x
        tiles.push_back(createTileFromTemplate('G'));
        tiles.push_back(createTileFromTemplate('G'));
        tiles.push_back(createTileFromTemplate('G'));
        tiles.push_back(createTileFromTemplate('G'));
        
        //Type H 1x
        tiles.push_back(createTileFromTemplate('H'));
        
        
        //Type I 4x
        tiles.push_back(createTileFromTemplate('I'));
        tiles.push_back(createTileFromTemplate('I'));
        tiles.push_back(createTileFromTemplate('I'));
        tiles.push_back(createTileFromTemplate('I'));
        
        
        //Type J 5x
        tiles.push_back(createTileFromTemplate('J'));
        tiles.push_back(createTileFromTemplate('J'));
        tiles.push_back(createTileFromTemplate('J'));
        tiles.push_back(createTileFromTemplate('J'));
        tiles.push_back(createTileFromTemplate('J'));
        
        
        //Type K 3x
        tiles.push_back(createTileFromTemplate('K'));
        tiles.push_back(createTileFromTemplate('K'));
        tiles.push_back(createTileFromTemplate('K'));
        
        
        //Type L 3x
        tiles.push_back(createTileFromTemplate('L'));
        tiles.push_back(createTileFromTemplate('L'));
        tiles.push_back(createTileFromTemplate('L'));
        
        
        //Type M 5x
        tiles.push_back(createTileFromTemplate('M'));
        tiles.push_back(createTileFromTemplate('M'));
        tiles.push_back(createTileFromTemplate('M'));
        tiles.push_back(createTileFromTemplate('M'));
        tiles.push_back(createTileFromTemplate('M'));
        
        
        //Type N 2x
        tiles.push_back(createTileFromTemplate('N'));
        tiles.push_back(createTileFromTemplate('N'));
        
        
        //Type O 1x
        tiles.push_back(createTileFromTemplate('O'));
        
        //Type P 2x
        tiles.push_back(createTileFromTemplate('P'));
        tiles.push_back(createTileFromTemplate('P'));
        
        //Type Q 1x
        tiles.push_back(createTileFromTemplate('Q'));
        
        //Type R 2x
        tiles.push_back(createTileFromTemplate('R'));
        tiles.push_back(createTileFromTemplate('R'));
        
        //Type S 1 + 2x
        tiles.push_back(createTileFromTemplate('S'));
        tiles.push_back(createTileFromTemplate('S'));
        
        
        //Type T 2x
        tiles.push_back(createTileFromTemplate('T'));
        tiles.push_back(createTileFromTemplate('T'));
        
        //Type U 3x
        tiles.push_back(createTileFromTemplate('U'));
        tiles.push_back(createTileFromTemplate('U'));
        tiles.push_back(createTileFromTemplate('U'));
        
        
        //Type V 1x
        tiles.push_back(createTileFromTemplate('V'));
        
        
        //Type W 2x
        tiles.push_back(createTileFromTemplate('W'));
        tiles.push_back(createTileFromTemplate('W'));
        
        
        //Type X 3x
        tiles.push_back(createTileFromTemplate('X'));
        tiles.push_back(createTileFromTemplate('X'));
        tiles.push_back(createTileFromTemplate('X'));
        
        //Type Y 2x
        tiles.push_back(createTileFromTemplate('Y'));
        tiles.push_back(createTileFromTemplate('Y'));
        
        //Type Z 1x
        tiles.push_back(createTileFromTemplate('Z'));
        
        //Type # 2x
        tiles.push_back(createTileFromTemplate('#'));
        tiles.push_back(createTileFromTemplate('#'));
        
        //Type @ 2x
        tiles.push_back(createTileFromTemplate('@'));
        tiles.push_back(createTileFromTemplate('@'));
        
        return tiles;
}

Tile* GameInteractor::drawTile() {
    Tile* tile = game->deck->getTiles().back();
    game->deck->removeTile();
    return tile;
}

void GameInteractor::setupTileDeck() {
    game->deck->setTiles(defineTiles());
    this->shuffleDeck();
    
    //Push starting tile to top of deck
    game->deck->addTile(createTileFromTemplate('S'));
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
        TileLandmark* newTrail = GameInteractor::createTileLandmark(landmarkTrail);
        if (tile->getNType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,N,newTrail);
        }
        else if (tile->getWType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,E,newTrail);
        }
        else if (tile->getEType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,W,newTrail);
        }
        else if (tile->getSType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,S,newTrail);
        }
        static_cast<TileTrail&>(*newTrail).setTrailEnds(trailSides == 1);
    }
    else if (trailSides == 3 || trailSides == 4) {
        if (tile->getNType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,N,GameInteractor::createTileLandmark(landmarkTrail));
            static_cast<TileTrail&>(*game->board->getTileLandmark(x,y,N)).setTrailEnds(true);
        }
        if (tile->getWType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,E,GameInteractor::createTileLandmark(landmarkTrail));
            static_cast<TileTrail&>(*game->board->getTileLandmark(x,y,E)).setTrailEnds(true);
        }
        if (tile->getEType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,W,GameInteractor::createTileLandmark(landmarkTrail));
            static_cast<TileTrail&>(*game->board->getTileLandmark(x,y,W)).setTrailEnds(true);
        }
        if (tile->getSType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,S,GameInteractor::createTileLandmark(landmarkTrail));
            static_cast<TileTrail&>(*game->board->getTileLandmark(x,y,S)).setTrailEnds(true);
        }
    }
    
    // Append adjacent landmarks
    if (game->board->getTileLandmark(x,y+1,S) != NULL) {
        if (game->board->getTileLandmark(x,y+1,S)->getLandmarkType() == game->board->getTileLandmark(x,y,N)->getLandmarkType()) {
            append(game->board->getTileLandmark(x,y,N), game->board->getTileLandmark(x,y+1,S));
        }
    }
    if (game->board->getTileLandmark(x+1,y,W) != NULL) {
        if (game->board->getTileLandmark(x+1,y,W)->getLandmarkType() == game->board->getTileLandmark(x,y,E)->getLandmarkType()) {
            append(game->board->getTileLandmark(x,y,E), game->board->getTileLandmark(x+1,y,W));
        }
    }
    if (game->board->getTileLandmark(x,y-1,N) != NULL) {
        if (game->board->getTileLandmark(x,y-1,N)->getLandmarkType() == game->board->getTileLandmark(x,y,S)->getLandmarkType()) {
            append(game->board->getTileLandmark(x,y,S), game->board->getTileLandmark(x,y-1,N));
        }
    }
    if (game->board->getTileLandmark(x-1,y,E) != NULL) {
        if (game->board->getTileLandmark(x-1,y,E)->getLandmarkType() == game->board->getTileLandmark(x,y,W)->getLandmarkType()) {
            append(game->board->getTileLandmark(x,y,W), game->board->getTileLandmark(x-1,y,E));
        }
    }
}

bool GameInteractor::placeTile(int x, int y, Tile* tile) {
    if (!this->isPlacementValid(x, y, tile))
        return false;
    
    TileRelation* newTile = new TileRelation(tile, game->board->getTileRelation(x,y+1), game->board->getTileRelation(x+1,y), game->board->getTileRelation(x,y-1), game->board->getTileRelation(x-1,y));
    game->board->setTileRelation(x,y,newTile);
    
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

void GameInteractor::setupBoard() {
    game->board->setFirstTile(new TileRelation(drawTile()));
    game->board->setTileRelation(76,76,game->board->getFirstTile());
}

bool GameInteractor::isComplete(TileLandmark* landmark) {
    if (landmark->getLandmarkType() == landmarkTrail) {
        TileTrail* start = &static_cast<TileTrail&>(*landmark);
        TileTrail* prev = start;
        TileTrail* next = start;
        
        // Go to ends of trail
        while(prev->getPrevTrail() != NULL && prev->getTrailEnds() == false)
            prev = prev->getPrevTrail();
        while(next->getNextTrail() != NULL && next->getTrailEnds() == false)
            next = next->getNextTrail();
        
        // Trail is complete if both ends of trail go to actual ends
        if (prev->getTrailEnds() && next->getTrailEnds())
            return true;
        else {
            return false;
        }
    }
    
    
    // remove this later
    return false;
}

TileLandmark* GameInteractor::createTileLandmark(LandmarkType type) {
    if (type == landmarkTrail) {
        TileTrail* trail = new TileTrail();
        trail->setLandmarkType(type);
        return trail;
    }
    else if (type == landmarkLake) {
        TileLake* lake = new TileLake();
        lake->setLandmarkType(type);
        return lake;
    }
    else if (type == landmarkDen) {
        TileDen* den = new TileDen();
        den->setLandmarkType(type);
        return den;
    }
    else {
        return NULL;
    }
}

bool GameInteractor::append(TileLandmark* first, TileLandmark* second) {
    if (first->getLandmarkType() != second->getLandmarkType())
        return false;
    else if (first->getLandmarkType() == landmarkTrail) {
        this->appendTrails(&static_cast<TileTrail&>(*first), &static_cast<TileTrail&>(*second));
    }
    
    return true;
}

// TEST: make sure this->prevTrail->nextTrail and this->nextTrail->prevTrail never equals this
void GameInteractor::appendTrails(TileTrail* first, TileTrail* second) {
    if (second->getPrevTrail() == NULL) {
        if (first->getNextTrail() == NULL) {
            first->setNextTrail(second);
            second->setPrevTrail(first);
        }
        // Linked list reversal algorithm
        else {
            TileTrail* currTrail = first;
            TileTrail* nextTrail = NULL;
            TileTrail* prevTrail = NULL;
            while (currTrail != NULL) {
                nextTrail = currTrail->getNextTrail();
                currTrail->setNextTrail(prevTrail);
                prevTrail = currTrail;
                currTrail = nextTrail;
            }
            first->setNextTrail(second);
            second->setPrevTrail(first);
        }
    }
    else if (second->getNextTrail() == NULL) {
        if (first->getPrevTrail() == NULL) {
            first->setPrevTrail(second);
            second->setNextTrail(first);
        }
        // Linked list reversal algorithm
        else {
            TileTrail* currTrail = second;
            // Go to beginning of trail being reversed
            while(currTrail->getPrevTrail() != NULL)
                currTrail = currTrail->getPrevTrail();
            TileTrail* nextTrail = NULL;
            TileTrail* prevTrail = NULL;
            while (currTrail != NULL) {
                nextTrail = currTrail->getNextTrail();
                currTrail->setNextTrail(prevTrail);
                prevTrail = currTrail;
                currTrail = nextTrail;
            }
            first->setPrevTrail(second);
            second->setNextTrail(first);
        }
    }
}

void GameInteractor::setupPlayers() {
    for (Player* player : game->players) {
        player = new Player();
        player->setScore(0);
        player->setTigerCount(7);
        player->setCrocodileCount(2);
    }
}
