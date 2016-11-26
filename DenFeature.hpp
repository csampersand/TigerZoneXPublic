#pragma once
#include "BoardFeature.hpp";
#include "Tile.hpp";

class DenFeature : BoardFeature
{
public:
	DenFeature(Tile*);
	void updateScore();
	
private:
	Tile* denLocation;
};

