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
    TileDeck();
	TileDeck(char[], int);	//The bottom card of the deck corresponds to the zero-eth element of the char[]
    static std::vector<Tile*> defineTiles();
    Tile* drawTile();
	int size();
    std::vector<Tile*> getDeck();
    Tile* createTileFromSequence(std::string);
private:
    static Tile* createTileFromTemplate(char);
    void shuffle();
    std::vector<Tile*> tiles;
};



#endif /* TileDeck_hpp */
