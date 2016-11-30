#include "Player.hpp"

void Player::incrementScore(int amount) {
	this->score += amount;
}

int Player::getScore() {
    return this->score;
}

int Player::getTigerCount() {
    return this->tigerCount;
}

void Player::giveTiger() {
    this->tigerCount++;
}

int Player::getCrocodileCount() {
	return this->crocodileCount;
}

void Player::setScore(int score) {
    this->score = score;
}

void Player::setTigerCount(int tigerCount) {
    this->tigerCount = tigerCount;
}

void Player::setCrocodileCount(int crocodileCount) {
    this->crocodileCount = crocodileCount;
}
