/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 2
 * Deck Object Declaration
 */
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include "Card.h"

using namespace std;

class Deck {
private:
	Card deck[52];
	int top = 0;
public:
	Deck();
	void PrintDeck();
	void ShuffleDeck();
	Card dealCard();
	Card getCard(int i);
	void reset();
};

#endif // DECK_H