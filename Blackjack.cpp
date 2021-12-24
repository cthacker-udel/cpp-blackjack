#include "Blackjack.hpp"
#include <string.h>
using namespace std;

Blackjack::Blackjack() {

	string name;
	cout << "Enter the name of your player" << endl;
	cin >> name;
	this->player1 = new Player(NULL, name);
	this->deck = new Deck();

};

void Blackjack::startGame() {

	cout << "starting game" << endl;
	this->deck->printDeck();
	int randShuffleNumber = rand();
	for(int i = 0; i < randShuffleNumber / 2; i += 2) {
		this->deck->shuffle();
	}

}
