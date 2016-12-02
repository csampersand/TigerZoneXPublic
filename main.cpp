//
//  main.cpp
//  TigerZoneX
//
//  Created by Chris on 11/4/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include <iostream>
#include "SocketInterface.hpp"
#include "GameInteractor.hpp"
#include "LogInterface.hpp"
#include <stdio.h>
#include <iostream>

int main(int argc, const char * argv[]) {
//    SocketInterface s(argv[1], argv[2], argv[3], argv[4], argv[5]);

    GameInteractor* gameInteractor = new GameInteractor();
    Tile* t1 = gameInteractor->createTileFromTemplate('E');
   // Tile* t2 = gameInteractor->createTileFromTemplate('E');
    LogInterface inter(*gameInteractor);
    
    char c;
    c = t1->getNType();
    
    std::cout << inter.returnTileSequence(t1) << std::endl;
    
    return 0;
}
