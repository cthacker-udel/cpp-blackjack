#include "Deck.hpp";
#include "Card.hpp";
#include <time.h>
#include <stdlib.h>
#include <cmath>

Deck::Deck() {

    srand(time(NULL));
    char *suits = {'D', 'S', 'H', 'C'};
    this->cards = new Card[52];
    // 0-10 11, 12, 13, 14
    for (int i = 0; i < 15; i++) {
        for(int j = 0; j < 4; j++) {
            if (i == 0 && j == 0) {
                this->cards[index] = new Card(suits[j], i);
            } else {
                addCard(new Card(suits[j], i));
            }
        }
    }

};

Deck::Deck(Card *cards) {
    this->cards = cards;
};

int Deck::getNumberOfCards() {

    int count = 0;
    Card *tempHead = this->cards;
    while (tempHead != NULL) {
        count++;
        tempHead = tempHead->next;
    }
    return count;
};

Card Deck::deal() {

    // deal from bottom
    Card *tempHead = this->cards;
    if (tempHead == NULL) {
        return NULL;
    }
    Card *prevCard = tempHead;
    while (tempHead->next != NULL) {
        prevCard = tempHead;
        tempHead = tempHead->next;
    }
    Card theCard = *tempHead;
    tempHead = NULL;
    return theCard;
};

void Deck::addCard(Card *newCard) {
    Card *tempHead = this->cards;
    while (tempHead->next != NULL) {
        tempHead = tempHead->next;
    }
    tempHead->next = newCard;
};

void Deck::shuffle() {

    Card *leftHalf = NULL;
    Card *rightHalf = NULL;
    int totalNumCards = getNumberOfCards();
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
    }
    Deck *leftDeck = new Deck(leftHalf);
    Deck *rightDeck = new Deck(rightHalf);
    Deck *newDeck = new Deck(NULL);
    while(leftDeck->cards != NULL || rightDeck->cards != NULL) {
        int randNum = (1+round(rand()))+(2*ceil(rand()))+(3*floor(rand()));
        if (randNum % 2 == 0) {
            if (leftDeck->cards != NULL) {
                std::cout << "dealing from left" << std::endl;
                newDeck->addCard(leftDeck->deal());
            }
        } else {
            if (rightDeck->cards != NULL) {
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

