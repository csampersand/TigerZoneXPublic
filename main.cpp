//
//  main.cpp
//  TigerZoneX
//
//  Created by Chris on 11/4/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include <iostream>
#include "Tile.hpp"
#include "TileTest.hpp"
#include "TileDeck.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Drawing some tiles from the deck:\n";
    TileDeck deck;
    TileTest::printTile(*deck.drawTile());
    TileTest::printTile(*deck.drawTile());
    TileTest::printTile(*deck.drawTile());
    TileTest::printTile(*deck.drawTile());
    TileTest::printTile(*deck.drawTile());
    TileTest::printTile(*deck.drawTile());
    TileTest::printTile(*deck.drawTile());
    TileTest::printTile(*deck.drawTile());
    
    return 0;
}
