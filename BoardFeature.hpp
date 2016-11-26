#pragma once
#include "Player.hpp";
#include <unordered_map>;
class BoardFeature
{
public:
	bool placeTiger(Player*);
	int getScore();
	void isComplete();

protected:
	void returnTigers();

	int currentScore;
	std::unordered_map<Player*, int> tigersOnFeature;
	Player* featureOwner;
};

