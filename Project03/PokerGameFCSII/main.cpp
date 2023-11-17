/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 4
 * This program creates a Card, Deck, and PokerHand Class and uses it to assign a hand of five cards to 6 players and print the hands including hand type
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
	char again = ' ';
	// Do while loop to run at least once, and continues running if user enters to continue
	do {
		// Loop to reset the cards in each players hand by calling a function that sets each card in the hand to the default value
		for (int i = 0; i < 6; i++) {
			pokerPlayer[i].clearHand();
		}
		deck.reset();
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
			pokerPlayer[i].PrintHand(4);
		}
		cout << endl << "Would You Like to Play Again? (y/n): ";
		cin >> again;
		// Input validation loop to make the user eneter a valid y or n answer - case insensitive
		while (again != 'y' && again != 'Y' && again != 'n' && again != 'N') {
			cout << "Invalid Input! Please enter y or n" << endl;
			cout << endl << "Would You Like to Play Again? (y/n): ";
			cin >> again;
		}
		cout << endl;
	} while (again == 'y' || again == 'Y');
	
	return 0;
}
