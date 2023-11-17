/* Kyle Tranfaglia
 * 10/3/22
 * Lab#4 - Exercise 2
 * This program will take a dictionary file and find all the words that have THE as part of the word
 */
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;

    // Variables
	ifstream inputFile;
	string word = "", fileName = "";
	int theCount = 0;
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("lab04Files/" + fileName);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error message will 
	// be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	// While loop is used to read each word of the file. The end of the word is recognized by whitespace and the nested
	// for loop will run after every word. This loop converts the word to uppercase by converting each individual character
	// of the word. Then, the nested if statement is read. If "THE" is present anywhere in that word, a position is assigned
	// to where the word "THE" begins in the words, making the statment true, so the count will increment. Otherwise, if the word 
	// "THE" is not found, the value of the search is the constant string::npos, making the statement false and the block will not run. 
	while (inputFile >> word) {
		for (unsigned int i = 0; i < word.length(); i++) {
			word[i] = toupper(word[i]);
		}
		if (word.find("THE") != string::npos)
			theCount++;
		}
	inputFile.close();
	
	cout << "The count: " << theCount << endl;
	
	return 0;
}