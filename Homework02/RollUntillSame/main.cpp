/* Kyle Tranfaglia
 * 09/23/22
 * Homework#2 - Exercise 3
 * This program will continually roll a die until a any random roll happens a set amount of times
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{

    using namespace std;

    // Variables
    int runLength = 0, runs = 0; // Variables for user inputs and amount of loop iterations
    int roll = 0, consecutive = 1; // Variables to hold random number and consecutive rolls of the same value
	int lastRoll = 0; // Variable to hold last random number generated

    cout << "Enter a run length (>= 1): ";
    cin >> runLength;

    // Invalid input check. Loop runs if the user input is not greater or equal to 1. An error message will appear
    // and the user will be instructed to enter a value again. This continues until a suitable input is read
    while (runLength < 1) {
		cout << "Invalid input, please enter a number (>= 1)\n";
		cout << "Enter a run length (>= 1): ";
		cin >> runLength;
		}

    srand(time(0)); // Sets the seed of the random number generator

	// Loop assigns last roll to variable before changing random number value. For the first loop, its value is 0.
	// Then, it generates a random number and assigns it to variable rolls. Next, an if statement runs to compare 
	// the random number to the last roll. If equal, consecutive variable increments by 1. If it is not equal
	// consecutive variable is reset to 1. The variable runs is iterated after each loop. The loop terminates 
	// when consecutive value is no longer less than the user entered run length
    do {
		lastRoll = roll;
		roll = (rand() % 6 ) + 1;

		if (roll == lastRoll) {
			consecutive++; // Consecutive was initialized as 1 to account that there would be two consecutive numbers if true
			}
		else
			consecutive = 1;
		runs++;
    } while (consecutive < runLength);
	
    cout << "The number of rolls to get " << runLength << " consecutive equal rolls was " << runs << endl;

    return 0;
}
