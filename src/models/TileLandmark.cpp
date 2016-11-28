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

// TEST: make sure this->prevTrail->nextTrail and this->nextTrail->prevTrail never equals this
bool TileTrail::append(TileLandmark* toLandmark) {
    if (toLandmark->type != this->type)
        return false;
    
    TileTrail* toTrail = &static_cast<TileTrail&>(*toLandmark);
    if (toTrail->prevTrail == NULL) {
        if (this->nextTrail == NULL) {
            this->nextTrail = toTrail;
            toTrail->prevTrail = this;
        }
        // Linked list reversal algorithm
        else {
            TileTrail* currTrail = this;
            TileTrail* nextTrail = NULL;
            TileTrail* prevTrail = NULL;
            while (currTrail != NULL) {
                nextTrail = currTrail->nextTrail;
                currTrail->nextTrail = prevTrail;
                prevTrail = currTrail;
                currTrail = nextTrail;
            }
            this->nextTrail = toTrail;
            toTrail->prevTrail = this;
        }
    }
    else if (toTrail->nextTrail == NULL) {
        if (this->prevTrail == NULL) {
            this->prevTrail = toTrail;
            toTrail->nextTrail = this;
        }
        // Linked list reversal algorithm
        else {
            TileTrail* currTrail = toTrail;
            // Go to beginning of trail being reversed
            while(currTrail->prevTrail != NULL)
                currTrail = currTrail->prevTrail;
            TileTrail* nextTrail = NULL;
            TileTrail* prevTrail = NULL;
            while (currTrail != NULL) {
                nextTrail = currTrail->nextTrail;
                currTrail->nextTrail = prevTrail;
                prevTrail = currTrail;
                currTrail = nextTrail;
            }
            this->prevTrail = toTrail;
            toTrail->nextTrail = this;
        }
    }
    
    return true;
}

bool TileLake::append(TileLandmark* toLandmark) {
    return false;
}

bool TileDen::append(TileLandmark* toLandmark) {
    return false;
}
