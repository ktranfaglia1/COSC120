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
	unsigned int position = 0;
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("HW03Files/" + fileName);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error message 
	// will be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	cout << "Input the word or phrase to be found: ";
	cin.get();
	getline(cin, input);
	inputCase = input;
	
	// For loop to turn the input string to uppercase. Each character is individually converted to an uppercase and stored
	// back in its corresponding position in the string. This loop iterates for the length of the string
	for (unsigned int i = 0; i < inputCase.length(); i++) {
		inputCase[i] = toupper(inputCase[i]);
		}
	// While loop is used to read each line of the file. The end of the line is recognized by the null terminator that causes the
	// line to break. The nested for loop will run for each line, converting the line to uppercase by converting each individual character
	// and assigning it back to its corresponding position in the string. Nested while loop is used to identify the starting position of
	// the first instance of the input in the line. If the input is found, count is incremented and the pointer is set to the whitespace 
	// after the position of the first matching word/phrase and the loop continues until the input can no longer be found in the line.
	while (getline(inputFile, word)) {
		for (unsigned int i = 0; i < word.length(); i++) {
			word[i] = toupper(word[i]);
		}
		while ((position = word.find(inputCase)) != string::npos) {
			word = word.substr(position + input.length());
			count++;
		}
	}
	inputFile.close();
	
	cout << "The file contains " << count << " occurrences of \"" << input << "\"\n";
	
	outputFile.open("HW03Files/GUIDETOTHEGALAXY.txt", ios::out | ios::app);
	outputFile << "The file contains " << count << " occurrences of \"" << input << "\"" << endl;
	outputFile.close();
	
	return 0;
}