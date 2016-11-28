//
//  TileDeck.hpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef TileDeck_hpp
#define TileDeck_hpp

#include <stdio.h>
#include <vector>
#include "Tile.hpp"

class TileDeck {
public:
    Tile* drawTile();
	int size();
    std::vector<Tile*> getTiles();
    void setTiles(std::vector<Tile*>);
    Tile* createTileFromSequence(std::string);
    void addTile(Tile*);
private:
    static Tile* createTileFromTemplate(char);
    void shuffle();
    std::vector<Tile*> tiles;
};



#endif /* TileDeck_hpp */
