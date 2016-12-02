//
//  BotInterface.hpp
//  TigerZoneX
//
//  Created by Chris on 12/1/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef BotInterface_hpp
#define BotInterface_hpp

#include "Interface.hpp"
#include <stdio.h>

class BotInterface : Interface {
	BotInterface(GameInteractor& gameInteractor): Interface(gameInteractor) {
        myTurn = true;
    };
	void update();
    bool myTurn;
};

#endif /* BotInterface_hpp */
