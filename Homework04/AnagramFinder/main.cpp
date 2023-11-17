/* Kyle Tranfaglia
 * 10/10/22
 * Homework#4 - Exercise 4
 * This program will find anagrams of an input word by reading in a file with a lot of words
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Prototypes for uppercase function and anagram finder function
string to_uppercase(string str);
bool is_anagram(string input, string word);

int main () {
	
	ifstream inputFile;
	string input = "", word = "";
	
	inputFile.open("HW04Files/words.txt");
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error
	// message will be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	cout << "Input a single word: ";
	cin >> input;
	input = to_uppercase(input); // Calls uppercase function
	cout << "Anagrams of " << input << endl;
	
	// While loop to read in file word by word, turns each to uppercase by calling uppercase function,
	// then nested if statement to call anagram finder in test expression. If call to function returns true,
	// that word is printed, otherwise block is skipped and loop continues until nothing is left to read in
	while (inputFile >> word ) {
		word = to_uppercase(word);
		if (is_anagram(input, word))
			cout << word << endl;
	}
	inputFile.close();
	
	return 0;
}
// Function to take a single string parameter and turn it to uppercase using a for loop that uses the toupper
// command to change the word to uppercase character by character and then the uppercase string is returned
string to_uppercase(string str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
		
	return str;
}
// Anagram finder function that utilizes a series of nested loops and if statements. Function takes in 
// two strings. If function determines a word is an anagram, it returns true
bool is_anagram(string input, string word) {
	// If the strings are equal in length, nested for loop runs another nested for loop and 
	// if the index of word equals any index of input, word and input are replaced by "*" at their corresponding 
	// matching indexes and after the first nested for loop finsihes, word and input are compared. If word and 
	// input now both equal all "*" symbols, they are anagrams and the function retuns true.
	if (input.length() == word.length()) {
		for (unsigned int i = 0; i < word.length(); i++)
			for (unsigned int k = 0; k < word.length(); k++)
				if (word[i] == input[k]) {
					word[i] = '*';
					input[k] = '*';
				}
		if (word == input)
			return true;
	}
	return false;
}