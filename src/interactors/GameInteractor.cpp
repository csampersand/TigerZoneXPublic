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
        }
        if (tile->getWType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,E,newTrail);
        }
        if (tile->getEType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,W,newTrail);
        }
        if (tile->getSType() == Tile::sideTrail) {
            game->board->setTileLandmark(x,y,S,newTrail);
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
        else if (tile->getEType() == Tile::sideLake) {
            game->board->setTileLandmark(x,y,E,newLake);
            newLake->setEOpen(true);
        }
        else if (tile->getWType() == Tile::sideLake) {
            game->board->setTileLandmark(x,y,W,newLake);
            newLake->setWOpen(true);
        }
        else if (tile->getSType() == Tile::sideLake) {
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
    if (game->board->getTileLandmark(x,y+1,S) != NULL) {
        if (game->board->getTileLandmark(x,y+1,S)->getType() == game->board->getTileLandmark(x,y,N)->getType()) {
            append(game->board->getTileLandmark(x,y,N), game->board->getTileLandmark(x,y+1,S), N);
        }
    }
    if (game->board->getTileLandmark(x+1,y,W) != NULL) {
        if (game->board->getTileLandmark(x+1,y,W)->getType() == game->board->getTileLandmark(x,y,E)->getType()) {
            append(game->board->getTileLandmark(x,y,E), game->board->getTileLandmark(x+1,y,W), E);
        }
    }
    if (game->board->getTileLandmark(x,y-1,N) != NULL) {
        if (game->board->getTileLandmark(x,y-1,N)->getType() == game->board->getTileLandmark(x,y,S)->getType()) {
            append(game->board->getTileLandmark(x,y,S), game->board->getTileLandmark(x,y-1,N), S);
        }
    }
    if (game->board->getTileLandmark(x-1,y,E) != NULL) {
        if (game->board->getTileLandmark(x-1,y,E)->getType() == game->board->getTileLandmark(x,y,W)->getType()) {
            append(game->board->getTileLandmark(x,y,W), game->board->getTileLandmark(x-1,y,E), W);
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

bool GameInteractor::isComplete(TileLake* lake, std::unordered_map<TileLandmark*, bool>& visited) {
    bool complete = true;
    if (lake->getNOpen() == true) {
        if (lake->getNLake() == NULL)
            return false;
        else if (visited[lake->getNLake()] != true) {
            visited.emplace(lake->getNLake(), true);
            complete = isComplete(lake->getNLake(), visited);
        }
    }
    if (lake->getEOpen() == true) {
        if (lake->getELake() == NULL)
            return false;
        else if (visited[lake->getELake()] != true) {
            visited.emplace(lake->getELake(), true);
            complete = isComplete(lake->getELake(), visited);
        }
    }
    if (lake->getSOpen() == true) {
        if (lake->getSLake() == NULL)
            return false;
        else if (visited[lake->getSLake()] != true) {
            visited.emplace(lake->getSLake(), true);
            complete = isComplete(lake->getSLake(), visited);
        }
    }
    if (lake->getWOpen() == true) {
        if (lake->getWLake() == NULL)
            return false;
        else if (visited[lake->getWLake()] != true) {
            visited.emplace(lake->getWLake(), true);
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
        if (prev->getTigerOwner() == NULL)
            return true;
    }
    while(next->getNextTrail() != NULL && next->getTrailEnds() == false) {
        next = next->getNextTrail();
        if (next->getTigerOwner() == NULL)
            return true;
    }
    
    return false;
}

bool GameInteractor::hasOwner(TileLake* lake, std::unordered_map<TileLake*,bool>& visited) {
    bool owner = false;
    if (owner != true && lake->getNLake() != NULL && visited[lake->getNLake()] != true) {
        visited.emplace(lake->getNLake(), true);
        owner = hasOwner(lake->getNLake(), visited);
    }
    if (owner != true && lake->getELake() != NULL && visited[lake->getELake()] != true) {
        visited.emplace(lake->getELake(), true);
        owner = hasOwner(lake->getELake(), visited);
    }
    if (owner != true && lake->getSLake() != NULL && visited[lake->getSLake()] != true) {
        visited.emplace(lake->getSLake(), true);
        owner = hasOwner(lake->getSLake(), visited);
    }
    if (owner != true && lake->getWLake() != NULL && visited[lake->getWLake()] != true) {
        visited.emplace(lake->getWLake(), true);
        owner = hasOwner(lake->getWLake(), visited);
    }
    return owner;
}

bool GameInteractor::hasOwner(TileDen* den) {
    return den->getTigerOwner() != NULL;
}

Player* GameInteractor::getOwner(TileTrail* trail) {
    Player* owner = NULL;
    
    TileTrail* start = trail;
    TileTrail* prev = start;
    TileTrail* next = start;
    
    owner = start->getTigerOwner();
    
    while(prev->getPrevTrail() != NULL && prev->getTrailEnds() == false) {
        prev = prev->getPrevTrail();
        if (prev->getTigerOwner() != NULL) {
            if (owner == NULL || owner == prev->getTigerOwner()) {
                owner = owner = prev->getTigerOwner();
            }
            else {
                owner = NULL;
            }
        }
    }
    while(next->getNextTrail() != NULL && next->getTrailEnds() == false) {
        next = next->getNextTrail();
        if (next->getTigerOwner() != NULL) {
            if (owner == NULL || owner == next->getTigerOwner()) {
                owner = owner = next->getTigerOwner();
            }
            else {
                owner = NULL;
            }
        }
    }
    
    return owner;

}

Player* GameInteractor::getOwner(TileLake* lake, std::unordered_map<TileLake*,bool>& visited, Player* owner) {
    if (lake->getNLake() != NULL && visited[lake->getNLake()] != true) {
        visited.emplace(lake->getNLake(), true);
        Player* foundOwner = getOwner(lake->getNLake(), visited, owner);
        if (owner == NULL || foundOwner == owner) {
            owner = foundOwner;
        }
        else {
            owner = NULL;
        }
    }
    if (lake->getELake() != NULL && visited[lake->getELake()] != true) {
        visited.emplace(lake->getELake(), true);
        Player* foundOwner = getOwner(lake->getELake(), visited, owner);
        if (owner == NULL || foundOwner == owner) {
            owner = foundOwner;
        }
        else {
            owner = NULL;
        }
    }
    if (lake->getSLake() != NULL && visited[lake->getSLake()] != true) {
        visited.emplace(lake->getSLake(), true);
        Player* foundOwner = getOwner(lake->getSLake(), visited, owner);
        if (owner == NULL || foundOwner == owner) {
            owner = foundOwner;
        }
        else {
            owner = NULL;
        }
    }
    if (lake->getWLake() != NULL && visited[lake->getWLake()] != true) {
        visited.emplace(lake->getWLake(), true);
        Player* foundOwner = getOwner(lake->getWLake(), visited, owner);
        if (owner == NULL || foundOwner == owner) {
            owner = foundOwner;
        }
        else {
            owner = NULL;
        }
    }
    return owner;
}

Player* GameInteractor::getOwner(TileDen* den) {
    return den->getTigerOwner();
}

void GameInteractor::setupPlayers() {
    for (Player* player : game->players) {
        player = new Player();
        player->setScore(0);
        player->setTigerCount(7);
        player->setCrocodileCount(2);
    }
}

// TODO: This removes the tile from the deck before checking if the placement is allowed. Figure out how to handle that.
// Actually, figure out how to handle any invalid move. Exceptions?
bool GameInteractor::playTurn(int x, int y, bool tiger, bool croc, int zone) {
    Tile* tile = this->drawTile();
    
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
    
    // Landmark didn't exist, can't place tiger
    // TODO: Doesn't account for jungles, consider changing this?
    if (landmark == NULL) {
        return false;
    }
    
    // Landmark already has an owner
    // TODO: Can double-place during a skip. Account for this
    if (hasOwner(landmark)) {
        return false;
    }
    
    landmark->setTigerOwner(game->players[game->turnIndex]);
    
    // TODO: Scoring nigga
    
    // Move to next player's turn
    game->turnIndex++;
    if (game->turnIndex > 1) {
        game->turnIndex = 0;
    }
    
    return true;
}
