#include "DenFeature.hpp"

using namespace std;

DenFeature::DenFeature(Tile* denLocation)
{
	this->denLocation = denLocation;
	updateScore();
}

//Check Moore neighborhood of Den and update score accordingly
void DenFeature::updateScore() {
	
}