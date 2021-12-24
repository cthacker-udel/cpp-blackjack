#include "Deck.hpp"
#include <string.h>
#pragma once
using namespace std;

class Player {

    Deck *hand;
    string name;

    public:
        Player(Deck *, string);
        Deck *getHand();
        int getHandRank();
        ~Player();
};
