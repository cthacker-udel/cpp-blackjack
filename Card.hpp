#include <stdio.h>
#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class Card {

    char suit;
    int rank;
    Card *next;
    friend class Deck;
    friend class Player;

    public:
        Card(char, int);
        int getRank();
        char getSuit();
        string toString();
        ~Card();

};
