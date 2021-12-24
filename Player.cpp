#include "Player.hpp"
#include <string.h>
using namespace std;

Player::Player(string newName) {
	this->hand = new Deck(NULL);
	this->name = newName;
};

Deck *Player::getHand() {
	return this->hand;
};


Player::~Player() {
	this->hand = NULL;
	this->name = "";
	delete this;
};
