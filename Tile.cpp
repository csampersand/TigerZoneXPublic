//
//  Tile.cpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "Tile.hpp"

Tile::Tile(SideType north, SideType east, SideType south, SideType west, CenterType center, bool hasPennant) {
    this->nType = north;
    this->eType = east;
    this->sType = south;
    this->wType = west;
    this->centerType = center;
    this->hasPennant = hasPennant;
}

Tile::SideType Tile::getNType() {
    return this->nType;
}
Tile::SideType Tile::getEType() {
    return this->eType;
}
Tile::SideType Tile::getSType() {
    return this->sType;
}
Tile::SideType Tile::getWType() {
    return this->wType;
}
Tile::CenterType Tile::getCenterType() {
    return this->centerType;
}

void Tile::rotate() {
    SideType oldNType = nType;
    nType = wType;
    wType = sType;
    sType = eType;
    eType = oldNType;
}

void Tile::rotate(int rotations) {
    while(rotations--)
        this->rotate();
}
