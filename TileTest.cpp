//
//  TileTest.cpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include <stdio.h>
#include "TileTest.hpp"

void TileTest::printTile(Tile tile) {
    printf("  %c  \n%c %c %c\n  %c  \n", tile.getNType(), tile.getWType(), tile.getCenterType(), tile.getEType(), tile.getSType());
}
