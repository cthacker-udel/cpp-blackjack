#include "card.hpp";

class Deck {

    Card *cards;
    public:
        Deck();
        int getNumberOfCards();
        Card deal();
        Card *shuffle();
        ~Deck();

};