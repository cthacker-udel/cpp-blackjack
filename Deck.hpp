#include "card.hpp";

class Deck {

    Card *cards;
    public:
        Deck();
        int getNumberOfCards();
        Card deal();
        void shuffle();
        Deck(Card *);
        void addCard(Card *);
        ~Deck();

};