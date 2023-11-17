/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 2
 * Deck Object Implimentation
 */
#include "Deck.h"
#include "Card.h"
// Constructor
Deck::Deck() {
	srand(time(0));
	for (int i = 0, k = 1, j = 1; i < 52; i++) {
		if (i % 13 == 0 && i != 0) {
			j++;
			k = 1;
		}
		deck[i] = Card(k++,j);
		
	}
}
// Function to print the deck as card values converted to a string
void Deck::PrintDeck() {
	// Loop to print every card in the deck separated by a space
	for (int i = 0; i < 52; i++) {
		cout << getCard(i).toString() << " ";
	}
	cout << endl << endl;
}
// Function to shuffle the deck by using an algorithm function to shuffle the all elements of the deck with a random number generator
void Deck::ShuffleDeck() {
	random_shuffle(begin(deck), end(deck));
}
// Function to deal a card by returning the card at the top of the deck
Card Deck::dealCard() {
	return deck[top++];
}
// Function to get a card and return it by getting the element at the index specified by teh parameter
Card Deck::getCard(int i) {
	return deck[i];
}
// Function to reset the top, meaning all cards are back in the deck
void Deck::reset() {
	top = 0;
}