//
//  main.cpp
//  TigerZoneX
//
//  Created by Chris on 11/4/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include <iostream>
#include "GameInteractor.hpp"
#include "TileLandmark.hpp"

int main(int argc, const char * argv[]) {
    GameInteractor gi;
    TileTrail* t = new TileTrail;
    t->setNextTrail(t);
    TileLandmark* l = t;
    TileTrail t2 = static_cast<TileTrail&>(*l);
    return 0;
}
