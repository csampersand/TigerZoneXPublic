//
//  GameInteractor.hpp
//  TigerZoneX
//
//  Created by Chris on 11/27/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef GameInteractor_hpp
#define GameInteractor_hpp

#include <stdio.h>
#include "Game.hpp"
#include "Tile.hpp"

class GameInteractor {
private:
    Game* game;
public:
    GameInteractor();
    GameInteractor(Game*);
    
    //
    void rotateTile(Tile*);
    void rotateTile(Tile*, int);
    
    bool isPlacementValid(int, int, Tile*);
    bool placeTile(int, int, Tile*);
};

#endif /* GameInteractor_hpp */
