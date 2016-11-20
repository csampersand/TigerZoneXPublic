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
        sideJungle = 'f',
        sideTrail = 'r',
        sideLake = 'c'
    };
    enum CenterType {
        centerDen = 'm',
        centerLake = 'c',
        centerTrailBlock = 'x',
        centerJungle = 'f'
    };
    enum PreyType {
        preyBoar = 'b',
        preyBuffalo = 'u',
        preyDeer = 'd',
        null = NULL
    };
    Tile(SideType, SideType, SideType, SideType, CenterType, PreyType prey = null);
    SideType getNType();
    SideType getEType();
    SideType getSType();
    SideType getWType();
    CenterType getCenterType();
    PreyType getPreyType();
    void rotate();
    void rotate(int);
private:
    SideType nType;
    SideType eType;
    SideType sType;
    SideType wType;
    CenterType centerType;
    PreyType preyType;
    bool hasPennant;
};

#endif /* Tile_hpp */
