//
//  TileLandmark.cpp
//  TigerZoneX
//
//  Created by Chris on 11/19/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "TileLandmark.hpp"

void TileTrail::trailEnd(bool end) {
    trailEnds = end;
}

LandmarkType TileLandmark::getLandmarkType() {
    return this->type;
}

void TileLandmark::setLandmarkType(LandmarkType type) {
    this->type = type;
}

TileTrail* TileTrail::getNextTrail() {
    return this->nextTrail;
}

TileTrail* TileTrail::getPrevTrail() {
    return this->prevTrail;
}

void TileTrail::setNextTrail(TileTrail* next) {
    this->nextTrail = next;
}

void TileTrail::setPrevTrail(TileTrail* prev) {
    this->prevTrail = prev;
}

bool TileTrail::getTrailEnds() {
    return this->trailEnds;
}

void TileTrail::setTrailEnds(bool ends) {
    this->trailEnds = ends;
}
