#include "Player.hpp"

Player::Player() {
	this->score = 0;
	//8 meeples
	this->tigerCount = 8;
}

Player::incrementScore(int amount) {
	this->score += amount;
}

Player::returnTigers(int amount) {
	this->tigerCount += amount;
}

Player::placeTiger() {
	this->tigerCount -= 1;
}
