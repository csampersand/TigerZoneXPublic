#pragma once

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <vector>



class Player {
public:
	Player();
	void incrementScore(int);
	void returnTigers(int);
	void placeTiger();

private:
	int tigerCount; // Number of Meeple
	int score;
	
};


#endif /* Player_hpp */