#include "BoardFeature.hpp";

//Awards feature score to feature owner and returns all tigers on feature
void BoardFeature::isComplete() {
	if (featureOwner != NULL) {
		featureOwner->incrementScore(currentScore);
	}

	returnTigers();
}

//Places a tiger, belonging to tiger owner, on this feature
//*Placement only occurs if the feature is not already owned by another player
bool BoardFeature::placeTiger(Player* tigerOwner) {
	//Check if feature is already owned
	if (featureOwner != NULL) return false;

	//Insert new Tiger on feature, update feature owner, and decrement feature owners tiger count
	tigerOwner->placeTiger();
	auto pair = tigersOnFeature.emplace(tigerOwner, 1);
	if (!pair.second) pair.first->second += 1;
	featureOwner = tigerOwner;
}

int BoardFeature::getScore() {
	return currentScore;
}

//Returns all tigers on this feature to their respective owners
void BoardFeature::returnTigers() {
	for (auto it = tigersOnFeature.begin(); it != tigersOnFeature.end(); ++it) {
		it->first->returnTigers(it->second);
	}
}