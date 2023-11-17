/* Kyle Tranfaglia
 * 10/10/22
 * Lab#5 - Exercise 1
 * This program will use a function to continually roll a die until a any random roll happens a set amount of times
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

// Prototype for dice roll function
bool roll5 ();

int main()
{
	using namespace std;
	
	// Variables
	bool equal = 0;
	int count = 0;
	
	srand(time(0)); // Sets the seed of the random number generator
    
	// Do while loop to continue calling dice roll function until it returns boolean value true (!0). Pretest 
	// loop used as it must run at least once. Once true, loop terminates and count variable holds number of iterations
	do {
		equal = roll5(); // Call to dice roll function
		count++;
	} while (equal == 0);
	
	cout << "The number of rolls to get all 5 dice equal was " << count << endl;

    return 0;
}
// Function to initialize five dice and assign them random values 1-6. Then,the dice are compared. If all equal, 
// function returns boolean value true, otherwise it returns false. No parameters are used, only a bool return
bool roll5 () {
	using namespace std;

    // Variables
    int dice1 = 0, dice2 = 0, dice3 = 0, dice4 = 0, dice5 = 0;
	
	dice1 = (rand() % 6 + 1);
	dice2 = (rand() % 6 + 1);
	dice3 = (rand() % 6 + 1);
	dice4 = (rand() % 6 + 1);
	dice5 = (rand() % 6 + 1);
	
	if (dice1 == dice2 && dice2 == dice3 && dice3 == dice4 && dice4 == dice5)
		return true;
	else 
		return false;
}
