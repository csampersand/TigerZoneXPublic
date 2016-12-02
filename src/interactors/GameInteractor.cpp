//
//  GameInteractor.cpp
//  TigerZoneX
//
//  Created by Chris on 11/27/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "GameInteractor.hpp"
#include <algorithm>
#include <random>
#include <chrono>
#include <unordered_map>
#include <iostream>

GameInteractor::GameInteractor() {
    this->setupGame();
}

void GameInteractor::setupGame() {
    this->game = new Game();
    this->setupTileDeck();
    this->setupBoard();
    this->setupPlayers();
}

//Sets up a game with specified starting values

void GameInteractor::setupGame(Tile* startTile, int startX, int startY, std::vector<Tile*> deckTiles){
    this->game = new Game();
    this->setupTileDeck(deckTiles);
    this->setupBoard(startTile, startX, startY);
    this->setupPlayers();
}

void GameInteractor::setupTileDeck(std::vector<Tile*> deckTiles){
    game->deck->setTiles(deckTiles);
    
    //Push starting tile to top of deck
    //game->deck->addTile(startTile);
}

void GameInteractor::setupBoard(Tile* startTile, int startX, int startY){
    this->placeTile(startX, startY, startTile);
    this->placeLandmarks(startX, startY, game->board->getTileRelation(startX, startY)->getTile());
}

//#################%%%%%%%%%%$#@------------------

Game& GameInteractor::getGame() {
    return *this->game;
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
    //Trails
    
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
            game->board->setTileLandmark(x,y,C,newTrail);
        }
        if (tile->getEType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,E,newTrail);
            game->board->setTileLandmark(x,y,C,newTrail);
        }
        if (tile->getWType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,W,newTrail);
            game->board->setTileLandmark(x,y,C,newTrail);
        }
        if (tile->getSType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,S,newTrail);
            game->board->setTileLandmark(x,y,C,newTrail);
        }
        static_cast<TileTrail*>(newTrail)->setTrailEnds(trailSides == 1);
    }
    else if (trailSides == 3 || trailSides == 4) {
        if (tile->getNType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,N,GameInteractor::createTileLandmark(landmarkTrail));
            static_cast<TileTrail*>(game->board->getTileLandmark(x,y,N))->setTrailEnds(true);
        }
        if (tile->getWType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,E,GameInteractor::createTileLandmark(landmarkTrail));
            static_cast<TileTrail*>(game->board->getTileLandmark(x,y,E))->setTrailEnds(true);
        }
        if (tile->getEType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,W,GameInteractor::createTileLandmark(landmarkTrail));
            static_cast<TileTrail*>(game->board->getTileLandmark(x,y,W))->setTrailEnds(true);
        }
        if (tile->getSType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,S,GameInteractor::createTileLandmark(landmarkTrail));
            static_cast<TileTrail*>(game->board->getTileLandmark(x,y,S))->setTrailEnds(true);
        }
    }

    //Lakes
    
    // Create lakes with proper zones & crocodiles
    if (tile->getCenterType() == Tile::centerLake) {
        TileLandmark* newLandmark = GameInteractor::createTileLandmark(landmarkLake);
        TileLake* newLake = static_cast<TileLake*>(newLandmark);
        game->board->setTileLandmark(x,y,C,newLake);
        if (tile->getNType() == Tile::sideLake) {
            game->board->setTileLandmark(x,y,N,newLake);
            newLake->setNOpen(true);
        }
        if (tile->getEType() == Tile::sideLake) {
            game->board->setTileLandmark(x,y,E,newLake);
            newLake->setEOpen(true);
        }
        if (tile->getWType() == Tile::sideLake) {
            game->board->setTileLandmark(x,y,W,newLake);
            newLake->setWOpen(true);
        }
        if (tile->getSType() == Tile::sideLake) {
            game->board->setTileLandmark(x,y,S,newLake);
            newLake->setSOpen(true);
        }
        
        static_cast<TileLake&>(*newLake).setHasCrocodile(tile->getPreyType() == Tile::preyCroc);
    }
    else {
        if (tile->getNType() == Tile::sideLake) {
            TileLake* newLake = static_cast<TileLake*>(GameInteractor::createTileLandmark(landmarkLake));
            newLake->setNOpen(true);
            game->board->setTileLandmark(x,y,N,newLake);
        }
        if (tile->getWType() == Tile::sideLake) {
            TileLake* newLake = static_cast<TileLake*>(GameInteractor::createTileLandmark(landmarkLake));
            newLake->setWOpen(true);
            game->board->setTileLandmark(x,y,W,newLake);
        }
        if (tile->getEType() == Tile::sideLake) {
            TileLake* newLake = static_cast<TileLake*>(GameInteractor::createTileLandmark(landmarkLake));
            newLake->setEOpen(true);
            game->board->setTileLandmark(x,y,E,newLake);
        }
        if (tile->getSType() == Tile::sideLake) {
            TileLake* newLake = static_cast<TileLake*>(GameInteractor::createTileLandmark(landmarkLake));
            newLake->setSOpen(true);
            game->board->setTileLandmark(x,y,S,newLake);
        }
    }
    
    //Dens
    
    // Create den with proper zone
    if (tile->getCenterType() == Tile::centerDen) {
        TileDen* newDen = static_cast<TileDen*>(GameInteractor::createTileLandmark(landmarkDen));
        newDen->setX(x);
        newDen->setY(y);
        game->board->setTileLandmark(x, y, C, newDen);
    }
    
    // Append adjacent landmarks
    if (game->board->getTileLandmark(x,y+1,S) != NULL && game->board->getTileLandmark(x,y,N) != NULL) {
        if (game->board->getTileLandmark(x,y+1,S)->getType() == game->board->getTileLandmark(x,y,N)->getType()) {
            append(game->board->getTileLandmark(x,y,N), game->board->getTileLandmark(x,y+1,S), N);
        }
    }
    if (game->board->getTileLandmark(x+1,y,W) != NULL && game->board->getTileLandmark(x,y,E) != NULL) {
        if (game->board->getTileLandmark(x+1,y,W)->getType() == game->board->getTileLandmark(x,y,E)->getType()) {
            append(game->board->getTileLandmark(x,y,E), game->board->getTileLandmark(x+1,y,W), E);
        }
    }
    if (game->board->getTileLandmark(x,y-1,N) != NULL && game->board->getTileLandmark(x,y,S) != NULL) {
        if (game->board->getTileLandmark(x,y-1,N)->getType() == game->board->getTileLandmark(x,y,S)->getType()) {
            append(game->board->getTileLandmark(x,y,S), game->board->getTileLandmark(x,y-1,N), S);
        }
    }
    if (game->board->getTileLandmark(x-1,y,E) != NULL && game->board->getTileLandmark(x,y,W) != NULL) {
        if (game->board->getTileLandmark(x-1,y,E)->getType() == game->board->getTileLandmark(x,y,W)->getType()) {
            append(game->board->getTileLandmark(x,y,W), game->board->getTileLandmark(x-1,y,E), W);
        }
    }
}

bool GameInteractor::placeTile(int x, int y, Tile* tile) {
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
    
    return true;
}

void GameInteractor::setupBoard() {
    game->board->setFirstTile(new TileRelation(drawTile()));
    game->board->setTileRelation(76,76,game->board->getFirstTile());
    this->placeLandmarks(76,76,game->board->getFirstTile()->getTile());
}

bool GameInteractor::isComplete(TileLandmark* landmark) {
    if (landmark->getType() == landmarkTrail) {
        return isComplete(&static_cast<TileTrail&>(*landmark));
    }
    else if (landmark->getType() == landmarkLake) {
        std::unordered_map<TileLandmark*, bool> visited;
        return isComplete(&static_cast<TileLake&>(*landmark), visited);
    }
    else if (landmark->getType() == landmarkDen) {
        return isComplete(&static_cast<TileDen&>(*landmark));
    }
    
    
    // remove this later
    return false;
}

bool GameInteractor::isComplete(TileTrail* trail) {
    TileTrail* start = trail;
    TileTrail* prev = start;
    TileTrail* next = start;
	
    // Go to ends of trail
	while (prev->getPrevTrail() != NULL && prev->getTrailEnds() == false) {
		prev = prev->getPrevTrail();
		if (prev == start) {
			return true;
		}

	}
	while (next->getNextTrail() != NULL && next->getTrailEnds() == false) {
		next = next->getNextTrail();
		if (next == start) {
			return true;
		}

	}
    // Trail is complete if both ends of trail go to actual ends
    if (prev->getTrailEnds() && next->getTrailEnds())
        return true;
    else {
        return false;
    }
}

bool GameInteractor::isComplete(TileLake* lake, std::unordered_map<TileLandmark*, bool>& visited) {
    bool complete = true;
    visited[lake] = true;
    if (lake->getNOpen() == true) {
        if (lake->getNLake() == NULL)
            return false;
        else if (visited[lake->getNLake()] != true) {
            complete = isComplete(lake->getNLake(), visited);
        }
    }
    if (lake->getEOpen() == true) {
        if (lake->getELake() == NULL)
            return false;
        else if (visited[lake->getELake()] != true) {
            complete = isComplete(lake->getELake(), visited);
        }
    }
    if (lake->getSOpen() == true) {
        if (lake->getSLake() == NULL)
            return false;
        else if (visited[lake->getSLake()] != true) {
            complete = isComplete(lake->getSLake(), visited);
        }
    }
    if (lake->getWOpen() == true) {
        if (lake->getWLake() == NULL)
            return false;
        else if (visited[lake->getWLake()] != true) {
            complete = isComplete(lake->getWLake(), visited);
        }
    }
    return complete;
}

bool GameInteractor::isComplete(TileDen* den) {
    if (
        game->board->getTileRelation(den->getX()-1,den->getY()-1) != NULL &&
        game->board->getTileRelation(den->getX(),den->getY()-1) != NULL &&
        game->board->getTileRelation(den->getX()+1,den->getY()-1) != NULL &&
        game->board->getTileRelation(den->getX()-1,den->getY()) != NULL &&
        game->board->getTileRelation(den->getX()+1,den->getY()) != NULL &&
        game->board->getTileRelation(den->getX()-1,den->getY()+1) != NULL &&
        game->board->getTileRelation(den->getX(),den->getY()+1) != NULL &&
        game->board->getTileRelation(den->getX()+1,den->getY()+1) != NULL
        ) {
        return true;
    }
    else {
        return false;
    }
}

TileLandmark* GameInteractor::createTileLandmark(LandmarkType type) {
    if (type == landmarkTrail) {
        TileTrail* trail = new TileTrail();
        trail->setType(type);
        return trail;
    }
    else if (type == landmarkLake) {
        TileLake* lake = new TileLake();
        lake->setType(type);
        return lake;
    }
    else if (type == landmarkDen) {
        TileDen* den = new TileDen();
        den->setType(type);
        return den;
    }
    else {
        return NULL;
    }
}

bool GameInteractor::append(TileLandmark* first, TileLandmark* second, Position direction) {
    if (first->getType() != second->getType())
        return false;
    else if (first->getType() == landmarkTrail) {
        this->appendTrails(static_cast<TileTrail*>(first), static_cast<TileTrail*>(second));
    }
    else if (first->getType() == landmarkLake) {
        this->appendLakes(static_cast<TileLake*>(first), static_cast<TileLake*>(second), direction);
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

void GameInteractor::appendLakes(TileLake* first, TileLake* second, Position direction) {
    if (direction == N) {
        first->setNLake(second);
        second->setSLake(first);
    }
    else if (direction == E) {
        first->setELake(second);
        second->setWLake(first);
    }
    else if (direction == S) {
        first->setSLake(second);
        second->setNLake(first);
    }
    else if (direction == W) {
        first->setWLake(second);
        second->setELake(first);
    }
}

bool GameInteractor::hasOwner(TileLandmark* landmark) {
    bool owner = false;
    if (landmark->getType() == landmarkTrail) {
        owner = hasOwner(static_cast<TileTrail*>(landmark));
    }
    else if (landmark->getType() == landmarkLake) {
        std::unordered_map<TileLake*, bool> visited;
        owner = hasOwner(static_cast<TileLake*>(landmark), visited);
    }
    else if (landmark->getType() == landmarkDen) {
        owner = hasOwner(static_cast<TileDen*>(landmark));
    }
    
    return owner;
}

bool GameInteractor::hasOwner(TileTrail* trail) {
    
    TileTrail* start = trail;
    TileTrail* prev = start;
    TileTrail* next = start;
    
    if (start->getTigerOwner() != NULL)
        return true;
    
    while(prev->getPrevTrail() != NULL && prev->getTrailEnds() == false) {
        prev = prev->getPrevTrail();
        if (prev->getTigerOwner() != NULL)
            return true;
        if (prev == start){
            return false;
        }
    }
    while(next->getNextTrail() != NULL && next->getTrailEnds() == false) {
        next = next->getNextTrail();
        if (next->getTigerOwner() != NULL)
            return true;
        if(next == start){
            return false;
        }
    }
    
    return false;
}

bool GameInteractor::hasOwner(TileLake* lake, std::unordered_map<TileLake*,bool>& visited) {
    bool owner = false;
    visited[lake] = true;
    if (owner != true && lake->getNLake() != NULL && visited[lake->getNLake()] != true) {
        owner = hasOwner(lake->getNLake(), visited);
    }
    if (owner != true && lake->getELake() != NULL && visited[lake->getELake()] != true) {
        owner = hasOwner(lake->getELake(), visited);
    }
    if (owner != true && lake->getSLake() != NULL && visited[lake->getSLake()] != true) {
        owner = hasOwner(lake->getSLake(), visited);
    }
    if (owner != true && lake->getWLake() != NULL && visited[lake->getWLake()] != true) {
        owner = hasOwner(lake->getWLake(), visited);
    }
    return owner;
}

bool GameInteractor::hasOwner(TileDen* den) {
    return den->getTigerOwner() != NULL;
}

Player* GameInteractor::getOwner(TileLandmark* landmark) {
    Player* owner = NULL;
    if (landmark->getType() == landmarkTrail) {
        owner = getOwner(static_cast<TileTrail*>(landmark));
    }
    else if (landmark->getType() == landmarkLake) {
        std::unordered_map<TileLake*, bool> visited;
        owner = getOwner(static_cast<TileLake*>(landmark), visited, owner);
    }
    else if (landmark->getType() == landmarkDen) {
        owner = getOwner(static_cast<TileDen*>(landmark));
    }
    
    return owner;
}

Player* GameInteractor::getOwner(TileTrail* trail) {
    Player* owner = NULL;
    
    TileTrail* start = trail;
    TileTrail* prev = start;
    TileTrail* next = start;
    
    owner = start->getTigerOwner();
    
    while(prev->getPrevTrail() != NULL && prev->getTrailEnds() == false) {
        prev = prev->getPrevTrail();
        if(start == prev){
            return NULL;
        }
        if (prev->getTigerOwner() != NULL) {
            if (owner == NULL || owner == prev->getTigerOwner()) {
                owner = prev->getTigerOwner();
            }
            else {
                owner = NULL;
            }
        }
    }
    while(next->getNextTrail() != NULL && next->getTrailEnds() == false) {
        next = next->getNextTrail();
        if(start == next){
            return NULL;
        }
        if (next->getTigerOwner() != NULL) {
            if (owner == NULL || owner == next->getTigerOwner()) {
                owner = next->getTigerOwner();
            }
            else {
                owner = NULL;
            }
        }
    }
    
    return owner;

}

Player* GameInteractor::getOwner(TileLake* lake, std::unordered_map<TileLake*,bool>& visited, Player* owner) {
    
    Player* foundOwner = lake->getTigerOwner();
    if (foundOwner != NULL) {
        if (owner == NULL || foundOwner == owner) {
            owner = foundOwner;
        }
        else {
            owner = NULL;
        }
    }
    visited[lake] = true;
    
    
    if (lake->getNLake() != NULL && visited[lake->getNLake()] != true) {
        owner = getOwner(lake->getNLake(), visited, owner);
    }
    if (lake->getELake() != NULL && visited[lake->getELake()] != true) {
        owner = getOwner(lake->getELake(), visited, owner);
    }
    if (lake->getSLake() != NULL && visited[lake->getSLake()] != true) {
        owner = getOwner(lake->getSLake(), visited, owner);
    }
    if (lake->getWLake() != NULL && visited[lake->getWLake()] != true) {
        owner = getOwner(lake->getWLake(), visited, owner);
    }
    
    return owner;
}

Player* GameInteractor::getOwner(TileDen* den) {
    return den->getTigerOwner();
}

void GameInteractor::setupPlayers() {
    int n = sizeof(game->players)/sizeof(game->players[0]);
    for (int i = 0; i < n; i++) {
        game->players[i] = new Player();
        game->players[i]->setScore(0);
        game->players[i]->setTigerCount(7);
        game->players[i]->setCrocodileCount(2);
    }
   // std::cout<< "pointer player: " << game->players[0] << " player[0]->getTigerCount " << game->players[0]->getTigerCount() << std::endl;
}

std::unordered_map<TileLandmark*,bool> GameInteractor::getCompleteLandmarks(int x, int y) {
    std::unordered_map<TileLandmark*,bool> completed;
    for (int i = 1; i < 10; i++) {
        TileLandmark* l = game->board->getTileLandmark(x, y, i);
        if (l != NULL && completed.find(l) == completed.end()) {
            bool complete = isComplete(l);
            completed[l] = (complete);
        }
    }
    return completed;
}

//bool GameInteractor::placeCrocodile(TileLandmark*) {
//    //
//}

int GameInteractor::getCrocodileCount(TileLandmark* landmark) {
    int crocodileCount = 0;
    if (landmark->getType() == landmarkTrail) {
        crocodileCount = getCrocodileCount(static_cast<TileTrail*>(landmark));
    }
    else if (landmark->getType() == landmarkLake) {
        std::unordered_map<TileLake*,bool> visited;
        crocodileCount = getCrocodileCount(static_cast<TileLake*>(landmark), visited, crocodileCount);
    }
    else if (landmark->getType() == landmarkDen) {
        crocodileCount = getCrocodileCount(static_cast<TileTrail*>(landmark));
    }
    return crocodileCount;
}

int GameInteractor::getCrocodileCount(TileTrail* trail) {
    int crocodileCount = 0;
    
    TileTrail* start = trail;
    TileTrail* prev = start;
    TileTrail* next = start;
    
    if (start->getHasCrocodile() == true)
        crocodileCount++;
    
    while(prev->getPrevTrail() != NULL) {
        prev = prev->getPrevTrail();
        if(prev == start){
            return crocodileCount;
        }
        if (prev->getHasCrocodile() == true)
            crocodileCount++;
    }
    while(next->getNextTrail() != NULL) {
        next = next->getNextTrail();
        if(next == start){
            return crocodileCount;
        }
        if (next->getHasCrocodile() == true)
            crocodileCount++;
    }
    
    return crocodileCount;
}

int GameInteractor::getCrocodileCount(TileLake* lake, std::unordered_map<TileLake*,bool>& visited, int crocodileCount) {
    if (lake->getHasCrocodile()) {
        crocodileCount++;
    }
    visited[lake] = true;
    
    if (lake->getNLake() != NULL && visited[lake->getNLake()] != true) {
        crocodileCount += getCrocodileCount(lake->getNLake(), visited, crocodileCount);
    }
    if (lake->getELake() != NULL && visited[lake->getELake()] != true) {
		crocodileCount += getCrocodileCount(lake->getELake(), visited, crocodileCount);
    }
    if (lake->getSLake() != NULL && visited[lake->getSLake()] != true) {
		crocodileCount += getCrocodileCount(lake->getSLake(), visited, crocodileCount);
    }
    if (lake->getWLake() != NULL && visited[lake->getWLake()] != true) {
		crocodileCount += getCrocodileCount(lake->getWLake(), visited, crocodileCount);
    }
    return crocodileCount;
}

int GameInteractor::getCrocodileCount(TileDen* den) {
    return 0;
}

void GameInteractor::returnTigers(int x, int y) {
    std::unordered_map<TileLandmark*,bool> completed = getCompleteLandmarks(x, y);
    for (auto i : completed) {
        if (i.second) {
            returnTigers(i.first);
        }
    }
}

void GameInteractor::returnTigers(TileLandmark* landmark) {
    if (landmark->getType() == landmarkTrail) {
        returnTigers(static_cast<TileTrail*>(landmark));
    }
    else if (landmark->getType() == landmarkLake) {
        std::unordered_map<TileLake*,bool> visited;
        returnTigers(static_cast<TileLake*>(landmark), visited);
    }
    else if (landmark->getType() == landmarkDen) {
        returnTigers(static_cast<TileTrail*>(landmark));
    }
}

void GameInteractor::returnTigers(TileTrail* trail) {
    TileTrail* start = trail;
    TileTrail* prev = start;
    TileTrail* next = start;
    
    if (start->getTigerOwner() != NULL)
        start->getTigerOwner()->giveTiger();
    
    while(prev->getPrevTrail() != NULL) {
        prev = prev->getPrevTrail();
        if(prev == start){
            return;
        }
        if (prev->getTigerOwner() != NULL)
            prev->getTigerOwner()->giveTiger();
    }
    while(next->getNextTrail() != NULL) {
        next = next->getNextTrail();
        if(next == start){
            return;
        }
        if (next->getTigerOwner() != NULL)
            next->getTigerOwner()->giveTiger();
    }
}

void GameInteractor::returnTigers(TileLake* lake, std::unordered_map<TileLake*,bool>& visited) {
    if (lake->getTigerOwner() != NULL) {
        lake->getTigerOwner()->giveTiger();
    }
    visited[lake] = true;
    
    if (lake->getNLake() != NULL && visited[lake->getNLake()] != true) {
        returnTigers(lake->getNLake(), visited);
    }
    if (lake->getELake() != NULL && visited[lake->getELake()] != true) {
        returnTigers(lake->getELake(), visited);
    }
    if (lake->getSLake() != NULL && visited[lake->getSLake()] != true) {
        returnTigers(lake->getSLake(), visited);
    }
    if (lake->getWLake() != NULL && visited[lake->getWLake()] != true) {
        returnTigers(lake->getWLake(), visited);
    }
}

// TODO: This removes the tile from the deck before checking if the placement is allowed. Figure out how to handle that.
// Actually, figure out how to handle any invalid move. Exceptions?
bool GameInteractor::playTurn(int x, int y, int rotations, bool tiger, bool croc, int zone) {
    Tile* tile = this->drawTile();
    rotateTile(tile, rotations);
    
    // Make sure tile is attached to other tiles, and the sides match
    if (!isPlacementValid(x, y, tile))
        return false;
    
    placeTile(x, y, tile);

    placeLandmarks(x, y, tile);
    
    // Can't place a tiger and croc at the same time
    if (tiger && croc)
        return false;
    
    // Invalid zone
    if (zone > 9 || zone < 1)
        return false;
    
    TileLandmark* landmark = game->board->getTileLandmark(x, y, zone);
    
    if (tiger) {
        // Landmark didn't exist, can't place tiger
        // TODO: Doesn't account for jungles, consider changing this?
        if (landmark == NULL) {
            return false;
        }
        
        // Landmark already has an owner
        // TODO: Can double-place during a skip. Account for this
        else if (hasOwner(landmark)) {
            return false;
        }
        
        // Place tiger if conditions are satisfied
        else {
            landmark->setTigerOwner(game->players[game->turnIndex]);
        }
    }
    
    if (croc) {
        for (int i=0; i<9; i++) {
            TileLandmark* l = game->board->getTileLandmark(x, y, i+1);
            
            // TODO: Refactor this to only happen once per unique landmark
            // TODO: Make sure the tile is of the right type
            if (!l->getHasCrocodile()) {
                l->setHasCrocodile(true);
            }
        }
    }
    
    // Give tigers back for completed landmarks
    // Tigers stay on landmarks
    returnTigers(x, y);
    
    // TODO: Scoring nigga
    
    
    // Storing last move
    int tigerZone = 0;
    if (tiger)
        tigerZone = zone;
    
    this->lastMove = new Move(game->turnIndex, x, y, tile, rotations, croc, tigerZone);
    
    // Move to next player's turn
    game->turnIndex++;
    if (game->turnIndex > 1) {
        game->turnIndex = 0;
    }
    
    return true;
}

std::vector<Move> GameInteractor::listPossibleMoves() {
	std::vector<Move> validMoves;
	std::queue< std::pair<int, int> > queue;
	bool visited[153][153];

	//Start BFS
	queue.push(std::make_pair(76, 76));
	std::pair<int, int> nextCoord;
	while (queue.size() > 0) {
		//Visit the next coord
		nextCoord = queue.front();
		queue.pop();
		visitCoord(nextCoord, game->deck->getTiles().front(), game->turnIndex, queue, visited, validMoves);
	}

	return validMoves;
}

void GameInteractor::visitCoord(std::pair<int, int> coord, Tile* tile, int PID, std::queue< std::pair<int, int> > queue, bool visited[][153], std::vector<Move> foundMoves) {
	//Mark current coord as visited
	visited[coord.first][coord.second] = true;

	//Possible move location found
	if (game->board->getTileRelation(coord.first, coord.second) == NULL) {
		//Find any possible moves at coord, given tile
		Tile* tempTile = new Tile(tile->getNType(), tile->getEType(), tile->getSType(), tile->getWType(), tile->getCenterType(), tile->getPreyType());
		for (int i = 0; i < 4; ++i) {
			rotateTile(tempTile);
			if (isPlacementValid(coord.first, coord.second, tempTile)) {
				//Valid tile orientation found
				//TODO find valid tiger and croc placements per rotation
				foundMoves.push_back(Move(PID, coord.first, coord.second, tile, i, false, 0));
			}
		}
		delete tempTile;
	}
	//Keep searching
	else {
		int xx[] = { coord.first, coord.first + 1, coord.first, coord.first - 1 };
		int yy[] = { coord.second + 1, coord.second, coord.second - 1, coord.second };
		for (int i = 0; i < 4; ++i) {
			//if coord is out of bounds or has already been visited do not add to queue
			if (xx[i] > 152 || xx[i] < 0 || yy[i] > 152 || yy[i] < 0) continue;
			if (visited[xx[i]][yy[i]]) continue;

			queue.push(std::make_pair(xx[i], yy[i]));
		}
	}
	delete tile;
}

Move GameInteractor::getLastMove() {
    return *this->lastMove;
}
