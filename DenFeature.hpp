#pragma once
#include "BoardFeature.hpp";
#include "Tile.hpp";

class DenFeature : BoardFeature
{
public:
	DenFeature();
	DenFeature(int, int);
	bool placeCroc(Player*);
	
private:
	int x_coord;	//Possibly have the scoring object contain these coord's
	int y_coord;
};