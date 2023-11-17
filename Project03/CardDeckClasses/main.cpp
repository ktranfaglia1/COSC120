/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 1
 * This program creates a Card and Deck Class and uses it to print some information about the deck of cards
 */
#include <iostream>

#include "Deck.h"
#include "Card.h"

using namespace std;

int main() {
	Deck deck1, deck2;
	
	deck1.PrintDeck();
	deck1.ShuffleDeck();
	deck1.PrintDeck();
	cout << endl;
	// Loop to print out 10 cards using the deal card function and converting it to a string
	for (int i = 0; i < 10; i++)
		cout << deck1.dealCard().toString() << " - ";
	cout << endl;
	
	deck1.reset();
	// Loop to print out 5 cards using the deal card function and converting it to a string
	for (int i = 0; i < 5; i++)
		cout << deck1.dealCard().toString() << " - ";
	cout << endl;
	// Loop to print out only the cards in the 3rd through 9th index of the same deck using the deal card function and converting it to a string
	for (int i = 3; i < 10; i++)
		cout << deck1.getCard(i).toString() << " - ";
	cout << endl;
	
	deck2 = deck1;
	cout << endl;
	deck1.PrintDeck();
	deck2.PrintDeck();
	
	cout << endl;
	deck1.ShuffleDeck();
	deck1.PrintDeck();
	deck2.PrintDeck();
	
	return 0;
}
