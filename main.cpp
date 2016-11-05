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

int main(int argc, const char * argv[]) {
    std::cout << "Tile type M:\n";
    Tile testTile(Tile::sideCity, Tile::sideFarm, Tile::sideFarm, Tile::sideCity, Tile::centerCity, true);
    TileTest::printTile(testTile);

    std::cout << "\nRotate once:\n";
    testTile.rotate();
    TileTest::printTile(testTile);

    std::cout << "\nRotated 2 more times:\n";
    testTile.rotate(2);
    TileTest::printTile(testTile);
    
//    int i = 3;
//    while (i--)
//        std::cout << "Hello, World!\n";
    return 0;
}
