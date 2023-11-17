/* Kyle Tranfaglia
 * 10/3/22
 * Homework#3 - Exercise 1
 * This program will read in from a file integer numbers and determine the minimum and maximum of those numbers
 */
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;

    // Variables
	ifstream inputFile;
	string fileName = "";
	long number = 0, min = 0, max = 0;
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("HW03Files/" + fileName);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error
	// message will be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	inputFile >> number;
	min = max = number;
	
	// While loop runs until an long data dype can no longer be read in from the file (EOF). Nested if statement 
	// compares the read in long value to the maximum value and sets it as max if true. If false, it compares 
	// long value to the minimum value and sets it as min if true, and if both are false the loop just iterates
	while (inputFile >> number ) {
		if (number > max)
			max = number;
		else if (number < min)
			min = number;
		}
	inputFile.close();
	
	cout << "Maximum = " << max << endl;
	cout << "Minimum = " << min << endl;
	
	return 0;
}