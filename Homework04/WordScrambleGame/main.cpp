/* Kyle Tranfaglia
 * 10/10/22
 * Homework#4 - Exercise 3
 * This program gets an input from player 1 that is a single word, randomly scrambles the letters, prints out
 * the scrambled word for player two, and gives them three tries to guess the word correctly
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Prototypes
string scramble_string(string input);
string trim(string str);
string to_lowercase(string str);

int main () {
	
	string input = "", guess = "", scrambled = "";
	int count = 0;
	
	srand(time(0)); // Sets the seed of the random number generator
	
	cout << "Player 1: Input a single word: ";
	cin >> input;
	cout << endl;
	
	input = trim(input); // Calls trim function 
	input = to_lowercase(input); // Calls lowercase function
	scrambled = scramble_string(input); // Calls scramble function
	
	cout << "Player 2: The scrambled word is " << scrambled << endl;
	cout << "You have three guesses at the original word" << endl << endl;
	
	// While loop to allow for 3 guesses. It calls trim function and lowercase function in each 
	// loop to make it a fair case insesitive comparison to input. Count is then iterated.
	// nested if statement is used to compare guess and input. If equal, user is congratulated
	// and count is set to 3 so that the loop stops. If this is false, else if is tested and determines
	// if 3 guesses have been used. If true, user is informed they have lost and correct word is revealed.
	// Otherwise the user is just told there guess is not correct and to try again
	while (count < 3) {
		cout << "Guess the original word: ";
		cin >> guess;
		guess = trim(guess);
		guess = to_lowercase(guess);
		count++;
		
		if (guess == input) {
			cout << "Congratulations, you guessed the word correctly!" << endl;
			count = 3;
		}
		else if (guess != input && count >= 3) {
			cout << "You have exhausted all three of your guesses" << endl;
			cout << "The correct word was " << input << endl;
		}
		else
			cout << "That is not correct, make another guess" << endl;
	}
	return 0;
}
// Scramble function scrambles the input word by player 1. It takes in the input as a parameter and users 
// a for loop that iterates 100 times to effetcively scramble the word and then returns the scrambled word 
string scramble_string(string input) {
	
	// For loop used to scramble word. It iterates 100 times and 
	for (int i = 0; i < 100; i++) {
		int randx = (rand() % (input.length() - 1)), randy = (rand() % (input.length() - 1));
		char x = input[randx];
		char y = input[randy];
		input[randx] = y;
		input[randy] = x;
	}
	return input;
}
string trim(string str) {
	
	str.erase(0, str.find_first_not_of("\t\n\r\v\f "));
	str.erase(str.find_last_not_of("\t\n\r\v\f ") + 1);
	
	return str;
}

string to_lowercase(string str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
		
	return str;
}