/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 2
 * Card Object Declaration
 */
#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
private:
	int value;
	int suit;
public:
	Card();
	Card(int v, int s);
	string toStringFace();
	string toStringSuit();
	bool equals(Card card2);
	string toString();
	string toString(bool space);
	bool greater(Card card2);
};

#endif // CARD_H