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
protected:
    Player* tigerOwner;
    int tigerCount;
    LandmarkType type;
    bool hasCrocodile;
    bool hasGoat;
    Player* goatOwner;
public:
    TileLandmark();
    bool getHasCrocodile();
    void setHasCrocodile(bool);
    bool getHasGoat();
    void setHasGoat(bool);
    LandmarkType getType();
    void setType(LandmarkType);
    Player* getTigerOwner();
    Player* getGoatOwner();
    void setTigerOwner(Player*);
    void setGoatOwner(Player*);
    
};

class TileTrail : public TileLandmark {
    friend class Trail;
private:
    TileTrail* nextTrail;
    TileTrail* prevTrail;
    bool trailEnds;
    void trailEnd(bool);
public:
    TileTrail();
    TileTrail* getNextTrail();
    TileTrail* getPrevTrail();
    void setNextTrail(TileTrail*);
    void setPrevTrail(TileTrail*);
    bool getTrailEnds();
    void setTrailEnds(bool);
};

class TileLake : public TileLandmark {
    friend class Lake;
private:
    TileLake* nLake;
    TileLake* eLake;
    TileLake* sLake;
    TileLake* wLake;
    bool nOpen;
    bool eOpen;
    bool sOpen;
    bool wOpen;
    bool lakeEnds;
public:
    TileLake();
    TileLake* getNLake();
    TileLake* getELake();
    TileLake* getSLake();
    TileLake* getWLake();
    void setNLake(TileLake*);
    void setELake(TileLake*);
    void setSLake(TileLake*);
    void setWLake(TileLake*);
    bool getNOpen();
    bool getEOpen();
    bool getSOpen();
    bool getWOpen();
    void setNOpen(bool);
    void setEOpen(bool);
    void setSOpen(bool);
    void setWOpen(bool);
};

class TileDen : public TileLandmark {
    friend class Den;
public:
    TileDen();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
private:
    int x;
    int y;
};

#endif /* TileLandmark_hpp */
