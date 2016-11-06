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

void TileDeck::shuffle() {
    auto engine = std::default_random_engine{};
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
