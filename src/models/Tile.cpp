//
//  Tile.cpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "Tile.hpp"

Tile::Tile(SideType north, SideType east, SideType south, SideType west, CenterType center, PreyType prey) {
    this->nType = north;
    this->eType = east;
    this->sType = south;
    this->wType = west;
    this->centerType = center;
    this->preyType = prey;
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
Tile::PreyType Tile::getPreyType() {
    return this->preyType;
}
void Tile::setNType(SideType type) {
    this->nType = type;
}
void Tile::setEType(SideType type) {
    this->eType = type;
}
void Tile::setSType(SideType type) {
    this->sType = type;
}
void Tile::setWType(SideType type) {
    this->wType = type;
}
