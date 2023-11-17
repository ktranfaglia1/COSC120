/* Kyle Tranfaglia
 * 10/3/22
 * Lab#4 - Exercise 1
 * This program does a function of most word processors. It counts lines, words, and characters of a file
 */
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;

    // Variables
	ifstream inputFile;
	string fileName = "", word = "", line = "" ;
	char character = ' ';
	int wordCount = 0, charCount = 0, lineCount = 0;
	
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("lab04Files/" + fileName);
	
	// If the file is found, a while loop starts that reads each word by recognizing the 
	// whitespace after every word, and moving the pointer there. This continues until this
	// statement is false, which will happen when the pointer hits the EOf terminator which 
	// is not a whitespace. After each whitespace, the count increments. File is closed after
	// loop finished. If the file is never found, the program terminates and and error message is printed
	if (inputFile) {
		while (inputFile >> word) {
			wordCount++;
		}
		inputFile.close();
	}
	else {
		cerr << "Error opening the file.\n";
		return 1;
		}
	cout << "Word Count: " << wordCount << endl;
	
	inputFile.open("lab04Files/" + fileName);
	
	// If the file is found, a while loop starts that reads each character by starting with the pointer
	// at the beginning and moving the pointer forward after each iteration. This continues until this
	// statement is false, which will happen when the pointer hits the EOf terminator and character holds EOF
	// which will yield false as stated by condition. After each character, the count increments. File is closed
	// after loop finished. If the file is never found, the program terminates and and error message is printed
	if (inputFile) {
		while ((character = inputFile.peek()) != EOF) {
			inputFile.get(character);
			charCount++;
		}
		inputFile.close();
	}
	else {
		cerr << "Error opening the file.\n";
		return 1;
		}
	cout << "Character Count: " << charCount << endl;
		
	inputFile.open("lab04Files/" + fileName);
	
	// If the file is found, a while loop starts that reads a string up until the end of string signified by
	// the null terminator that causes the line break. The loop then iterates and reads the next line and continues
	// until the statement is false, which will happen when the next line no longer contains a string, or in other 
	// words, when the EOF is reached. After each null terminator, the count increments. File is closed
	// after loop finished. If the file is never found, the program terminates and and error message is printed
	if (inputFile) {
		while (getline(inputFile, line)) {
			lineCount++;
		}
		inputFile.close();
	}
	else {
		cerr << "Error opening the file.\n";
		return 1;
		}
		cout << "Line Count: " << lineCount << endl;
		
	return 0;
}