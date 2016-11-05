//
//  Tile.hpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>

class Tile {
public:
    enum SideType {
        sideFarm,
        sideRoad,
        sideCity
    };
    enum CenterType {
        centerCloister,
        centerCity,
        centerFarm
    };
    Tile(SideType north, SideType east, SideType south, SideType west, CenterType center, bool hasPennant);
    void rotate();
    void rotate(int rotations);
private:
    SideType nType;
    SideType eType;
    SideType sType;
    SideType wType;
    CenterType centerType;
    bool hasPennant;
};

#endif /* Tile_hpp */
