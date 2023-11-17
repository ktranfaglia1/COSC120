/* Kyle Tranfaglia
 * 12/06/22
 * Homework#12 - Exercise 3
 * This program creates an IntSet Class with some operators to run a set guessing game where the user has 10 tries to guess a number in a random set
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "IntSet.h"

using namespace std;

int main() {
	srand(time(0));
	// Variables
	int guess = 0, tries = 1, count = 0;
	bool status = true;
	IntSet set;
	// Loop to create a set of 100 random numbers between 1 and 1000
	for (int i = 0; i < 100; i++) {
		set.add(rand() % 1000 + 1);
	}
	// Loop to run as long as the user has not won or lost yet
	while (status) {
		cout << "Guess a number (try " << tries << "): ";
		cin >> guess;
		// Input validation loop to make user guess a possible number in the set range
		while (guess < 1 || guess > 1000) {
			cout << "Invalid guess! Numbers in the set are between 1 and 1000" << endl;
			cout << "Guess a number (try " << tries << "): ";
			cin >> guess;
		}
		// Statement to check if the guess is in the set, and if so, states it and sets status to false to terminate outside loop
		if (set.in(guess)) {
			cout << "You guessed a number in the set";
			status = false;
		}
		tries++; // Increments guess number
		// Statement to display an incorrect guess if status is still true and the user has more guesses remianing, otherwise, game over message is displayed
		if (status && tries <= 10) {
			cout << "You did not guess a number in the set" << endl;
			count = 0;
			// Loop to iterate 20 times and check how many numbers in the set are within - 10 or + 10 of the guess
			for (int i = -10; i <= 10; i++) {
				if (set.in(guess + i)) {
					count++;
				}
			}
			cout << "There are " << count << " numbers in the set within 10 of your guess" << endl;
		}
		else if (status && tries > 10) {
			cout << "Game Over: You did not guess a number in the set";
			status = false;
		}
	}
	return 0;
}