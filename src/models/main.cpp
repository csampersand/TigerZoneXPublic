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
#include "Test.hpp"

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

	std::cout << "Test starts here\n";



	std::cout << "Press enter\n";
	int i = 0;
	std::cin >> i;
    
    return 0;
}
