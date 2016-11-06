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
    static std::vector<Tile*> defineTiles();
    void shuffle();
private:
    std::vector<Tile*> deck;
};

#endif /* TileDeck_hpp */
