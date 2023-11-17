/* Kyle Tranfaglia
 * 10/3/22
 * Homework#3 - Exercise 2
 * This program finds all of the occurrences of the input word or phrase in the file and reports the results in a text file
 */
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;

    // Variables
	ifstream inputFile;
	fstream outputFile;
	string word = "", word2 ="", fileName = "", input = "", inputCase = "";
	int count = 0;
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("HW03Files/" + fileName);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error message will 
	// be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	cout << "Input the word or phrase to be found: ";
	cin.get();
	getline(cin, input);
	inputCase = input;
	
	for (unsigned int i = 0; i < inputCase.length(); i++) {
		inputCase[i] = toupper(inputCase[i]);
		}
	// While loop is used to read each word of the file. The end of the word is recognized by whitespace and the nested
	// for loop will run after every word. This loop converts the word to uppercase by converting each individual character
	// of the word. Then, the nested if statement is read. If "THE" is present anywhere in that word, a position is assigned
	// to where the word "THE" begins in the words, making the statment true, so the count will increment. Otherwise, if the word 
	// "THE" is not found, the value of the search is the constant string::npos, making the statement false and the block will not run. 
	while (inputFile >> word) {
		if (input.find(" ") != string::npos){
			inputFile >> word2;
			word += " " + word2;
		}
		for (unsigned int i = 0; i < word.length(); i++) {
			word[i] = toupper(word[i]);
		}
		if (word.find(inputCase) != string::npos)
			count++;
		}
	inputFile.close();
	
	cout << "The file contains " << count << " occurrences of \"" << input << "\"\n";
	
	outputFile.open("HW03Files/GUIDETOTHEGALAXY.txt", ios::out | ios::app);
	outputFile << "The file contains " << count << " occurrences of \"" << input << "\"" << endl;
	outputFile.close();
	
	return 0;
}