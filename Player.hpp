#include "Deck.hpp"
#include <string.h>
#pragma once
using namespace std;

class Player {

    Deck *hand;
    string name;
    friend class Blackjack;

    public:
        Player(string);
        Deck *getHand();
        ~Player();
};
