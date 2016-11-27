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
        return trail;
    }
    else if (type == landmarkLake) {
        TileLake* lake = new TileLake();
        return lake;
    }
    else if (type == landmarkDen) {
        TileDen* den = new TileDen();
        return den;
    }
    else {
        return NULL;
    }
}

void TileTrail::trailEnd(bool end) {
    trailEnds = end;
}
