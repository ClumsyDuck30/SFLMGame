#include "Player.h"

Player::Player(char mark) {
	score = step = 0;
	name = "";
	this->mark = mark;
}

string Player::getName() {
	return this->name;
}

char Player::getMark() {
	return this->mark;
}

unsigned int Player::getScore() {
	return this->score;
}

void Player::setName(string newName) {
	this->name = newName;
}

