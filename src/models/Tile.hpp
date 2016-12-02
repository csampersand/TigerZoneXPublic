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
        sideJungle = 'J',
        sideTrail = 'T',
        sideLake = 'L'
    };
    enum CenterType {
        centerDen = 'X',
        centerLake = 'L',
        centerTrailBlock = 't',
        centerJungle = 'J'
    };
    enum PreyType {
        preyBoar = 'P',
        preyBuffalo = 'B',
        preyDeer = 'D',
        preyCroc = 'C',
        null = NULL
    };
    Tile(SideType, SideType, SideType, SideType, CenterType, PreyType prey = null);
    SideType getNType();
    SideType getEType();
    SideType getSType();
    SideType getWType();
    CenterType getCenterType();
    PreyType getPreyType();
    void setNType(SideType);
    void setEType(SideType);
    void setSType(SideType);
    void setWType(SideType);
private:
    SideType nType;
    SideType eType;
    SideType sType;
    SideType wType;
    CenterType centerType;
    PreyType preyType;
};

#endif /* Tile_hpp */
