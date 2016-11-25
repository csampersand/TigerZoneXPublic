#pragma once
#include "Player.hpp";
class BoardFeature
{
public:
	virtual void isComplete() = 0;
	int getScore() {
		return currentScore;
	}

protected:
	int currentScore;
	int playerOneTigersOnFeature;
	int playerTwoTigersOnFeature;
	Player* featureOwner;
};

