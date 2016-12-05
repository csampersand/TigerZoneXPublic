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
    std::vector<Move> listPossibleMoves();
    void visitCoord(std::pair<int, int>, Tile*, int, std::queue< std::pair<int, int> >, bool, std::vector<Move>);
    void setTigerZone(Move);
    void setMoves(std::vector<Move>);
    std::vector<Move> getMoves();
private:
    std::vector<Move> moves;
};

#endif /* BotInterface_hpp */
