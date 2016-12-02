//
//  Interface.hpp
//  TigerZoneX
//
//  Created by Chris on 12/1/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef Interface_hpp
#define Interface_hpp

#include <stdio.h>
#include "Game.hpp"
#include "GameInteractor.hpp"

class Interface {
private:
    Game model;
    GameInteractor interactor;
protected:
    Game& getGame();
    GameInteractor& getInteractor();
public:
    Interface(GameInteractor&);
    virtual void update() = 0;
};

#endif /* Interface_hpp */
