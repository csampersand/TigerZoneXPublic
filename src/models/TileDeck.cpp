//
//  TileDeck.cpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "TileDeck.hpp"

std::vector<Tile*> TileDeck::getTiles(){
    return this->tiles;
};

Tile* TileDeck::drawTile() {
    Tile* tile = this->tiles.back();
    this->tiles.pop_back();
    return tile;
}

int TileDeck::size() {
	return tiles.size();
}

void TileDeck::setTiles(std::vector<Tile*> tiles) {
    this->tiles = tiles;
}

void TileDeck::addTile(Tile* tile) {
    this->tiles.push_back(tile);
}
