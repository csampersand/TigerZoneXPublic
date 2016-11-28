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

int TileDeck::size() {
	return (int)tiles.size();
}

void TileDeck::setTiles(std::vector<Tile*> tiles) {
    this->tiles = tiles;
}

void TileDeck::addTile(Tile* tile) {
    this->tiles.push_back(tile);
}

void TileDeck::removeTile() {
    this->tiles.pop_back();
}
