#include <card.hpp>

class Player {

    card *hand;
    string name;

    public:
        Player(card *, string);
        card *getHand();
        int getHandRank();
        ~Player();
};