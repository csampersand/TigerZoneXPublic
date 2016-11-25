#include "Player.hpp"

Player::Player() {
	this->score = 0;
	//8 meeples
	this->followerCount = 8;
}

Player::incrementScore(int amount) {
	this->score += amount;
}
