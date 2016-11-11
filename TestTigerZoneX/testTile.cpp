//
//  testTile.cpp
//  TigerZoneX
//
//  Created by Chris on 11/11/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "catch.hpp"

#include "Tile.hpp"

TEST_CASE("Testing tile class") {
    Tile t(Tile::sideCity, Tile::sideFarm, Tile::sideRoad, Tile::sideRoad, Tile::centerCity, false);
    
    SECTION("rotating the tile") {
        INFO("Rotating 3 times")
        t.rotate(3);
        REQUIRE(t.getNType() == Tile::sideFarm);
        REQUIRE(t.getEType() == Tile::sideRoad);
        REQUIRE(t.getSType() == Tile::sideRoad);
        REQUIRE(t.getWType() == Tile::sideCity);
    }
}
