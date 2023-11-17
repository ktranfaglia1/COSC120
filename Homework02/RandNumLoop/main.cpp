/* Kyle Tranfaglia
 * 09/23/22
 * Homework#2 - Exercise 1
 * This program will continually roll 5 six-sided dice at a time and return the number
 * of rolls needed for all the dice to have the same value
 */
 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 
 int main () {
	 
	 using namespace std;
	 
	 // Variables
	 int dice1 = 0, dice2 = 0, dice3 = 0, dice4 = 0, dice5 = 0; // Varibale for each dice roll
	 int runs = 0; // incremented variable to capture number of loop iterations
	 bool decision = false; // loop variable to determine when loop stops
	 
	 srand(time(0)); // Sets the seed of the random number generator
	 
	 // Loop generates 5 random numbers and continues to run until the variable decision equals true
	 // The variable decision is assigned a value by an if statment within the loop
	 do {
		 dice1 = (rand() % 6 + 1);
		 dice2 = (rand() % 6 + 1);
		 dice3 = (rand() % 6 + 1);
		 dice4 = (rand() % 6 + 1);
		 dice5 = (rand() % 6 + 1);
		 
		 // If statement within loop compares values of dice rolls and if they are all equal it 
		 // assigns fasle to the variable decision, otherwise decision contains true and the loop iterates
		 if (dice1 == dice2 && dice2 == dice3 && dice3 == dice4 && dice4 == dice5) 
			 decision = false; 
		 else
			 decision = true;
		 
		 runs++; // Counts the iterations
	 } while (decision == true);
	 cout << "The number of rolls to get all 5 dice equal was " << runs << endl;
	 cout << "Each dice was equal to " << dice1 << endl;
	 
	 return 0;
 }