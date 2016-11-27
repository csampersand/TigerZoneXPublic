#include "Player.hpp"

Player::Player() {
	this->score = 0;
	this->tigerCount = 7;
	this->crocodileCount = 2;
}

void Player::incrementScore(int amount) {
	this->score += amount;
}

int Player::getScore() {
	return this->score;
}