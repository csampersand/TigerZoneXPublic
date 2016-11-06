//
//  TileDeck.cpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include <algorithm>
#include <random>
#include "TileDeck.hpp"

std::vector<Tile*> TileDeck::defineTiles() {
    std::vector<Tile*> tiles;
    
    // Type A 2x
    tiles.push_back(new Tile(Tile::sideFarm,
                             Tile::sideFarm,
                             Tile::sideRoad,
                             Tile::sideFarm,
                             Tile::centerCloister,
                             false));
    tiles.push_back(new Tile(Tile::sideFarm,
                             Tile::sideFarm,
                             Tile::sideRoad,
                             Tile::sideFarm,
                             Tile::centerCloister,
                             false));
    
    return tiles;
}

TileDeck::TileDeck() {
    this->deck = TileDeck::defineTiles();
}

void TileDeck::shuffle() {
    
}
