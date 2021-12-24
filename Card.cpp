#include "Card.hpp"
#include <string.h>
#include <map>
using namespace std;

Card::Card(char newSuit, int newRank) {
    this->suit = newSuit;
    this->rank = newRank;
    this->next = NULL;
};

int Card::getRank() {
    return this->rank;
};

char Card::getSuit() {
    return this->suit;
};

Card::~Card() {
    delete this;
};

string Card::toString() {

	string result = "";

	map<char, string> suitMap;

	suitMap['H'] = "Hearts";
	suitMap['S'] = "Suits";
	suitMap['D'] = "Diamonds";
	suitMap['C'] = "Clubs";

	map<int, string> rankMap;

	rankMap[1] = "One";
	rankMap[2] = "Two";
	rankMap[3] = "Three";
	rankMap[4] = "Four";
	rankMap[5] = "Five";
	rankMap[6] = "Six";
	rankMap[7] = "Seven";
	rankMap[8] = "Eight";
	rankMap[9] = "Nine";
	rankMap[10] = "Ten";
	rankMap[11] = "Jack";
	rankMap[12] = "Queen";
	rankMap[13] = "King";
	rankMap[14] = "Ace";

	result += rankMap[this->rank] + " of ";
	result += suitMap[this->suit];
	return result;

}
