//
//  TileLandmark.hpp
//  TigerZoneX
//
//  Created by Chris on 11/19/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef TileLandmark_hpp
#define TileLandmark_hpp

#include <stdio.h>
#include "Player.hpp"

class TileLandmark {
private:
    Player* tigerOwnedBy;
    std::vector<TileLandmark*>* tileLandmarks;
};

class TileTrail : public TileLandmark {
private:
    TileTrail* nextTrail;
    TileTrail* prevTrail;
};

class TileLake : public TileLandmark {
private:
    TileLake* nLake;
    TileLake* eLake;
    TileLake* sLake;
    TileLake* wLake;
};

class TileDen : public TileLandmark {
    bool completed;
};

#endif /* TileLandmark_hpp */
