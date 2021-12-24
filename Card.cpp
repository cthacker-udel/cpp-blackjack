#include "Card.hpp";

Card::Card(char newSuit, int newRank) {
    this->suit = newSuit;
    this->rank = newRank;
};

Card::getRank() {
    return this->rank;
};

Card::getSuit() {
    return this->suit;
};

Card::~Card() {
    delete this;
};