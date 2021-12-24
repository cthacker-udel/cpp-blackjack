#include "Deck.hpp";
#include "Card.hpp";

Deck::Deck() {

    char *suits = {'D', 'S', 'H', 'C'};
    this->cards = new Card[52];
    // 0-10 11, 12, 13, 14
    int index = 0;
    for (int i = 0; i < 15; i++) {
        for(int j = 0; j < 4; j++) {
            if (index == 0) {
                this->cards[index] = new Card(suits[j], i);
            } else {
                Card *tempHead = this->cards;
                while (tempHead->next != NULL) {
                    tempHead = tempHead->next;
                }
                tempHead->next = new Card(suits[j], i);
            }
        }
    }

}

Deck::getNumberOfCards() {

    int count = 0;
    Card *tempHead = this->cards;
    while (tempHead != NULL) {
        
    }


}