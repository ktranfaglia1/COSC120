/* Kyle Tranfaglia
 * 10/10/22
 * Homework#4 - Exercise 2
 * This program uses a function to find all of the occurrences of the input word or phrase in the file and reports the results in console
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototype for string counter function
int count_strings(string fileName, string input);

int main() {

    // Variables
	string fileName = "", input = "";
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	cout << "Input the word or phrase to be found: ";
	cin.get();
	getline(cin, input);
	
	// If statement that calls the count strings function and sends two string parameters. If the value returned 
	// by the function is -1, this signifies an error opening file so the block runs and terminates the program.
	if (count_strings(fileName, input) == -1) {
		cerr << "Error opening file.\n";
		return 1;
	}
	cout << "The file contains " << count_strings(fileName, input) << " occurrences of \"" << input << "\"\n";
	
	return 0;
}
// Function to count the number of times an input word or phrase is file by recieving file name and input,
// opening the file, setting input to uppercase, and using a while loop to read in the file line by line, setting
// the line to uppercase, and then if searching for a word or phrase on that line yeilds a result (position number)
// it moves the pointer past the word, iterates the count, and repeats until input is no longer on that line
int count_strings(string fileName, string input) {
	
	ifstream inputFile;
	string word = "";
	int count = 0;
	unsigned long position = 0;
	
	inputFile.open("HW04Files/" + fileName);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this
	// return statement. If false, function returns -1.
	if (!inputFile) {
		return -1;
	}
	// For loop to turn the input string to uppercase. Each character is individually converted to an uppercase and stored
	// back in its corresponding position in the string. This loop iterates for the length of the string
	for (unsigned int i = 0; i < input.length(); i++) {
		input[i] = toupper(input[i]);
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
		while ((position = word.find(input)) != string::npos) {
			word = word.substr(position + input.length());
			count++;
		}
	}
	inputFile.close();
	
	return count;
}