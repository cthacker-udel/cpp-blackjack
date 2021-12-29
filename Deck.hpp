#include "Card.hpp"
#pragma once

class Deck {

    /*

    Deck class

    private attributes:
    Card pointer - cards within deck
    numCards - integer : number of cards left

    public attributes:
        no-arg constructor
        void deal() - returns Card * <-- card that is dealt
        void shuffle() - shuffles deck
        Deck(Card *) <-- intializes deck with empty pointer
        void addCard(Card *) <--- adds card to deck
        ~Deck() - Deck destructor
        void printDeck() <--- prints deck
        int getNumCards() <-- returns number of cards in deck
        void setNumCards() <-- sets number of cards in deck 
        void displayHandTotal <-- displays hand total given string which is play name
        int getTotal <-- gets total rank of hand

    */

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
