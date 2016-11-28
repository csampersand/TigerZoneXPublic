//
//  TileLandmark.cpp
//  TigerZoneX
//
//  Created by Chris on 11/19/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "TileLandmark.hpp"

TileLandmark* TileLandmark::createTileLandmark(LandmarkType type) {
    if (type == landmarkTrail) {
        TileTrail* trail = new TileTrail();
        trail->type = type;
        return trail;
    }
    else if (type == landmarkLake) {
        TileLake* lake = new TileLake();
        lake->type = type;
        return lake;
    }
    else if (type == landmarkDen) {
        TileDen* den = new TileDen();
        den->type = type;
        return den;
    }
    else {
        return NULL;
    }
}

void TileTrail::trailEnd(bool end) {
    trailEnds = end;
}

LandmarkType TileLandmark::getLandmarkType() {
    return this->type;
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
