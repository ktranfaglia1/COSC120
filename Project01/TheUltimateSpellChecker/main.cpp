/* Kyle Tranfaglia
 * 11/07/22
 * Project#1 - Exercise 3
 * This program is a document case sensitive checker. The program will get a dictonary file and a document file from the user 
 * spell check the words, and if any word is not in the dictionary, it states that and provide some suggestions, but does repeat words.
 * The user can then choose from the suggestions, keep the word, or write and new one and the document will be updated 
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Prototypes
bool PopulateVector(vector<string> &vec, string str, string &fileName);
int BinarySearch(const vector<string> &dictionary, string word);
void WordSuggestions(const vector<string> &dictionary, const vector<int> &misspelledPosition, vector<string> &document, vector<string> &suggestions, string word);
void OneCharDiff(const vector<string> &dictionary, vector<string> &suggestions, string word);
void TransposeTwoAdjacent(const vector<string> &dictionary, vector<string> &suggestions, string word);
void AddCharacter(const vector<string> &dictionary, vector<string> &suggestions, string word);
void RemoveCharacter(const vector<string> &dictionary, vector<string> &suggestions, string word);
void Continuation(const vector<string> &dictionary, vector<string> &suggestions, string word);
void DisplayAndUpdate(const vector<int> &misspelledPosition, vector<string> &document, vector<string> &suggestions, string caseWord);
void RemoveDuplicates(vector<string> &vec);
void RemoveDuplicates(vector<string> &vec, vector<int> &parallel);
void CapitalizeSuggestions(vector<string> &suggestions);
void printUpdatedDocument(const vector<string> &document, const string &fileName);

int main () {
	
	// Variables
	string word = "", fileName = "", dummy = "", capWord = "";
	vector<string> dictionary, suggestions, document, misspelled; 
	vector<int> misspelledPosition;
	// Calls populate vector function twice to populate both vectors, and if it returns true, it means that the file did not open successfully for both so it returns 1
	if (PopulateVector(dictionary, "dictionary", fileName) || PopulateVector(document, "document", fileName)) {
		return 1;
	}
	sort(dictionary.begin(), dictionary.end()); // Uses algorithm sort to quickly sort the dictioanry vector by ASCII value for efficient naviagting
	// Loop that runs for the size of the document to go through every word in the document, and constructs a new word using only characters, -, and '.
	// this loop gets the capitalized and non capitalized word if different, and sends uncapitalized into search but capitalized to misspelled vector
	for (unsigned int i = 0; i < document.size(); i++) {
		dummy = document[i];
		word = "";
		capWord = "";
		for (unsigned int j = 0; j < dummy.length(); j++) {
			if ((dummy[j] >= 'A' && dummy[j] <= 'Z') || (dummy[j] >= 'a' && dummy[j] <= 'z') || dummy[j] == '-' || dummy[j] == '\'') {
				word += tolower(dummy[j]);
				capWord += dummy[j];
			}
		}
		// Calls binary search function and sends the non capitalized formatted word as a paramter with the dictionary vector. If this returns -1, the word was not 
		// found in the dictionary, so the capitalized word is pushed back on the vector holding misspelled words and i is pushed back on position parallel vector
		if (BinarySearch(dictionary, word) == -1 ) {
			misspelled.push_back(capWord);
			misspelledPosition.push_back(i);
		}
	}
	RemoveDuplicates(misspelled, misspelledPosition); // Call to a fucntion to remove any duplicate words from vector
	// Compares size of vector to zero to see if there were no misspelled words. Otherwise, a for loop runs to send each mispelled word
	// to the word suggestions function to be earched for suggestions and updated in the document
	if (misspelled.size() == 0) {
		cout << endl << "There are no misspelled words" << endl;
	}
	else {
		for (unsigned int i = 0; i < misspelled.size(); i++) {
			word = misspelled[i];
			WordSuggestions(dictionary, misspelledPosition, document, suggestions, word); // Call to function to find word suggestionms for misspelled word
		}
	}
	cout << endl << "Done spell checking the file.";
	printUpdatedDocument(document, fileName);
	
	return 0;
}
// Function to open the a file, populate a vector with the words contained in the file, return true if the file does not open, and false if it does
bool PopulateVector(vector<string> &vec, string str, string &fileName) {
	
	ifstream inputFile;
	string dummy = "";
	
	cout << "Input " << str << " filename: "; // Gets file name to open file
	cin >> fileName;
	
	inputFile.open(fileName); // Opens the file
	
	// Checks if the file opened. If the file opened correctly, the program skips over this block of code. Otherwise, the
	// comparison is true and an error message will be displayed and the function retruns true
	if (!inputFile) {
		cerr << "Error opening file: " << fileName;
		return true;
	}
	// Loop to read in all words from file, and stop when no more words can be read. After each word is read in, it is pushed to the back of a vector
	while (inputFile >> dummy) {
		vec.push_back(dummy);
	}
	inputFile.close(); // Closes the file
	
	return false;
}
// Function that uses a binary search to look for the user word from the document in the dictionary that was sorted by ASCII value and retruns -1 if it does not find word
int BinarySearch(const vector<string> &dictionary, string word) {
	
	int first = 0;
	int last = dictionary.size() - 1;
	int middle = 0;
	// Loop to perform binary search by comapring first and last value and then setting the middle to the sum of first and last divided by two, and checks if
	// the middle term is the word and will return middle if true, but if not, it compares ASCII value of dictionary word at middle index to word and if it is
	// less, the last becomes one minus the middle, or if more, first becomes middle plus one. Loop ends when word found or first is greater than last
	while (first <= last) {
		middle = (first + last) / 2;
		if (dictionary[middle] == word) {
			return middle;
		} else if (dictionary[middle] > word)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return -1;
}
// Function that returns nothing but all suggestion functions and updates suggestions vector passed by reference, and then updates document vector with correct words
void WordSuggestions(const vector<string> &dictionary, const vector<int> &misspelledPosition, vector<string> &document, vector<string> &suggestions, string word) {
	
	string caseWord = word, dummy = word; // Incoming word parameter may be capitalized, so it is initialized to new variable to denote this
	// Sets word to an empty string and then uses loop to convert word to lowercase so it can be used in suggestion functions
	word = "";
	for (unsigned int j = 0; j < dummy.length(); j++) {
		word += tolower(dummy[j]);
	}
	// Calls all the functions that find word suggestions
	OneCharDiff(dictionary, suggestions, word);
	TransposeTwoAdjacent(dictionary, suggestions, word);
	AddCharacter(dictionary, suggestions, word);
	RemoveCharacter(dictionary, suggestions, word);
	Continuation(dictionary, suggestions, word);
	RemoveDuplicates(suggestions); // Calls function to remove the duplicate words stored in suggestions vector
	
	// Calls function to display the incorrect word, context, and suggestions, and update the document
	DisplayAndUpdate(misspelledPosition, document, suggestions, caseWord);

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
	unsigned int match = 0;
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
// Larger Function to display all the console information such as misspelled word, context, and suggestions, and then update the document according to the user input
void DisplayAndUpdate(const vector<int> &misspelledPosition, vector<string> &document, vector<string> &suggestions, string caseWord) {
	
	string replacement = "";
	char selection = ' ';
	static int count = 0; // static variable used so that count does not start back at 0 after every call to function
	int position = misspelledPosition[count];
	
	cout << "\n\"" << caseWord << "\" is not in the dictionary" << endl << endl;
	cout << "Context: ";
	// Loop to print the context of the misspelled word by printing the four indexes before the word, but not printing if the index is negative
	for (int i = position - 4; i < position; i++) {
		if (i < 0) {
			continue;
		}
		else {
			cout << document[i] << " ";
		}
	} 
	cout << "<<< " << document[position] << " >>> ";
	// Loop to print the context of the misspelled word by printing the four indexes after the word but only if it doesnt reach the end of the document
	for (int i = position + 1; i < position + 5; i++) {
		if (i > document.size() - 1) {
			break;
		}
		else {
			cout << document[i] << " ";
		}
	}
	// Compares first index of word and if its ASCII value is within capital letter range, then the capitalize suggestions vector is called to capitalize the suggested words
	if (caseWord[0] >= 'A' && caseWord[0] <= 'Z') {
		CapitalizeSuggestions(suggestions);
		cout << "running";
	}
	cout << endl << endl << "Select Action" << endl << "-----------" << endl;
	cout << "K: Keep word as is" << endl << "C: Input word to replace" << endl;
	// Statement to compare size of suggestions vector to literal value 10 as if it is less or equal, it uses for loop to display numbered suggestions for entire vector
	if (suggestions.size() <= 10) {
		for (unsigned int i = 0; i < suggestions.size(); i++) {
			cout << (i + 1) % 10 << ": " << suggestions[i] << endl;
		}
	}
	// If size of suggestions vector is more than 10, it uses for loop to display numbered suggestions for the first ten indexes of the vector
	else {
		for (unsigned int i = 0; i < 10; i++) {
			cout << (i + 1) % 10 << ": " << suggestions[i] << endl;
		}
	}
	cout << endl << "Selection: ";
	cin >> selection;
	selection = toupper(selection); // Converts the uper input character to uppercase for easier comparison 
	unsigned int val = selection - '1' + 1;
	while ((selection != 'K' && selection != 'C') && (val < 0 || val > suggestions.size()))  {
		cout << endl << "Invalid selection! Please eneter one of the designated inputs above" << endl;
		cout << "Selection: ";
		cin >> selection;
		selection = toupper(selection);
		val = selection - '1' + 1;
	}
	string wordInContext = document[position]; // Gets word with any attached characters such as a period for later comparison
// Statement to compare the value of the choice to options. If 'C,' the user selects a word to replace the misspelled word with and then a for loop is
// used to change all instances of the misspelled word to the replacment word. Otherwise, if the sleection is a number, it changes the document word
// to the suggetsed word at the selected index (minus one) unless 0, then it uses index of 9. If the uses selects k, no additional statement runs and the word remains
	if (selection == 'C') {
		cout << "Input replacement word: ";
		cin >> replacement;
		for (unsigned int i = 0; i < document.size(); i++) {
			if (document[i] == caseWord)
				document[i] = replacement;
			else if (document[i] == wordInContext)
				document[i] = replacement + wordInContext[wordInContext.length() - 1];
		}
	}
	else if (val > 0 && val <= 9) {
		for (unsigned int i = 0; i < document.size(); i++) {
			if (document[i] == caseWord)
				document[i] = suggestions[val - 1];
			else if (document[i] == wordInContext)
				document[i] = suggestions[val - 1] + wordInContext[wordInContext.length() - 1];
		}
	}
	else if (val == 0) {
		for (unsigned int i = 0; i < document.size(); i++) {
			if (document[i] == caseWord)
				document[i] = suggestions[9];
			else if (document[i] == wordInContext)
				document[i] = suggestions[9] + wordInContext[wordInContext.length() - 1];
		}
	}
	count++; // Iterates a count for index of misspelledPosition
}
// Function to remove duplicates from a vector of string and int data type by using the erase command after comparing indexes of vector
void RemoveDuplicates(vector<string> &vec, vector<int> &parallel ) {
	
	// Loop runs for size of suggestions vector to erase any duplicate suggestions for the string vector and its parallel int vector 
	// by comparing each index to all other indexes of the vector and erases the duplicate index if they are equal but not the same index
	for (unsigned int i = 0; i < vec.size(); i++) {
		for (unsigned int k = 0; k < vec.size(); k++) {
			if (vec[i] == vec[k] && i != k) {
				vec.erase(vec.begin() + k);
				parallel.erase(parallel.begin() + k);
			}
		}
	}
}
// Function overloading to allow a remove duplicates function to work when sending one string vector, still using erase command after comparing indexes
void RemoveDuplicates(vector<string> &vec) {
	
	// Loop runs for size of suggestions vector to erase any duplicate suggestions by comparing each index to all other indexes of the vector
	// and erases the duplicate index if they are equal but not the same index
	for (unsigned int i = 0; i < vec.size(); i++) {
		for (unsigned int k = 0; k < vec.size(); k++) {
			if (vec[i] == vec[k] && i != k) {
				vec.erase(vec.begin() + k);
			}
		}
	}
}
// Function to capitalize the first letter of the suggestions and update suggestions vector passed by refernece
void CapitalizeSuggestions(vector<string> &suggestions) {
	
	string dummy = "";
	// Loop to run for size of suggestions vector and set dummy to each index, turn only the first letter to uppercase, and then reasign dummy to index in vector
	for (unsigned int i = 0; i < suggestions.size(); i++) {
		dummy = suggestions[i];
		dummy[0] = toupper(dummy[0]); 
		suggestions[i] = dummy;
	}
}
// Function to open an output file for the checked document and write onto the file using the updated, spell checked document with an 80 character per line format
void printUpdatedDocument(const vector<string> &document, const string &fileName) {
	
	ofstream outputFile;
	int lengthSum = 0;
	
	outputFile.open("Project1Files/Checked_" + fileName); // Creates and opens the checked output file
	cout << " Saving new file" << endl;
	// Loop that runs for the size of the document vector and outputs the document one index at a time, seperated by a space, and then keeps a running total
	// of the linelength, which resets everytime the if statement is true. The if statment is used to check if the liencount is less than or equal to 80, 
	// but if the next word would cause it to go over 80, whih if this is true, a new line starts, and the running total is set back to 0
	for (unsigned int i = 0; i < document.size(); i++) {
		outputFile << document[i] << " ";
		lengthSum += document[i].length() + 1;
		if (lengthSum <= 80 && (lengthSum + document[i+1].length() + 1) > 80) {
			outputFile << endl;
			lengthSum = 0;
		}
	}
	outputFile.close();
	cout << "Done" << endl;
}