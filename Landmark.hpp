//
//  Landmark.hpp
//  TigerZoneX
//
//  Created by Chris on 11/26/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef Landmark_hpp
#define Landmark_hpp

#include <stdio.h>
#include <vector>
#include "TileLandmark.hpp"

class Landmark {
public:
    virtual bool isComplete() = 0i;
    // tile landmark segments that make up the entire landmark
    std::vector<TileLandmark*> tiles;
};

class Trail : public Landmark {
public:
    bool isComplete();
};

class Lake : public Landmark {
public:
    bool isComplete();
};

class Den : public Landmark {
public:
    bool isComplete();
};

#endif /* Landmark_hpp */
