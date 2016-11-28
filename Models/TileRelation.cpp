//
//  TileRelation.cpp
//  TigerZoneX
//
//  Created by Chris on 11/5/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "TileRelation.hpp"

Tile* TileRelation::getTile() {
    return this->tile;
}
void TileRelation::setTile(Tile* tile) {
    this->tile = tile;
}
TileRelation* TileRelation::getNTileRelation() {
    return this->nTileRelation;
}
TileRelation* TileRelation::getETileRelation() {
    return this->eTileRelation;
}
TileRelation* TileRelation::getSTileRelation() {
    return this->sTileRelation;
}
TileRelation* TileRelation::getWTileRelation() {
    return this->wTileRelation;
}
void TileRelation::setNTileRelation(TileRelation* tileRelation) {
    this->nTileRelation = tileRelation;
}
void TileRelation::setETileRelation(TileRelation* tileRelation) {
    this->eTileRelation = tileRelation;
}
void TileRelation::setSTileRelation(TileRelation* tileRelation) {
    this->sTileRelation = tileRelation;
}
void TileRelation::setWTileRelation(TileRelation* tileRelation) {
    this->wTileRelation = tileRelation;
}
TileRelation::TileRelation(Tile* tile, TileRelation* nTileRelation, TileRelation* eTileRelation, TileRelation* sTileRelation, TileRelation* wTileRelation) {
    this->setTile(tile);
    this->setNTileRelation(nTileRelation);
    this->setETileRelation(eTileRelation);
    this->setSTileRelation(sTileRelation);
    this->setWTileRelation(wTileRelation);
}
