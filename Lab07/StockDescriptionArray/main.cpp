/* Kyle Tranfaglia
 * 10/24/22
 * Lab#7
 * This program will ask the user to input a filename on stock data, read in the data,
 * assign it to two arrays and display a set of descriptive statistics for the stock
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

const int COLS = 2;

// Prototypes
int getDayCount(ifstream &inputFile);
void printStockDataChart(const string date[], const double prices[][COLS], int lineCount);
double CalculateAverageClosingValue(const double prices[][COLS], int lineCount);
int CalculateUpDayCount(const double prices[][COLS], int lineCount);
int CalculateDownDayCount(const double prices[][COLS], int lineCount);
int CalculateFlatDayCount(const double prices[][COLS], int lineCount);
void getClimbData(const string date[], const double prices[][COLS], int lineCount, int &longestClimb, string &startDate, string &endDate);
void getFallData(const string date[], const double prices[][COLS], int lineCount, int &longestFall, string &startDate, string &endDate);
void getMaxDayIncrease(const string date[], const double prices[][COLS], int lineCount, double &increaseMax, string &day);
void getMaxDayDecrease(const string date[], const double prices[][COLS], int lineCount, double &decreaseMax, string &day);

int main() {
	
	// Variables
	ifstream inputFile;
	string fileName = "", word = "", startDate = "", endDate = "", day = "";
	int upDays = 0, downDays = 0, flatDays = 0, longestClimb = 1, longestFall = 1, lineCount = 0;
	double avgClosing = 0, increaseMax = 0, decreaseMax = 0, price = 0;
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("lab07Files/" + fileName);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error
	// message will be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	lineCount = getDayCount(inputFile);
	
	string date[lineCount];
	double prices[lineCount][COLS];

	getline(inputFile, word); // gets the first line of file - header
	
	// For loop to to read in string to capture date, set date to date array at position i, then a nested for loop
	// to read in price as double, and set it at postion in two-d array. Loop iterates twice to capture opening and closing
	for (int i = 0; i < lineCount; i++) {
		inputFile >> word;
		date[i] = word;
		for (int j = 0; j < COLS; j++) {
			inputFile >> price;
			prices[i][j] = price;
		}
	}
	inputFile.close();
	// Functions are called and then the return values or altered reference variables are displayed
	cout << setprecision(6) << fixed;
	printStockDataChart(date, prices, lineCount);
	cout << endl << "Stock Statistics for file " << fileName << endl;
	cout << "=======================================" << endl;
	cout << "Number of days in data set: " << lineCount << endl;
	avgClosing = CalculateAverageClosingValue(prices, lineCount);
	cout << "Average closing stock price: $" << avgClosing << endl;
	upDays = CalculateUpDayCount(prices, lineCount);
	cout << "Number of days stock went up: " << upDays << endl;
	downDays = CalculateDownDayCount(prices, lineCount);
	cout << "Number of days stock went down: " << downDays << endl;
	flatDays = CalculateFlatDayCount(prices, lineCount);
	cout << "Number of days stock stayed flat: " << flatDays << endl;
	getClimbData(date, prices, lineCount, longestClimb, startDate, endDate);
	cout << "Longest climb: " << longestClimb << " days from " << startDate << " to " << endDate << endl;
	getFallData(date, prices, lineCount, longestFall, startDate, endDate);
	cout << "Longest fall: " << longestFall << " days from " << startDate << " to " << endDate << endl;
	getMaxDayIncrease(date, prices, lineCount, increaseMax, day);
	cout << "Largest Day Increase: " << increaseMax << " on " << day << endl;
	getMaxDayDecrease(date, prices, lineCount, decreaseMax, day);
	cout << "Largest Day Decrease: " << abs(decreaseMax) << " on " << day << endl;
	
	return 0;
}
// Function to get number of days listed in file, taking in reference to opened file and returns integer value
int getDayCount(ifstream &inputFile) {
	
	// Variables
	string line = "";
	long lineCount = 0;
	
	getline(inputFile, line); // gets the first line of file - header
	
	// Reads in file line by line and if read is successful, linecount increments. Loop terminates when pointer
	// hits EOF, meaning no more lines can be read in
	while (getline(inputFile, line)) {
			lineCount++;
		}
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	
	return lineCount;
}
// Function to print stock data from file into console while using the information to add daily change for each day.
// Nothing is returned, only printed given read in information from file reference
void printStockDataChart(const string date[], const double prices[][COLS], int lineCount) {
	
	cout << setw(9) << "Date" << setw(14) << "Opening" << setw(12) << "Closing" << setw(12) << "Change" << endl;
	cout << setprecision(6) << fixed; // 6 decimal precision
	
	// For loop to go through the string array and two-d double array to display the data, with a nested if statement
	// to compare closing and opening to determine sign and print daily change. Setw used to format data output
	for (int i = 0; i < lineCount; i++) {
		cout << setw(12) << date[i];
		for (int j = 0; j < COLS; j++)
			cout << setw(12) << prices[i][j];
		if (prices[i][1] > prices[i][0])
			cout << setw(8) << "+   " << (prices[i][1] - prices[i][0]);
		else if (prices[i][1] < prices[i][0])
			cout << setw(8) << "-   " << (prices[i][0] - prices[i][1]);
		else
			cout << setw(8) << "---";
		cout << endl;
	}
}
// Function to calculate the average closing value of the stock reading array data via reference
// and returning a double
double CalculateAverageClosingValue(const double prices[][COLS], int lineCount) {
	
	double sumClosing = 0;
	int count = 0;
	
	// For loop to go through two-d double array to keep a running total of closing values. Count iterates each loop
	for (int i = 0; i < lineCount; i++) {
		sumClosing += prices[i][1];
		count++;
	}
	return (sumClosing /= count); // Returns value of average by dividing running total by number of days
}
// Function to calculate up days for stock by using reference to array to go through data and return an integer 
int CalculateUpDayCount(const double prices[][COLS], int lineCount) {
	
	int upDays = 0;
	
	// For loop to go through two-d array and if closing is greater than opening, increment upday count
	for (int i = 0; i < lineCount; i++) {
		if (prices[i][1] > prices[i][0])
			upDays++;
	}
	return upDays;
}
// Function to calculate down days for stock by using reference array to go through data and return an integer 
int CalculateDownDayCount(const double prices[][COLS], int lineCount) {
	
	int downDays = 0;
	
	// For loop to go through two-d array and if closing is less than opening, increment downday count
	for (int i = 0; i < lineCount; i++) {
		if (prices[i][0] > prices[i][1])
			downDays++;
	}
	return downDays;
}
// Function to calculate flat days for stock by using reference to array to go through data and return an integer
int CalculateFlatDayCount(const double prices[][COLS], int lineCount) {
	
	int flatDays = 0;
	// For loop to go through two-d array and if closing is equal to opening, increment flatday count
	for (int i = 0; i < lineCount; i++) {
		if (prices[i][1] == prices[i][0])
			flatDays++;
	}
	return flatDays;
}
// Function to get climb data including longest climb, and the starting and ending date by going through array by reference. 
// Nothing is returned, but the three reference variables following file are changed.
void getClimbData(const string date[], const double prices[][COLS], int lineCount, int &longestClimb, string &startDate, string &endDate) {
	
	int climb = 1;
	
	// For loop to go through the string array and two-d double array. Nested if statements used to determine if day is more than previous day which will 
	// increment climb. Otherwise, climb is set to 1. Once climb count surpasses longest climb, longest climb count iterates and start and end date are set 
	for (int i = 1; i < lineCount; i++) {
		if (prices[i][1] >= prices[i - 1][1])
			climb++;
		else 
			climb = 1;
		if (climb > longestClimb) {
			longestClimb++;
			startDate = date[i - longestClimb + 1];
			endDate = date[i];
		}
	}
	
}
// Function to get fall data including longest fall, and the starting and ending date by going through array by reference. 
// Nothing is returned, but the three reference variables following file are changed.
void getFallData(const string date[], const double prices[][COLS], int lineCount, int &longestFall, string &startDate, string &endDate) {
	
	int climb = 1;
	
	// For loop to go through the string array and two-d double array. Nested if statements used to determine if day less than previous day which will 
	// increment climb. Otherwise, climb is set to 0. Once climb count surpasses longest fall, longest fall count iterates and start and end date are set 
	for (int i = 1; i < lineCount; i++) {
		if (prices[i - 1][1] >= prices[i][1])
			climb++;
		else 
			climb = 1;
		if (climb > longestFall) {
			longestFall++;
			startDate = date[i - longestFall + 1];
			endDate = date[i];
		}
	}
	
}
// Function to get maximum increase in one day, by going through array by reference, and altering the reference variable
// parameters to provide max amount as double and date as a string. Nothing is returned from the function
void getMaxDayIncrease(const string date[], const double prices[][COLS], int lineCount, double &increaseMax, string &day) {
	
	// For loop to go through the string array and two-d double array, then compare close to open differnece and max increase. If greater, that
	// value is set to max increase and date is captured by refernece variable
	for (int i = 0; i < lineCount; i++) {
		if ((prices[i][1] - prices[i][0]) > increaseMax) {
			increaseMax = (prices[i][1] - prices[i][0]);
			day = date[i];
		}
	}
}
// Function to get maximum decrease in one day, by by going through array by reference, and altering the reference variable
// parameters to provide max amount as double and date as a string. Nothing is returned from the function
void getMaxDayDecrease(const string date[], const double prices[][COLS], int lineCount, double &decreaseMax, string &day) {
	
	// For loop to go through the string array and two-d double array, then compare close to open differnece and max increase. If less, that
	// value is set to max decrease and date is captured by refernece variable
	for (int i = 0; i < lineCount; i++) {
		if ((prices[i][1] - prices[i][0]) < decreaseMax) {
			decreaseMax = (prices[i][1] - prices[i][0]);
			day = date[i];
		}
	}
}