//
//  BotInterface.cpp
//  TigerZoneX
//
//  Created by Chris on 12/1/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "BotInterface.hpp"
#include <vector>

void BotInterface::update()
{
	GameInteractor g = this->getInteractor();
	std::vector<Move> moves = g.listPossibleMoves(
	//pick a random move
	//play the move
}
