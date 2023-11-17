/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 3
 * PokerHand Object Declaration
 */
#ifndef POKERHAND_H_
#define POKERHAND_H_

#include <iostream>
#include <iomanip>
#include "Card.h"

using namespace std;

class PokerHand {
private:
	Card hand[5];
	int cardsInHand = 0;
public:
	PokerHand();
	void clearHand();
	void addToHand(Card card);
	void PrintHand();
	void PrintHand(int width);
	void sortHand();
};

#endif // PokerHand_H
