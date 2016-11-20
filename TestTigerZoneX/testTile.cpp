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
    Tile t(Tile::sideLake, Tile::sideJungle, Tile::sideTrail, Tile::sideTrail, Tile::centerLake, false);
    
    SECTION("rotating the tile") {
        INFO("Rotating 3 times")
        t.rotate(3);
        REQUIRE(t.getNType() == Tile::sideJungle);
        REQUIRE(t.getEType() == Tile::sideTrail);
        REQUIRE(t.getSType() == Tile::sideTrail);
        REQUIRE(t.getWType() == Tile::sideLake);
    }
}
