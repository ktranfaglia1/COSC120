/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 2
 * This program creates a Card and Deck Class and asks the user for an amount of trials and determines the count and the probability of derangement
 */
#include <iostream>

#include "Deck.h"
#include "Card.h"

using namespace std;

int main() {
	// Variables
	Deck deck1, deck2;
	Card card1, card2;
	unsigned int count = 0, subCount = 0, trials = 0; 
	
	cout << "How many times would you like to shuffle the deck: ";
	cin >> trials;
	// Input Validation loop to make the user input a value greater than zero
	while (trials <= 0) {
		cout << "Invalid Input! Please enter a value greater than zero" << endl;
		cout << "How many times would you like to shuffle the deck?";
		cin >> trials;
	}
	// For loop to run for the user input number of trials, shuffling the deck each time and determining if there was a derangement by using a count
	for (unsigned int i = 0; i < trials; i++) {
		deck2.ShuffleDeck();
		subCount = 0;
		// Loop to assign deck 1 and deck 2 cards to a variable for comparison, and if they are equal, a count increments
		for (int k = 0; k < 52; k++) {
			card1 = deck1.getCard(k);
			card2 = deck2.getCard(k);
			if (card1.equals(card2)) {
				subCount++;

			}
		}
		// If the subcount never incremented, none of the values are the same so a derangement ocurred, so a count to track them is incremented
		if (subCount == 0) {
			count++;
		}
	}
	cout << "Number of derangements: " << count << endl;
	cout << "Probability of a derangement: " << 1.0*count/trials << endl;
	cout << "One over Probability: " << 1.0*trials/count << endl; // Approaches Euler's number
	
	return 0;
}