/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 3
 * PokerHand Object Implimentation
 */
#include "PokerHand.h"
// Constructor
PokerHand::PokerHand() {
}
// Function to clear a player's hand by defaulting cards in hand and the cards in the hand
void PokerHand::clearHand() {
	cardsInHand = 0;
	// loop to set each card in the hand array to the defualt card value that represents no card
	for (int i = 0; i < 5; i++) {
		hand[i] = Card();
	}
}
// Function to add a card to a players hand by assigning the dealth card to the player hand array and incrementing cards in hand
void PokerHand::addToHand(Card card) {
	hand[cardsInHand++] = card;
}
// Function to print the players hand with a space between each card
void  PokerHand::PrintHand() {
	// Loop to print each card in the players hand separated by a space
	for (int i = 0; i < cardsInHand; i++) {
		cout << " " << hand[i].toString();
	}
	cout << endl;
}
// Function to print the players hand spaced with a width specified by the user sent as a parameter
void PokerHand::PrintHand(int width) {
	// Loop to print each card in the players hand separated by a distance specified by the width parameter
	for (int i = 0; i < cardsInHand; i++) {
		cout << setw(width) << hand[i].toString();
	}
	cout << endl;
}
// Function to sort a player's hand of cards using a insertion sort and comparing card face values
void PokerHand::sortHand() {
	// For loop to sort the array by going through each element and while the value at one index ahead of another index is greater, that the
	// element is moved to the next larger index and this continues until the the element is no longer larger than the next index
	for (int i = 1; i < cardsInHand; i++) {
		Card temp = hand[i];
		int loc = i - 1;
		while (loc >= 0 && hand[loc].greater(temp)) {
			hand[loc + 1] = hand[loc];
			loc--;
		}
		hand[loc + 1] = temp;
	}
}
