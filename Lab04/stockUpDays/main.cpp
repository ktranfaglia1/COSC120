/* Kyle Tranfaglia
 * 10/3/22
 * Lab#4 - Exercise 3
 * This program will ask the user to input a filename on stock data, read in the data, and display a count of the number of up days
 */
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;

    // Variables
	ifstream inputFile;
	string fileName = "", date = "";
	int upDays = 0;
	double opening = 0, closing = 0, value = 0;
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("lab04Files/" + fileName);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error
	//  message will be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	getline(inputFile, date); // gets the first line of file - header - before loop
	
	// While there is a date (string) that the program is able to read from the file, the loop will continue
	// meaning that once there is not an initial date being read by the program, it must be at the end of file 
	// and the loop will terminate. Within the loop, the program then reads after teh first tab in the file 
	// to get the first double value and does this again to get the second value. These values are then compared
	// with an if statement. If the second value (closing) is greater than first value (opening) upDays is iterated.
	while (inputFile >> date ) {
		inputFile >> value;
		opening = value;
		inputFile >> value;
		closing = value;
		if (closing > opening)
			upDays++;
		}
	inputFile.close();
	
	cout << "The number of Up days: " << upDays << endl;
	
	return 0;
}