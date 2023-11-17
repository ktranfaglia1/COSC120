/* Kyle Tranfaglia
 * 11/07/22
 * Project#1 - Exercise 2
 * This program is a document case insensitive checker. The program will get a dictonary file and a document file from the user 
 * spell check the words, and if any word is not in the dictionary, it states that and provide some suggestions, but does repeat words
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Prototypes
bool PopulateVector(vector<string> &vec, string str);
string Uppercase(string str);
int BinarySearch(const vector<string> &dictionary, string word);
void WordSuggestions(const vector<string> &dictionary, vector<string> &suggestions, string word, string fileName, char choice);
void OneCharDiff(const vector<string> &dictionary, vector<string> &suggestions, string word);
void TransposeTwoAdjacent(const vector<string> &dictionary, vector<string> &suggestions, string word);
void AddCharacter(const vector<string> &dictionary, vector<string> &suggestions, string word);
void RemoveCharacter(const vector<string> &dictionary, vector<string> &suggestions, string word);
void Continuation(const vector<string> &dictionary, vector<string> &suggestions, string word);
void RemoveDuplicates(vector<string> &vec);

int main () {
	
	// Variables
	fstream outputFile;
	string word = "", fileName = "", dummy = "";
	vector<string> dictionary, suggestions, document, misspelled;
	char choice = ' ';
	// Calls populate vector function twice to populate both vectors, and if it returns true, it means that the file did not open successfully for both so it returns 1
	if (PopulateVector(dictionary, "dictionary") || PopulateVector(document, "document")) {
		return 1;
	}
	cout << "Send output to the screen, a file, or both? S/F/B: ";
	cin >> choice;
	choice = toupper(choice);
	// Input validation loop. If user input is not one of the three letters, the user os informed of invalid input, and propted to enter new input until valid
	while (choice != 'S' && choice != 'F' && choice != 'B') {
		cout << "Invalid input!. Please enter S (screen), F (File), or B (Both)" << endl;
		cout << "Send output to the screen, a file, or both? S/F/B: ";
		cin >> choice;
		choice = toupper(choice);
	}
	// Checks if user wants the output written into a file, and if so asks for the file name to write data to 
	if (choice == 'F' || choice == 'B') {
		cout << "Input document filename: ";
		cin >> fileName;
	}
	sort(dictionary.begin(), dictionary.end()); // Uses algorithm sort to quickly sort the dictioanry vector by ASCII value for efficient naviagting
	// Loop that runs for the size of the document to go through every word in the document, and constructs a new word using only characters, -, and '.
	 for (unsigned int i = 0; i < document.size(); i++) {
		dummy = document[i];
		word = "";
		for (unsigned int j = 0; j < dummy.length(); j++) {
			if ((dummy[j] >= 'A' && dummy[j] <= 'Z') || dummy[j] == '-' || dummy[j] == '\'') {
				word += dummy[j];
			}
		}
		// Calls binary search function and sends the formatted word as a paramter with the dictionary vector. If this returns -1, the word was not 
		// found in the dictionary, so the word is pushed back on the vector holding misspelled words
		if (BinarySearch(dictionary, word) == -1 ) {
			misspelled.push_back(word);
		}
	}
	// Compares user choice for output and size of misspelled vector to determine requested output by user. If the size of the vector is zero,
	// they are informed there are no spelled words in a format determined by choice of output, and if not, the else runs and 
	// a function to remove duplicates from the misspelled vector is called and then a loop runs to call word suggestions function
	// for every word in misspelled vector
	if (misspelled.size() == 0 && choice == 'B') {
		cout << endl << "There are no misspelled words" << endl;
		outputFile.open("Project1Files/" + fileName, ios:: out | ios::app);
		outputFile << endl << "There are no misspelled words" << endl;
		outputFile.close();
	}
	else if (misspelled.size() == 0 && choice == 'F') {
		outputFile.open("Project1Files/" + fileName, ios:: out | ios::app);
		outputFile << endl << "There are no misspelled words" << endl;
		outputFile.close();
	}
	else if (misspelled.size() == 0 && choice == 'S') {
		cout << endl << "There are no misspelled words" << endl;
	}
	else {
		RemoveDuplicates(misspelled); // Call to a fucntion to remove any duplicate words from vector
		for (unsigned int i = 0; i < misspelled.size(); i++) {
			word = misspelled[i];
			WordSuggestions(dictionary, suggestions, word, fileName, choice); // Call to function to find word suggestionms for misspelled word
		}
	}
	return 0;
}
// Function to open the a file, populate a vector with the words contained in the file, return true if the file does not open, and false if it does
bool PopulateVector(vector<string> &vec, string str) {
	
	ifstream inputFile;
	string fileName = "", dummy = "";
	
	cout << "Input " << str << " filename: "; // gets filename for using the literal paramter passed and captureed by str variable
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
		vec.push_back(Uppercase(dummy));
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
void WordSuggestions(const vector<string> &dictionary, vector<string> &suggestions, string word, string fileName, char choice) {
	
	fstream outputFile;
	// Calls all the functions that find word suggestions
	OneCharDiff(dictionary, suggestions, word);
	TransposeTwoAdjacent(dictionary, suggestions, word);
	AddCharacter(dictionary, suggestions, word);
	RemoveCharacter(dictionary, suggestions, word);
	Continuation(dictionary, suggestions, word);
	// Compares choice from user on input, and if they selected a file output, the output file will be opened and set to be appended
	if (choice == 'F' || choice == 'B') {
		outputFile.open("Project1Files/" + fileName, ios:: out | ios::app);
	}
	RemoveDuplicates(suggestions); // Calls function to remove the duplicate words stored in suggestions vector
	// Formats the output for both console and text file ouput, or just one of each depending if the user slected 'B,' 'F,' or 'S' and 
	// either prints that there was no suggestions found if the suggestion vector has a size of 0, or prints each suggestion by order of index
	if (choice == 'B') {
		cout << endl << word << " is not in the dictionary" << endl << endl;
		cout << "Suggestions" << endl << "-----------" << endl;
		outputFile << endl << word << " is not in the dictionary" << endl << endl;
		outputFile << "Suggestions" << endl << "-----------" << endl;
		if (suggestions.size() == 0) {
			cout << "None" << endl;
			outputFile << "None" << endl;
		}
		else {
			for (unsigned int i = 0; i < suggestions.size(); i++) {
				cout << suggestions[i] << endl;
				outputFile << suggestions[i] << endl;
			}
		}
		outputFile.close(); // Closes the file
	}
	else if (choice == 'F') {
		outputFile << endl << word << " is not in the dictionary" << endl << endl;
		outputFile << "Suggestions" << endl << "-----------" << endl;
		if (suggestions.size() == 0) {
			outputFile << "None" << endl;
		}
		else {
			for (unsigned int i = 0; i < suggestions.size(); i++) {
				outputFile << suggestions[i] << endl;
			}
		}
		outputFile.close(); // Closes the file
	}
	else {
		cout << endl << word << " is not in the dictionary" << endl << endl;
		cout << "Suggestions" << endl << "-----------" << endl;
		if (suggestions.size() == 0) {
			cout << "None" << endl;
		}
		else {
			for (unsigned int i = 0; i < suggestions.size(); i++) {
				cout << suggestions[i] << endl;
			}
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
// Function to remove duplicates from a vector of strings by using the erase command after comparing indexes of vector
void RemoveDuplicates(vector<string> &vec) {
	
	// Loop runs for size of suggestions vector to erase any duplicate suggestions by comparing each index to all other indexes of the vector
	// and erases the duplicate index if they are equal but not the same index
	for (unsigned int i = 0; i < vec.size(); i++) {
		for (unsigned int k = 0; k < vec.size(); k++) {
			if (vec[i] == vec[k] && i != k)
				vec.erase(vec.begin() + k);
		}
	}
}