#include "Blackjack.hpp"
#include <string.h>
#include <cmath>
using namespace std;

Blackjack::Blackjack() {

	string name;
	cout << "Enter the name of your player" << endl;
	cin >> name;
	this->player1 = new Player(name);
	this->deck = new Deck();

};

void Blackjack::startGame() {

	int randShuffleNumber = rand();
	for(int i = 0; i < sqrt(randShuffleNumber)*2; i += 1) {
		this->deck->shuffle();
	}
	int playerTotal = 0;
	int computerTotal = 0;
	cout << "---------  starting game  ---------" << endl;
	//cout << "after initializing totals" << endl;
	Deck *computerHand = new Deck(NULL);

	this->player1->hand->addCard(this->deck->deal());
	this->player1->hand->addCard(this->deck->deal());
	computerHand->addCard(this->deck->deal());

	computerTotal = computerHand->getTotal();
	playerTotal = this->player1->hand->getTotal();

	string decision = "";

	while (true) { // player dealing loop
		this->player1->hand->displayHandTotal(this->player1->name);
		cout << "Hit or Stand? h/H/hit or s/S/stand" << endl;
		do {
			cin >> decision;
		} while (decision != "hit" && decision != "h" && decision != "H" && decision != "s" && decision != "S" && decision != "Stand");

		if (decision.find("h") != string::npos || decision.find("H") != string::npos) {
			// hit
			this->player1->hand->addCard(this->deck->deal());
			playerTotal = this->player1->hand->getTotal();
			if (playerTotal > 21) {
				// player lost
				cout << "Your total is : " << playerTotal << ", which is over 21 so you lost the game" << endl;
				return;
			} else if (playerTotal == 21) {
				cout << "Your total is 21! You won!" << endl;
				return;
			}
		} else {
			// stand
			break;
		}
	}

	while (computerTotal < 17) {

		computerHand->addCard(this->deck->deal());
		computerTotal = computerHand->getTotal();
		if (computerTotal > 21) {
			// computer loses
			cout << "Computer's hand went over 21, computer loses" << endl;
			return;
		}
	}

	cout << "showdown" << endl;
	if (computerTotal > playerTotal) {
		cout << "Computer wins" << endl;
	} else if (playerTotal > computerTotal) {
		cout << "Player wins" << endl;
	} else {
		cout << "Tie" << endl;
	}

}
