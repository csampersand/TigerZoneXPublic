#pragma once

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <vector>



class Player {
public:
	Player();
	void incrementScore(int);
	int getScore();

private:
	int tigerCount;
	int crocodileCount;
	int score;
};


#endif /* Player_hpp */
