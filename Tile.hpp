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
        sideFarm = 'f',
        sideRoad = 'r',
        sideCity = 'c'
    };
    enum CenterType {
        centerCloister = 'm',
        centerCity = 'c',
        centerRoadBlock = 'x',
        centerFarm = 'f'
    };
    Tile(SideType, SideType, SideType, SideType, CenterType, bool hasPennant = false);
    SideType getNType();
    SideType getEType();
    SideType getSType();
    SideType getWType();
    CenterType getCenterType();
    void rotate();
    void rotate(int);
private:
    SideType nType;
    SideType eType;
    SideType sType;
    SideType wType;
    CenterType centerType;
    bool hasPennant;
};

#endif /* Tile_hpp */
