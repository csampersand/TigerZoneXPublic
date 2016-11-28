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
#include <vector>
#include "Player.hpp"
#include "Tile.hpp"

// Forward declarations since we can't two-way include
class Landmark;
class Trail;
class Lake;
class Den;

enum Position {
    NW = 1,
    N = 2,
    NE = 3,
    W = 4,
    C = 5,
    E = 6,
    SW = 7,
    S = 8,
    SE = 9
};

enum LandmarkType {
    landmarkTrail = 'T',
    landmarkLake = 'L',
    landmarkDen = 'D'
};

class TileLandmark {
    friend class Landmark;
private:
    Player* tigerOwnedBy;
    int tigerCount;
    bool hasCrocodile;
public:
    // The parent landmark, containing all tile landmarks
    Landmark* landmark;
    static TileLandmark* createTileLandmark(LandmarkType);
    LandmarkType type;
    virtual bool append(TileLandmark*) = 0;
};

class TileTrail : public TileLandmark {
    friend class Trail;
private:
    TileTrail* nextTrail;
    TileTrail* prevTrail;
    bool trailEnds;
    bool hasCrocodile;
public:
    void trailEnd(bool);
    bool append(TileLandmark*);
};

class TileLake : public TileLandmark {
    friend class Lake;
private:
    TileLake* nLake;
    TileLake* eLake;
    TileLake* sLake;
    TileLake* wLake;
    bool lakeEnds;
    bool hasCrocodile;
public:
    bool append(TileLandmark*);
};

class TileDen : public TileLandmark {
    friend class Den;
private:
    std::vector<Tile*> surroundingTiles;
public:
    bool append(TileLandmark*);
};

#endif /* TileLandmark_hpp */
