//
//  BotInterface.cpp
//  TigerZoneX
//
//  Created by Chris on 12/1/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "BotInterface.hpp"
#include <vector>
#include <chrono>
#include <random>

void BotInterface::update()
{
	GameInteractor g = this->getInteractor();
	std::vector<Move> moves = g.listPossibleMoves();

	typedef std::chrono::high_resolution_clock myclock;
	myclock::time_point beginning = myclock::now();
	myclock::duration d = myclock::now() - beginning;
	unsigned seed = d.count();
	auto engine = std::default_random_engine{};
	engine.seed(seed);
	std::shuffle(std::begin(moves), std::end(moves), engine);

	//pick a random move
	Move move = moves.front();
	//play the move
	if(move.tigerZone == 0)
		g.playTurn(move.x, move.y, move.rotations, false, move.croc, move.tigerZone);
	else
		g.playTurn(move.x, move.y, move.rotations, true, move.croc, move.tigerZone);
}
