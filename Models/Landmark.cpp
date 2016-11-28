//
//  Landmark.cpp
//  TigerZoneX
//
//  Created by Chris on 11/26/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "Landmark.hpp"

bool Trail::isComplete() {
    TileTrail* start = &static_cast<TileTrail&>(*tiles.front());
    TileTrail* prev = start;
    TileTrail* next = start;
    
    // Go to ends of trail
    while(prev->prevTrail != NULL && prev->trailEnds == false)
        prev = prev->prevTrail;
    while(next->nextTrail != NULL && next->trailEnds == false)
        next = next->nextTrail;
    
    // Trail is complete if both ends of trail go to actual ends
    if (prev->trailEnds && next->trailEnds)
        return true;
    else
        return false;
}
