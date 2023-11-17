/* Kyle Tranfaglia
 * 10/17/22
 * Lab#6 - Exercise 
 * This program will ask the user to input a filename on stock data, read in the data,
 * and display a set of descriptive statistics for the stock
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// Prototypes
int getDayCount(fstream &inputFile);
void printStockDataChart(fstream &inputFile);
double CalculateAverageClosingValue(fstream &inputFile);
int CalculateUpDayCount(fstream &inputFile);
int CalculateDownDayCount(fstream &inputFile);
int CalculateFlatDayCount(fstream &inputFile);
void getClimbData(fstream &inputFile, int &longestClimb, string &startDate, string &endDate);
void getFallData(fstream &inputFile, int &longestFall, string &startDate, string &endDate);
void getMaxDayIncrease(fstream &inputFile, double &increaseMax, string &date);
void getMaxDayDecrease(fstream &inputFile, double &decreaseMax, string &date);

int main() {
	
	// Variables
	fstream inputFile;
	string fileName = "", header = "", date = "", startDate = "", endDate = "";
	int dayCount = 0, upDays = 0, downDays = 0, flatDays = 0, longestClimb = 1, longestFall = 1;
	double avgClosing = 0, increaseMax = 0, decreaseMax = 0;
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("lab06Files/" + fileName, ios::in);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error
	// message will be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	getline(inputFile, header); // gets the first line of file - header
	
	// Functions are called and then the return values or altered reference variables are displayed
	cout << setprecision(6) << fixed;
	printStockDataChart(inputFile);
	cout << endl << "Stock Statistics for file " << fileName << endl;
	cout << "=======================================" << endl;
	dayCount = getDayCount(inputFile);
	cout << "Number of days in data set: " << dayCount << endl;
	avgClosing = CalculateAverageClosingValue(inputFile);
	cout << "Average closing stock price: $" << avgClosing << endl;
	upDays = CalculateUpDayCount(inputFile);
	cout << "Number of days stock went up: " << upDays << endl;
	downDays = CalculateDownDayCount(inputFile);
	cout << "Number of days stock went down: " << downDays << endl;
	flatDays = CalculateFlatDayCount(inputFile);
	cout << "Number of days stock stayed flat: " << flatDays << endl;
	getClimbData(inputFile, longestClimb, startDate, endDate);
	cout << "Longest climb: " << longestClimb << " days from " << startDate << " to " << endDate << endl;
	getFallData(inputFile, longestFall, startDate, endDate);
	cout << "Longest fall: " << longestFall << " days from " << startDate << " to " << endDate << endl;
	getMaxDayIncrease(inputFile, increaseMax, date);
	cout << "Largest Day Increase: " << increaseMax << " on " << date << endl;
	getMaxDayDecrease(inputFile, decreaseMax, date);
	cout << "Largest Day Decrease: " << abs(decreaseMax) << " on " << date << endl;
	
	return 0;
}
// Function to get number of days listed in file, taking in reference to opened file and returns integer value
int getDayCount(fstream &inputFile) {
	
	// Variables
	string line = "";
	long lineCount = 0;
	
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	getline(inputFile, line); // gets the first line of file - header
	
	// Reads in file line by line and if read is successful, linecount increments. Loop terminates when pointer
	// hits EOF, meaning no more lines can be read in
	while (getline(inputFile, line)) {
			lineCount++;
		}
	return lineCount;
}
// Function to print stock data from file into console while using the information to add daily change for each day.
// Nothing is returned, only printed given read in information from file reference
void printStockDataChart(fstream &inputFile) {
	
	// Variables
	string date = "";
	double opening = 0, closing = 0;
	
	cout << setw(9) << "Date" << setw(14) << "Opening" << setw(12) << "Closing" << setw(12) << "Change" << endl;
	cout << setprecision(6) << fixed; // 6 decimal precision
	
	// While loop to read in date as string, and opening and closing as doubles, with a nested if statement
	// to compare closing and opening to determine sign and print daily change. Setw used to format data output
	while (inputFile >> date) {
		cout << setw(12) << date;
		inputFile >> opening;
		cout << setw(12) << opening;
		inputFile >> closing;
		cout << setw(12) << closing << setw(8);
		if (closing > opening)
			cout << "+   " << (closing - opening);
		else if (closing < opening)
			cout << "-   " << (opening - closing);
		else
			cout << "---";
		cout << endl;
		}
}
// Function to calculate the average closing value of the stock by reading in file data via reference
// and returning a double
double CalculateAverageClosingValue(fstream &inputFile) {
	
	// Variables
	string date = "";
	double opening = 0, closing = 0, avgClosing = 0;
	int count = 0;
	
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	getline(inputFile, date); // gets the first line of file - header
	
	// While loop to read in string and two doubles and keep a running total of closing values. Count iterates each loop
	while (inputFile >> date) {
		inputFile >> opening;
		inputFile >> closing;
		avgClosing += closing;
		count++;
	}
	return (avgClosing /= count); // Returns value of average by dividing running total by number of days
}
// Function to calculate up days for stock by using reference to file to read in data and return an integer 
int CalculateUpDayCount(fstream &inputFile) {
	
	// Variables
	string date = "";
	double opening = 0, closing = 0;
	int upDays = 0;
	
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	getline(inputFile, date); // gets the first line of file - header
	
	// While loop to read in string and two doubles and if closing is greater than opening, increment upday count
	while (inputFile >> date) {
		inputFile >> opening;
		inputFile >> closing;
		if (closing > opening)
			upDays++;
	}
	return upDays;
}
// Function to calculate down days for stock by using reference to file to read in data and return an integer 
int CalculateDownDayCount(fstream &inputFile) {
	
	// Variables
	string date = "";
	double opening = 0, closing = 0;
	int downDays = 0;
	
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	getline(inputFile, date); // gets the first line of file - header
	
	// While loop to read in string and two doubles and if closing is less than opening, increment downday count
	while (inputFile >> date) {
		inputFile >> opening;
		inputFile >> closing;
		if (closing < opening)
			downDays++;
	}
	return downDays;
}
// Function to calculate flat days for stock by using reference to file to read in data and return an integer
int CalculateFlatDayCount(fstream &inputFile) {
	
	// Variables
	string date = "";
	double opening = 0, closing = 0;
	int flatDays = 0;
	
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	getline(inputFile, date); // gets the first line of file - header
	
	// While loop to read in string and two doubles and if closing is equal to opening, increment flatday count
	while (inputFile >> date) {
		inputFile >> opening;
		inputFile >> closing;
		if (closing == opening)
			flatDays++;
	}
	return flatDays;
}
// Function to get climb data including longest climb, and the starting and ending date by reading in file by refernce. 
// Nothing is returned, but the three reference variables following file are changed. * Climb data was interpreted as
// a stretch days that had overall growth from opening to close (upday), not close to next day close *
void getClimbData(fstream &inputFile, int &longestClimb, string &startDate, string &endDate) {
	
	// Variables
	string date = "", longStart = "";
	double opening = 0, closing = 0;
	int climb = 0;
	
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	getline(inputFile, date); // gets the first line of file - header
	
	// While loop to read in string and two doubles. Nested if statements used to determine if day is upday which will 
	// increment climb. Otherwise, climb is set to 0. Once climb is 1, meaning upday strench begins, date is captured.
	// Once climb count surpasses longest climb, longest climb count iterates and start and end date are set. 
	while (inputFile >> date) {
		inputFile >> opening;
		inputFile >> closing;
		if (closing >= opening)
			climb++;
		else 
			climb = 0;
		if (climb == 1)
			longStart = date;
		if (climb > longestClimb) {
			longestClimb++;
			startDate = longStart;
			endDate = date;
		}
	}
	
}
// Function to get fall data including longest fall, and the starting and ending date by reading in file by refernce. 
// Nothing is returned, but the three reference variables following file are changed. * Fall data was interpreted as
// a stretch days that had overall decline from opening to close (downday), not close to next day close *
void getFallData(fstream &inputFile, int &longestFall, string &startDate, string &endDate) {
	
	// Variables
	string date = "", longStart = "";
	double opening = 0, closing = 0;
	int climb = 0;
	
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	getline(inputFile, date); // gets the first line of file - header
	
	// While loop to read in string and two doubles. Nested if statements used to determine if day is downday which will 
	// increment climb. Otherwise, climb is set to 0. Once climb is 1, meaning downday strench begins, date is captured.
	// Once climb count surpasses longest fall, longest fall count iterates and start and end date are set. 
	while (inputFile >> date) {
		inputFile >> opening;
		inputFile >> closing;
		if (opening >= closing)
			climb++;
		else 
			climb = 0;
		if (climb == 1)
			longStart = date;
		if (climb > longestFall) {
			longestFall++;
			startDate = longStart;
			endDate = date;
		}
	}
	
}
// Function to get maximum increase in one day, by reading in reference to file, and altering the reference variable
// parameters to provide max amount as double and date as a string. Nothing is returned from the function
void getMaxDayIncrease(fstream &inputFile, double &increaseMax, string &date) {
	
	// Variables
	string dates = "";
	double opening = 0, closing = 0;
	
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	getline(inputFile, date); // gets the first line of file - header
	
	// While loop to read in string and two doubles, then compare close to open differnece and max increase. If greater, that
	// value is set to max increase and date is captured by refernece variable
	while (inputFile >> dates) {
		inputFile >> opening;
		inputFile >> closing;
		if ((closing - opening) > increaseMax) {
			increaseMax = (closing - opening);
			date = dates;
		}
	}
}
// Function to get maximum decrease in one day, by reading in reference to file, and altering the reference variable
// parameters to provide max amount as double and date as a string. Nothing is returned from the function
void getMaxDayDecrease(fstream &inputFile, double &decreaseMax, string &date) {
	
	// Variables
	string dates = "";
	double opening = 0, closing = 0;
	
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	getline(inputFile, date); // gets the first line of file - header
	
	// While loop to read in string and two doubles, then compare close to open differnece and max increase. If less, that
	// value is set to max decrease and date is captured by refernece variable
	while (inputFile >> dates) {
		inputFile >> opening;
		inputFile >> closing;
		if ((closing - opening ) < decreaseMax) {
			decreaseMax = (closing - opening);
			date = dates;
		}
	}
}