#include "Deck.hpp";
#include "Card.hpp";

Deck::Deck() {

    char *suits = {'D', 'S', 'H', 'C'};
    this->cards = new Card[52];
    // 0-10 11, 12, 13, 14
    int index = 0;
    for (int i = 0; i < 15; i++) {
        for(int j = 0; j < 4; j++) {
            this->cards[index] = new Card(suits[j], i);
        }
    }

}