#include "Deck.hpp"
#include "Card.hpp"
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

Deck::Deck() {

    srand(time(NULL));
    char suits[] = {'D', 'S', 'H', 'C'};
    // 0-10 11, 12, 13, 14
    for (int i = 1; i < 15; i++) {
        for(int j = 0; j < 4; j++) {
            if (i == 1 && j == 0) {
                this->cards = new Card(suits[j], i);
            } else {
                addCard(new Card(suits[j], i));
            }
            this->numCards += 1;
        }
    }

};

int Deck::getNumCards() {
	return this->numCards;
}

int Deck::getTotal() {
	int total = 0;
	Card *tempHead = this->cards;
	while (tempHead != NULL) {
		if (tempHead->rank >= 10) {
			total += 10;
		} else {
			total += tempHead->rank;
		}
		tempHead = tempHead->next;
	}
	return total;
}

void Deck::displayHandTotal(string playerName) {
	cout << playerName << "'s total: " << this->getTotal() << endl;
}

void Deck::setNumCards() {

	int count = 0;
	Card *tempHead = this->cards;
	while (tempHead != NULL) {
		count++;
		tempHead = tempHead->next;
	}
	this->numCards = count;
	//cout << "SetNumCards cards = " << count << endl;

}

Deck::Deck(Card *cards) {
    this->cards = cards;
    this->setNumCards();
};

Card *Deck::deal() {
	//cout << "dealing" << endl;
    // deal from bottom
    Card *tempHead = this->cards;
    if (tempHead == NULL) {
        return NULL;
    }
    this->numCards -= 1;
    Card *prevCard = tempHead;
    while (tempHead->next != NULL) {
        prevCard = tempHead;
        tempHead = tempHead->next;
    }
    Card *theCard = new Card(tempHead->suit, tempHead->rank);
    tempHead = NULL;
    prevCard->next = NULL;
    return theCard;
};

void Deck::addCard(Card *newCard) {
	cout << "adding = " << newCard->toString() << endl;
    Card *tempHead = this->cards;
    if (this->cards == NULL) {
    	this->cards = newCard;
    } else {
		while (tempHead->next != NULL) {
			tempHead = tempHead->next;
		}
		tempHead->next = newCard;
    }
};

void Deck::shuffle() {

    Card *leftHalf = NULL;
    Card *rightHalf = NULL;
    int totalNumCards = this->numCards;
    int halfPoint = totalNumCards / 2;
    Card *tempHead = this->cards;
    int count = 0;
    while (tempHead != NULL) {
        count++;
        if (count == halfPoint) {
            // split
            rightHalf = tempHead->next;
            tempHead->next = NULL;
            leftHalf = this->cards;
            break;
        }
        tempHead = tempHead->next;
    }
    Deck *leftDeck = new Deck(leftHalf);
    Deck *rightDeck = new Deck(rightHalf);
    Deck *newDeck = new Deck(NULL);
    while(leftDeck->numCards > 0 || rightDeck->numCards > 0) {
        int randNum = (1+round(rand()))+(2*ceil(rand()))+(3*floor(rand()));
        //cout << "card count, left = " << leftDeck->numCards << " right = " << rightDeck->numCards << endl;
        if (leftDeck->numCards > 0 && randNum % 2 == 0) {
              std::cout << "dealing from left" << std::endl;
              newDeck->addCard(leftDeck->deal());
        } else {
            if (rightDeck->numCards > 0) {
                std::cout << "dealing from right" << std::endl;
                newDeck->addCard(rightDeck->deal());
            }
        }
    }
    this->cards = newDeck->cards;
};

Deck::~Deck() {
    this->cards = NULL;
};

void Deck::printDeck() {

	Card *tempHead = this->cards;
	while (tempHead != NULL) {
		cout << tempHead->toString() << endl;
		tempHead = tempHead->next;
	}

}

