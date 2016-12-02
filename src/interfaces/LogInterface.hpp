//
//  LogInterface.hpp
//  TigerZoneX
//
//  Created by Connor Elkin on 12/2/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef LogInterface_hpp
#define LogInterface_hpp

#include <stdio.h>
#include "Interface.hpp"
#include "Move.hpp"

class LogInterface : public Interface {
    public:
        void update();
        int printBoard();
        std::string returnTileSequence(Tile*);
        void printMove(Move*);
        LogInterface(GameInteractor& gameInteractor): Interface(gameInteractor) {};
    
    private:
        //logfile
    
};

#endif /* LogInterface_hpp */
