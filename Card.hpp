
#include <stdio.h>
#include <iostream>
#include <string.h>

class Card {

    char suit;
    int rank;

    public:
        Card(char, int);
        int getRank();
        char getSuit();
        void toString();
        ~Card();

};