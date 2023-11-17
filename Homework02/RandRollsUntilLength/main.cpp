/* Kyle Tranfaglia
 * 09/23/22
 * Homework#2 - Exercise 2
 * This program will continually roll a die until a given roll happens a set amount of times
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{

    using namespace std;

    // Variables
    int diceRoll = 0, runLength = 0, runs = 0; // Variables for two user inputs and amount of loop iterations
    int roll = 0, consecutive = 0; // Variables to hold random number and consecutive rolls of the same value

    cout << "Enter a dice roll (1 - 6): ";
    cin >> diceRoll;

    // Invalid input check. Loop runs if the user input is not between 1 and 6. An error message will appear
    // and the user will be instructed to enter a value again. This continues until a suitable input is read
    while (diceRoll < 1 || 6 < diceRoll) {
		cout << "Invalid input, please enter a number (1 - 6)\n";
		cout << "Enter a dice roll (1 - 6): ";
		cin >> diceRoll;
		}

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

	// Loop generates a random number and assigns it to variable rolls. Then, an if statement runs to compare
	// the random number to the entered dice value. If equal, consecutive variable increments by 1.
	// If it is not equal, consecutive variable is reset to 0. The variable runs is iterated after each loop.
	// The loop terminates when consecutive value is no longer less than the user entered run length
    do {
		roll = (rand() % 6 + 1);

		if (roll == diceRoll) {
			consecutive++;
			}
		else
			consecutive = 0;
		runs++;
    } while (consecutive < runLength);

    cout << "The number of rolls to get " << runLength << " consecutive " << diceRoll;
    cout << "'s was " << runs << endl;

    return 0;
}