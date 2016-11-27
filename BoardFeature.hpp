#pragma once
#include "Player.hpp";
#include <unordered_map>;
#include "TileRelation.hpp";
class BoardFeature
{
public:
	bool placeTiger(Player*);
	virtual bool placeCroc(Player*) = 0;
	int getScore();
	void isComplete();

protected:
	void returnTigers();

	int currentScore;
	std::unordered_map<Player*, int> tigersOnFeature;
	Player* featureOwner;
};

