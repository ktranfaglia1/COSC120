/* Kyle Tranfaglia
 * 10/20/22
 * Homework#5 - Exercise 4
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
	string fileName = "", dummy = "", newDummy = "";
	string words[25] = { "the", "of", "to", "and", "a", "in", "that", "is", "i", "it", "for","as", "with",
						"you", "on", "was", "be", "he", "this", "not", "have", "are", "at", "if", "but" };
	double wordCount = 0;
	int A[25] = {0};
	
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
	
	// While loop to run as long as a string can be read in from file. Congregating string is emptied after every loop.
	// nested for loop used to check if each character in string is alphabetical, and if so, converts it to lowercase
	// and begins congregating a new string with those characters. An if statement is the used to increment count of wrods
	// as long as the words is not a blank string, meaning it is not a word. Last for loop is used to check if any words in
	// the array equals the word and if so, the loop stops and the corresponding spot in integer array is incremented
	while (file >> dummy) {
		newDummy = "";
		for (unsigned int i = 0; i < dummy.length(); i++) {
			if ((dummy[i] >= 'A' && dummy[i] <= 'Z') || (dummy[i] >= 'a' && dummy[i] <= 'z'))
				newDummy += tolower(dummy[i]);
        }
		if (newDummy != "")
			wordCount++;
		for (int i = 0; i < 25; i++) {
			if (words[i] == newDummy) {
				A[i]++;
				i = 25;
			}
		}
	}
	file.close();
	file.open("HW05Files/" + fileName, ios::out | ios::app);
	
	// For loop to interate 25 times, printing out the word in the array at that location and then print integer array data
	// at that location divided by word count to get frequency, printing to both the console and the output file decided by user
	for (int i = 0; i < 25; i++) {
		cout << words[i] << "\t" << (A[i]/wordCount) << endl;
		file << words[i] << "\t" << (A[i]/wordCount) << endl;
	}
	file << endl;
	file.close();
	
	return 0;
}