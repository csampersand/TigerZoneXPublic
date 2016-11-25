#pragma once

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <vector>



class Player {
public:
	Player();
	int incrementScore(int);

private:
	int followerCount; // Number of Meeple
	int score;
	
};


#endif /* Player_hpp */
