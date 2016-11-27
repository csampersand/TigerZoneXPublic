#include "Player.hpp"

Player::Player(TileRelation*** gameBoard) {
	this->score = 0;
	this->tigerCount = 7;
	this->crocodileCount = 2;
	this->Board = gameBoard;
}

void Player::incrementScore(int amount) {
	this->score += amount;
}

int Player::getScore() {
	return this->score;
}