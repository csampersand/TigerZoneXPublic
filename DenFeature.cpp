#include "DenFeature.hpp"

using namespace std;

DenFeature::DenFeature()
{
}

DenFeature::DenFeature(int x_board_coord, int y_board_coord)
{
	x_coord = x_board_coord;
	y_coord = y_board_coord;
}

bool DenFeature::placeCroc(Player* player) {
	return false;
}