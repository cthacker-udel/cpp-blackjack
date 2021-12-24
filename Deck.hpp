#include "Card.hpp"
#pragma once

class Deck {

    Card *cards;
    int numCards = 0;
    friend class Player;
    public:
        Deck();
        Card *deal();
        void shuffle();
        Deck(Card *);
        void addCard(Card *);
        ~Deck();
        void printDeck();
        int getNumCards();
        void setNumCards();
        void displayHandTotal(string);
        int getTotal();

};
