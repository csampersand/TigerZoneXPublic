#include "DenFeature.hpp"

using namespace std;

DenFeature::DenFeature()
{
}

void DenFeature::isComplete() {
	currentScore = 9;
	if (featureOwner != NULL) {
		featureOwner->incrementScore(currentScore);
	}
}
