/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 3
 * This program creates a Card, Deck, and PokerHand Class and uses it to assign a hand of five cards to 6 players and print the hands
 */
#include <iostream>

#include "Deck.h"
#include "Card.h"
#include "PokerHand.h"

using namespace std;

int main() {
	// Variables
	PokerHand pokerPlayer[6];
	Deck deck;
	
	deck.ShuffleDeck();
	// Loop to assign 5 cards to each player by assigning one card to a player at a time in a sequence until 5 cards for each player is reached
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 6; k++) {
			pokerPlayer[k].addToHand(deck.dealCard()); // Deals a card from the deck and adds it to a player's hand
		}
	}
	// Loop to ascendingly sort by face value each player's hand
	for (int i = 0; i < 6; i++) {
		pokerPlayer[i].sortHand();
	}
	// Loop to print each players hand by calling the print hand fucntion and specifying the player the hand belongs to
	for (int i = 0; i < 6; i++) {
		cout << "Player " << i + 1 << ":";
		pokerPlayer[i].PrintHand();
	}
	return 0;
}