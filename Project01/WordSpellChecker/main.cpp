/* Kyle Tranfaglia
 * 11/07/22
 * Project#1 - Exercise 1
 * This program is a single word case insensitive checker. The program will get a dictonary file from the user, 
 * spell check the word, and if its not in the dictionary, state that and provide some suggestions
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Prototypes
bool PopulateVector(vector<string> &dictionary);
string Uppercase(string str);
void WordSuggestions(const vector<string> &dictionary, vector<string> &suggestions, string word);
void OneCharDiff(const vector<string> &dictionary, vector<string> &suggestions, string word);
void TransposeTwoAdjacent(const vector<string> &dictionary, vector<string> &suggestions, string word);
void AddCharacter(const vector<string> &dictionary, vector<string> &suggestions, string word);
void RemoveCharacter(const vector<string> &dictionary, vector<string> &suggestions, string word);
void Continuation(const vector<string> &dictionary, vector<string> &suggestions, string word);

int main () {
	
	// Variables
	string word = "";
	vector<string> dictionary, suggestions;
	char again = 'y';
	
	// Calls populate vector function and if it returns true, it means that the file did not open successfully so it returns 1
	if (PopulateVector(dictionary)) {
		return 1;
	}
	// Checks if value of again is 'Y' or 'y' (user input to continue, defaulted to y) and will run statement as long as this is true. 
	while (again == 'y' || again == 'Y') {
		cout << "Input a single word to spell check: ";
		cin >> word;
		word = Uppercase(word); // Converts word to uppercase
		cout << endl;
		// A linear search that goes through each index of dictionary vector and compares it to the user input. If true, then this 
		// word exists in the dictionary, otherwise, it is not, and the function to get word suggestions will be called
		for (unsigned int i = 0; i < dictionary.size(); i++) {
			if (dictionary[i] == word) {
				cout << word << " is in the dictionary" << endl << endl;
				i = dictionary.size();
			}
			else if (i == dictionary.size() - 1) {
				cout << word << " is not in the dictionary" << endl << endl;
				WordSuggestions(dictionary, suggestions, word);
			}
		}
		cout << "Check another word? Y/N: ";
		cin >> again;
		// Input validation loop. If input is not an acceptable input, the user is notified and instructed to input again until valid
		while ((again != 'y' && again != 'Y') && (again != 'n' && again != 'N')) {
			cout << "Invalid Input! Please enter y or n" << endl;
			cout << "Check another word? Y/N: ";
			cin >> again;
		}
	}
	
	return 0;
}
// Function to open the dictionary file, populate a vector with the words contained in the file, return true if the file does not open, and false if it does
bool PopulateVector(vector<string> &dictionary) {
	
	ifstream inputFile;
	string fileName = "", dummy = "";
	
	cout << "Input dictionary filename: ";
	cin >> fileName;
	
	inputFile.open("Project1Files/" + fileName); // Opens the file
	
	// Checks if the file opened. If the file opened correctly, the program skips over this block of code. Otherwise, the
	// comparison is true and an error message will be displayed and the function retruns true
	if (!inputFile) {
		cerr << "Error opening file: " << fileName;
		return true;
	}
	// Loop to read in all words from file, and stop when no more words can be read. After each word is read in, it is pushed to the back of a vector
	while (inputFile >> dummy) {
		dictionary.push_back(Uppercase(dummy));
	}
	inputFile.close(); // Closes the file
	
	return false;
}
// Function to convert a string to uppercase and retruning the new uppercase word as a string
string Uppercase(string str) {
	
	string caseString = "";
	// Loop to go through each letter of word and convert it to upercase using toupper command and reconstruct the word by adding the characters to a string 
	for (unsigned int i = 0; i < str.length(); i++) {
		caseString += toupper(str[i]);
	}
	return caseString;
}
// Function that returns nothing but all suggestion functions and updates suggestions vector passed by reference, then prints the suggestions
void WordSuggestions(const vector<string> &dictionary, vector<string> &suggestions, string word) {
	
	cout << "Suggestions" << endl << "-----------" << endl;
	// Calls all the functions that find word suggestions
	OneCharDiff(dictionary, suggestions, word);
	TransposeTwoAdjacent(dictionary, suggestions, word);
	AddCharacter(dictionary, suggestions, word);
	RemoveCharacter(dictionary, suggestions, word);
	Continuation(dictionary, suggestions, word);
	// Loop runs for size of suggestions vector to erase any duplicate suggestions by comparing each index to all other indexes of the vector
	// and erases the duplicate index if they are equal but not the same index
	for (unsigned int i = 0; i < suggestions.size(); i++) {
		for (unsigned int k = 0; k < suggestions.size(); k++) {
			if (suggestions[i] == suggestions[k] && i != k)
				suggestions.erase(suggestions.begin() + k);
		}
	}
	// Checks if any suggestions were found, and if not, prints none. Otherwise, the suggestions are printed in order of index until all are printed
	if (suggestions.size() == 0) {
			cout << "None" << endl;
		}
	else {
		for (unsigned int i = 0; i < suggestions.size(); i++) {
			cout << suggestions[i] << endl;
		}
	}
	suggestions.clear(); // Clears the suggestions vector so more words can be checked without adding to a vector with other suggestions
}
// Function to preform first search for suggestions by finding words that have a one charcater difference
void OneCharDiff(const vector<string> &dictionary, vector<string> &suggestions, string word) {
	
	int charsDiff = 0;
	string dictWord = "";
	// For loop that itearates for size of dictionary vector to compare each word to user word, first comparing length of words, and then the amount of characters
	// that are differnet, iterating a count each time. After the entire word is compared, if there was only one difference, the word is pushed back on suggestions vector
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		dictWord = dictionary[i];
		charsDiff = 0;
		if (dictWord.length() == word.length()) {
			for (unsigned int k = 0; k < word.length(); k++) {
				if (dictWord[k] != word[k])
					charsDiff++;
			}
		}
		if (charsDiff == 1) {
			suggestions.push_back(dictWord);
		}
	}
}
// Function to find suggestions by searching for words that are the transpose of two adjacent letters, updating the suggestions vector passed by reference
void TransposeTwoAdjacent(const vector<string> &dictionary, vector<string> &suggestions, string word) {
	
	string dictWord = "";
	unsigned int count = 0;
	// Loop that checks each word in dictionary and compares the length of both words, and if equal, runs a loop to compare letter at index
	// of word compared to letter of index minus one of dictioanry word and of the same index, iterating acount if ture. Then, if the count is the
	// same as length of word, then it must be a transpose of two adjacent letters so it is pushed back on suggestions vector
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		dictWord = dictionary[i];
		count = 0;
		if (dictWord.length() == word.length()) {
			for (unsigned int k = 1; k < word.length(); k++) {
				if (word[k] == dictWord[k-1] || word[k-1] == dictWord[k-1])
					count++;
			}
		}
		if (count == word.length()) {
			suggestions.push_back(dictWord);
		}
	}
}
// Function to find suggestions by searching for word with an added character and updates suggestion vector passed by reference
void AddCharacter(const vector<string> &dictionary, vector<string> &suggestions, string word) {
	
	string dictWord = "", dummy = "";
	// Loop that runs for size of dictionary vector to compare every dictionary word length to user word length and if user word is one less, the netsed 
	// for loop runs to test if erasing any of the characters from the dictionary word results in the user word, and if so, it is pushed back on vector
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		dictWord = dictionary[i];
		if (dictWord.length() == word.length() + 1) {
			for (unsigned int k = 0; k < word.length(); k++) {
				dummy = dictWord;
				dummy.erase(dummy.begin() + k);
				if (dummy == word) {
					suggestions.push_back(dictWord);
				}
			}
		}
	}
}
// Function to find suggestions by searching for word with an removed character and updates suggestion vector passed by reference
void RemoveCharacter(const vector<string> &dictionary, vector<string> &suggestions, string word) {
	
	string dictWord = "", dummy = "";
	// Loop that runs for size of dictionary vector to compare every dictionary word length to user word length and if user word is one more, the netsed 
	// for loop runs to test if erasing any of the characters from the user word results in the dictionary word, and if so, it is pushed back on vector
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		dictWord = dictionary[i];
		if (dictWord.length() + 1 == word.length()) {
			for (unsigned int k = 0; k < word.length(); k++) {
				dummy = word;
				dummy.erase(dummy.begin() + k);
				if (dummy == dictWord) {
					suggestions.push_back(dictWord);
				}
			}
		}
	}
}
// Function to find suggestions by searching for word that is a continuation of user word and updates suggestion vector passed by reference
void Continuation(const vector<string> &dictionary, vector<string> &suggestions, string word) {
	
	string dictWord = "";
	unsigned int match;
	// loop that runs for the size of dictionary vector to compare every dictionary word for to the user word but only for the length of the user word,
	// if all the characters of the user word match the dictionary word, then it must be a continutaion, meaning math count will equal word lenght,
	// and the dictionary word will be pushed back on the vector
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		dictWord = dictionary[i];
		match = 0;
		for (unsigned int k = 0; k < word.length(); k++) {
			if (word[k] == dictWord[k])
				match++;
		}
		if (match == word.length())
			suggestions.push_back(dictWord);
	}
}