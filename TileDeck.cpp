//
//  TileDeck.cpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include <algorithm>
#include <random>
#include <chrono>
#include "TileDeck.hpp"

Tile* TileDeck::createTileFromTemplate(char tileTemplate) {
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
            
        default:
            tile = NULL;
            break;
    }
    
    return tile;
}

std::vector<Tile*> TileDeck::defineTiles() {
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
    
    return tiles;
}

void TileDeck::shuffle() {
    typedef std::chrono::high_resolution_clock myclock;
    myclock::time_point beginning = myclock::now();
    myclock::duration d = myclock::now() - beginning;
    unsigned seed = d.count();
    auto engine = std::default_random_engine{};
    engine.seed(seed);
    std::shuffle(std::begin(this->deck), std::end(this->deck), engine);
}

TileDeck::TileDeck() {
    this->deck = TileDeck::defineTiles();
    this->shuffle();

    //Push starting tile to top of deck
    this->deck.push_back(createTileFromTemplate('S'));
}

TileDeck::TileDeck(char* tileList, int n) {
	std::vector<Tile*> tiles;
	for (int i = 0; i < n; ++i) {
		tiles.push_back(createTileFromTemplate(tileList[n]));
	}
	this->deck = tiles;
}


Tile* TileDeck::drawTile() {
    Tile* tile = this->deck.back();
    this->deck.pop_back();
    return tile;
}

