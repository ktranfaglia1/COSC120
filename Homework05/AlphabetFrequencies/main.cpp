/* Kyle Tranfaglia
 * 10/20/22
 * Homework#5 - Exercise 3
 * This program will read the source text file and determine the relative frequencies
 * of all the alphabetic characters in a case-insensitive way.
 */
#include <fstream>
#include <iostream>
#include <string>

int main() {
	
	using namespace std;
	
	// Variables
	fstream file;
	string fileName = "";
	char dummy = ' ';
	double alphaCount = 0;
	int A[26] = {0};
	
	cout << "Input the input fileName: ";
	cin >> fileName;
	
	file.open("HW05Files/" + fileName, ios::in);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error
	// message will be displayed and the program will abruptly terminate
	if (!file) {
		cerr << "Error opening file.\n";
		return 1;
	}	
	cout << "Input the output fileName: ";
	cin >> fileName;
	
	// While loop to see if pointer is at end of file. If not, it gets letter in file, converts it to uppercase, then  uses
	// nested if to see if it is an alphabetical character, and if so count is incremented and that space in the array corresponding
	// to the letter is incremented using ASCII value logic to place in in array location by its difference from A
	while (file.peek() != EOF) {
		file.get(dummy);
		dummy = toupper(dummy);
		if (dummy >= 'A' && dummy <= 'Z') {
			alphaCount++;
			A[dummy - 'A']++;
//			for (int i = 0; i < 26; i++) {  // My previous Method that also works but is less efficent
//				if (('A' + i) == dummy) {
//					A[i]++;
//					i = 26;
//				}
//			}
		}
	}
	file.close();
	file.open("HW05Files/" + fileName, ios::out | ios::app);
	
	// For loop to interate 26 times, casting ASCII value to a character, and printing out the array data stored in the location
	// that corresponds to that letter divided by count to get frequency, printing to both the console and the output file decided by user
	for (int i = 0; i < 26; i++) {
		char letter = static_cast<char>(('A' + i));
		cout << letter << "\t" << (A[i]/alphaCount) << endl;
		file << letter << "\t" << (A[i]/alphaCount) << endl;
	}
	file << endl;
	file.close();
	
	return 0;
}