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
            tile = new Tile(Tile::sideFarm,
                            Tile::sideFarm,
                            Tile::sideRoad,
                            Tile::sideFarm,
                            Tile::centerCloister,
                            false);
            break;
        case 'B':
            tile = new Tile(Tile::sideFarm,
                            Tile::sideFarm,
                            Tile::sideFarm,
                            Tile::sideFarm,
                            Tile::centerCloister,
                            false);
            break;
        case 'C':
            tile = new Tile(Tile::sideCity,
                            Tile::sideCity,
                            Tile::sideCity,
                            Tile::sideCity,
                            Tile::centerCity,
                            true);
            break;
        case 'D':
            tile = new Tile(Tile::sideRoad,
                            Tile::sideCity,
                            Tile::sideRoad,
                            Tile::sideFarm,
                            Tile::centerFarm,
                            false);
            break;
        case 'E':
            tile = new Tile(Tile::sideCity,
                            Tile::sideFarm,
                            Tile::sideFarm,
                            Tile::sideFarm,
                            Tile::centerRoadBlock,
                            false);
            break;
        case 'F':
            tile = new Tile(Tile::sideFarm,
                            Tile::sideCity,
                            Tile::sideFarm,
                            Tile::sideCity,
                            Tile::centerCity,
                            true);
            break;
        case 'G':
            tile = new Tile(Tile::sideCity,
                            Tile::sideFarm,
                            Tile::sideCity,
                            Tile::sideFarm,
                            Tile::centerCity,
                            false);
            break;
        case 'H':
            tile = new Tile(Tile::sideFarm,
                            Tile::sideCity,
                            Tile::sideFarm,
                            Tile::sideCity,
                            Tile::centerRoadBlock,
                            false);
            break;
        case 'I':
            tile = new Tile(Tile::sideFarm,
                            Tile::sideCity,
                            Tile::sideCity,
                            Tile::sideFarm,
                            Tile::centerRoadBlock,
                            false);
            break;
        case 'J':
            tile = new Tile(Tile::sideCity,
                            Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::sideFarm,
                            Tile::centerFarm,
                            false);
            break;
        case 'K':
            tile = new Tile(Tile::sideRoad,
                            Tile::sideCity,
                            Tile::sideFarm,
                            Tile::sideRoad,
                            Tile::centerFarm,
                            false);
            break;
        case 'L':
            tile = new Tile(Tile::sideRoad,
                            Tile::sideCity,
                            Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::centerCloister,
                            false);
            break;
        case 'M':
            tile = new Tile(Tile::sideCity,
                            Tile::sideFarm,
                            Tile::sideFarm,
                            Tile::sideCity,
                            Tile::centerCity,
                            true);
            break;
        case 'N':
            tile = new Tile(Tile::sideCity,
                            Tile::sideFarm,
                            Tile::sideFarm,
                            Tile::sideCity,
                            Tile::centerCity,
                            false);
            break;
        case 'O':
            tile = new Tile(Tile::sideCity,
                            Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::sideCity,
                            Tile::centerCity,
                            true);
            break;
        case 'P':
            tile = new Tile(Tile::sideCity,
                            Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::sideCity,
                            Tile::centerCity,
                            false);
            break;
        case 'Q':
            tile = new Tile(Tile::sideCity,
                            Tile::sideCity,
                            Tile::sideFarm,
                            Tile::sideCity,
                            Tile::centerCity,
                            true);
            break;
        case 'R':
            tile = new Tile(Tile::sideCity,
                            Tile::sideCity,
                            Tile::sideFarm,
                            Tile::sideCity,
                            Tile::centerCity,
                            false);
            break;
        case 'S':
            tile = new Tile(Tile::sideCity,
                            Tile::sideCity,
                            Tile::sideRoad,
                            Tile::sideCity,
                            Tile::centerCity,
                            true);
            break;
        case 'T':
            tile = new Tile(Tile::sideCity,
                            Tile::sideCity,
                            Tile::sideRoad,
                            Tile::sideCity,
                            Tile::centerCity,
                            false);
            break;
        case 'U':
            tile = new Tile(Tile::sideRoad,
                            Tile::sideFarm,
                            Tile::sideRoad,
                            Tile::sideFarm,
                            Tile::centerFarm,
                            false);
            break;
        case 'V':
            tile = new Tile(Tile::sideFarm,
                            Tile::sideFarm,
                            Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::centerFarm,
                            false);
            break;
        case 'W':
            tile = new Tile(Tile::sideFarm,
                            Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::centerRoadBlock,
                            false);
            break;
        case 'X':
            tile = new Tile(Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::sideRoad,
                            Tile::centerRoadBlock,
                            false);
            break;
            
        default:
            tile = NULL;
            break;
    }
    
    return tile;
}

std::vector<Tile*> TileDeck::defineTiles() {
    std::vector<Tile*> tiles;
    
    // Type A 2x
    tiles.push_back(createTileFromTemplate('A'));
    tiles.push_back(createTileFromTemplate('A'));
    
    // Type B 4x
    tiles.push_back(createTileFromTemplate('B'));
    tiles.push_back(createTileFromTemplate('B'));
    tiles.push_back(createTileFromTemplate('B'));
    tiles.push_back(createTileFromTemplate('B'));
    
    //Type C 1x
    tiles.push_back(createTileFromTemplate('C'));
    
    //Type D 4x
    tiles.push_back(createTileFromTemplate('D'));
    tiles.push_back(createTileFromTemplate('D'));
    tiles.push_back(createTileFromTemplate('D'));
    tiles.push_back(createTileFromTemplate('D'));

    
    //Type E 5x
    tiles.push_back(createTileFromTemplate('E'));
    tiles.push_back(createTileFromTemplate('E'));
    tiles.push_back(createTileFromTemplate('E'));
    tiles.push_back(createTileFromTemplate('E'));
    tiles.push_back(createTileFromTemplate('E'));

    
    //Type F 2x
    tiles.push_back(createTileFromTemplate('F'));
    tiles.push_back(createTileFromTemplate('F'));

    
    //Type G 1x
    tiles.push_back(createTileFromTemplate('G'));
    
    //Type H 3x
    tiles.push_back(createTileFromTemplate('H'));
    tiles.push_back(createTileFromTemplate('H'));
    tiles.push_back(createTileFromTemplate('H'));

    
    //Type I 2x
    tiles.push_back(createTileFromTemplate('I'));
    tiles.push_back(createTileFromTemplate('I'));

    
    //Type J 3x
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

    
    //Type M 2x
    tiles.push_back(createTileFromTemplate('M'));
    tiles.push_back(createTileFromTemplate('M'));

    
    //Type N 3x
    tiles.push_back(createTileFromTemplate('N'));
    tiles.push_back(createTileFromTemplate('N'));
    tiles.push_back(createTileFromTemplate('N'));

    
    //Type O 2x
    tiles.push_back(createTileFromTemplate('O'));
    tiles.push_back(createTileFromTemplate('O'));

    
    //Type P 3x
    tiles.push_back(createTileFromTemplate('P'));
    tiles.push_back(createTileFromTemplate('P'));
    tiles.push_back(createTileFromTemplate('P'));

    
    //Type Q 1x
    tiles.push_back(createTileFromTemplate('Q'));
    
    //Type R 3x
    tiles.push_back(createTileFromTemplate('R'));
    tiles.push_back(createTileFromTemplate('R'));
    tiles.push_back(createTileFromTemplate('R'));

    
    //Type S 2x
    tiles.push_back(createTileFromTemplate('S'));
    tiles.push_back(createTileFromTemplate('S'));

    
    //Type T 1x
    tiles.push_back(createTileFromTemplate('T'));
    
    //Type U 8x
    tiles.push_back(createTileFromTemplate('U'));
    tiles.push_back(createTileFromTemplate('U'));
    tiles.push_back(createTileFromTemplate('U'));
    tiles.push_back(createTileFromTemplate('U'));
    tiles.push_back(createTileFromTemplate('U'));
    tiles.push_back(createTileFromTemplate('U'));
    tiles.push_back(createTileFromTemplate('U'));
    tiles.push_back(createTileFromTemplate('U'));

    
    //Type V 9x
    tiles.push_back(createTileFromTemplate('V'));
    tiles.push_back(createTileFromTemplate('V'));
    tiles.push_back(createTileFromTemplate('V'));
    tiles.push_back(createTileFromTemplate('V'));
    tiles.push_back(createTileFromTemplate('V'));
    tiles.push_back(createTileFromTemplate('V'));
    tiles.push_back(createTileFromTemplate('V'));
    tiles.push_back(createTileFromTemplate('V'));
    tiles.push_back(createTileFromTemplate('V'));

    
    //Type W 4x
    tiles.push_back(createTileFromTemplate('W'));
    tiles.push_back(createTileFromTemplate('W'));
    tiles.push_back(createTileFromTemplate('W'));
    tiles.push_back(createTileFromTemplate('W'));

    
    //Type X 1
    tiles.push_back(createTileFromTemplate('X'));
    
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
}

Tile* TileDeck::drawTile() {
    Tile* tile = this->deck.back();
    this->deck.pop_back();
    return tile;
}

