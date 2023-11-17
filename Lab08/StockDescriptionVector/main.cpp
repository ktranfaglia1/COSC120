/* Kyle Tranfaglia
 * 10/31/22
 * Lab#8
 * This program will ask the user to input a filename on stock data, read in the data,
 * and display a set of descriptive statistics for the stock using vectors
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

// Prototypes
bool LoadData(string fileName, vector<string> &date, vector<double> &opening, vector<double> &closing);
void printStockDataChart(const vector<string> &date, const vector<double> &opening, const vector<double> &closing);
double CalculateAverageClosingValue(const vector<double> &closing);
int CalculateUpDayCount(const vector<double> &opening, const vector<double> &closing);
int CalculateDownDayCount(const vector<double> &opening, const vector<double> &closing);
int CalculateFlatDayCount(const vector<double> &opening, const vector<double> &closing);
void getClimbData(const vector<string> &date, const vector<double> &closing, int &longestClimb, string &startDate, string &endDate);
void getFallData(const vector<string> &date, const vector<double> &closing, int &longestFall, string &startDate, string &endDate);
void getMaxDayIncrease(const vector<string> &date, const vector<double> &opening, const vector<double> &closing, double &increaseMax, string &day);
void getMaxDayDecrease(const vector<string> &date, const vector<double> &opening, const vector<double> &closing, double &decreaseMax, string &day);

int main() {
	
	// Variables
	string fileName = "", startDate = "", endDate = "", day = "";
	int upDays = 0, downDays = 0, flatDays = 0, longestClimb = 1, longestFall = 1;
	double avgClosing = 0, increaseMax = 0, decreaseMax = 0;
	
	// Vectors
	vector<string> date;
	vector<double> opening;
	vector<double> closing;
	
	cout << "Input the fileName: ";
	cin >> fileName;

	// If statement that runs if boolean function returns true, meaning an error occurred opening file so program ends
	if (LoadData(fileName, date, opening, closing)) {
		cerr << "Error opening file.\n";
		return 1;
	}
	// Functions are called and then the return values or altered reference variables are displayed
	cout << setprecision(6) << fixed;
	printStockDataChart(date, opening, closing);
	cout << endl << "Stock Statistics for file " << fileName << endl;
	cout << "=======================================" << endl;
	cout << "Number of days in data set: " << date.size() << endl;
	avgClosing = CalculateAverageClosingValue(closing);
	cout << "Average closing stock price: $" << avgClosing << endl;
	upDays = CalculateUpDayCount(opening, closing);
	cout << "Number of days stock went up: " << upDays << endl;
	downDays = CalculateDownDayCount(opening, closing);
	cout << "Number of days stock went down: " << downDays << endl;
	flatDays = CalculateFlatDayCount(opening, closing);
	cout << "Number of days stock stayed flat: " << flatDays << endl;
	getClimbData(date, closing, longestClimb, startDate, endDate);
	cout << "Longest climb: " << longestClimb + 1 << " days from " << startDate << " to " << endDate << endl;
	getFallData(date, closing, longestFall, startDate, endDate);
	cout << "Longest fall: " << longestFall + 1 << " days from " << startDate << " to " << endDate << endl;
	getMaxDayIncrease(date, opening, closing, increaseMax, day);
	cout << "Largest Day Increase: " << increaseMax << " on " << day << endl;
	getMaxDayDecrease(date, opening, closing, decreaseMax, day);
	cout << "Largest Day Decrease: " << abs(decreaseMax) << " on " << day << endl;
	
	return 0;
}
// boolean function to load data into thre different vectors and return true if file open error. Vectors are then passed by reference
bool LoadData(string fileName, vector<string> &date, vector<double> &opening, vector<double> &closing) {
	
	ifstream inputFile;
	string word = "";
	double price = 0;
	
	inputFile.open("lab08Files/" + fileName);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and function returns true
	if (!inputFile)
		return true;
		
	getline(inputFile, word); // gets the first line of file - header
	
	// For loop to read in string to capture date, set date to date vector at position i, then a nested for loop to read 
	// in  opening and closing price as double, set at position in two seperate vectors and data is pushed back to end of vector,
	// continually increasing the size of the vector if needed
	while (inputFile >> word) {
		date.push_back(word);
		inputFile >> price;
		opening.push_back(price);
		inputFile >> price;
		closing.push_back(price);
	}
	inputFile.close();
	
	return false;
}
// Function to print stock data from file into console while using the information to add daily change for each day.
// Nothing is returned, only printed, read in information from file reference
void printStockDataChart(const vector<string> &date, const vector<double> &opening, const vector<double> &closing) {
	
	cout << setw(9) << "Date" << setw(14) << "Opening" << setw(12) << "Closing" << setw(12) << "Change" << endl;
	cout << setprecision(6) << fixed; // 6 decimal precision
	
	// For loop to go through the string vector and two double vectors to display the data, with a nested if statement
	// to compare closing and opening to determine sign and print daily change. Setw used to format data output
	for (unsigned int i = 0; i < date.size(); i++) {
		cout << setw(12) << date[i];
		cout << setw(12) << opening[i];
		cout << setw(12) << closing[i];
		if (closing[i] > opening[i])
			cout << setw(8) << "+   " << (closing[i] - opening[i]);
		else if (closing[i] < opening[i])
			cout << setw(8) << "-   " << (opening[i] - closing[i]);
		else
			cout << setw(8) << "---";
		cout << endl;
	}
}
// Function to calculate the average closing value of the stock reading vector data via reference and returning a double
double CalculateAverageClosingValue(const vector<double> &closing) {
	
	double sumClosing = 0;
	
	// For loop to go through double vector for closing values to keep a running total. Count iterates each loop
	for (unsigned int i = 0; i < closing.size(); i++)
		sumClosing += closing[i];
		
	return (sumClosing /= closing.size()); // Returns value of average by dividing running total by number of days (vector size)
}
// Function to calculate up days for stock by using reference to vector to go through data and return an integer 
int CalculateUpDayCount(const vector<double> &opening, const vector<double> &closing) {
	
	int upDays = 0;
	
	// For loop to go through two double vectors and if closing is greater than opening, increment upday count
	for (unsigned int i = 0; i < closing.size(); i++) {
		if (closing[i] > opening[i])
			upDays++;
	}
	return upDays;
}
// Function to calculate down days for stock by using reference vector to go through data and return an integer 
int CalculateDownDayCount(const vector<double> &opening, const vector<double> &closing) {
	
	int downDays = 0;
	
	// For loop to go through two double vectors and if closing is less than opening, increment downday count
	for (unsigned int i = 0; i < closing.size(); i++) {
		if (opening[i] > closing[i])
			downDays++;
	}
	return downDays;
}
// Function to calculate flat days for stock by using reference to vectors to go through data and return an integer
int CalculateFlatDayCount(const vector<double> &opening, const vector<double> &closing) {
	
	int flatDays = 0;
	// For loop to go through two double vectors and if closing is equal to opening, increment flatday count
	for (unsigned int i = 0; i < closing.size(); i++) {
		if (closing[i] == opening[i])
			flatDays++;
	}
	return flatDays;
}
// Function to get climb data including longest climb, and the starting and ending date by going through vectors by reference. 
// Nothing is returned, but the three reference variables following file are changed.
void getClimbData(const vector<string> &date, const vector<double> &closing, int &longestClimb, string &startDate, string &endDate) {
	
	int climb = 0;
	
	// For loop to go through the string vector and two double vectors. Nested if statements used to determine if day is more than previous day which will 
	// increment climb. Otherwise, climb is set to 0. Once climb count surpasses longest climb, longest climb count iterates and start and end date are set 
	for (unsigned int i = 0; i < closing.size(); i++) {
		if (closing[i] >= closing[i - 1])
			climb++;
		else 
			climb = 0;
		if (climb > longestClimb) {
			longestClimb++;
			startDate = date[i - longestClimb];
			endDate = date[i];
		}
	}
}
// Function to get fall data including longest fall, and the starting and ending date by going through vectors by reference. 
// Nothing is returned, but the three reference variables following file are changed.
void getFallData(const vector<string> &date, const vector<double> &closing, int &longestFall, string &startDate, string &endDate) {
	
	int climb = 0;
	
	// For loop to go through the string vector and two double vector. Nested if statements used to determine if day less than previous day which will 
	// increment climb. Otherwise, climb is set to 0. Once climb count surpasses longest fall, longest fall count iterates and start and end date are set 
	for (unsigned int i = 0; i < closing.size(); i++) {
		if (closing[i - 1] >= closing[i])
			climb++;
		else 
			climb = 0;
		if (climb > longestFall) {
			longestFall++;
			startDate = date[i - longestFall];
			endDate = date[i];
		}
	}
}
// Function to get maximum increase in one day, by going through vectors by reference, and altering the reference variable
// parameters to provide max amount as double and date as a string. Nothing is returned from the function
void getMaxDayIncrease(const vector<string> &date, const vector<double> &opening, const vector<double> &closing, double &increaseMax, string &day) {
	
	// For loop to go through the string vectors and two double double vectors, then compare close to open differnece and max increase.
	// If greater, that value is set to max increase and date is captured by refernece variable
	for (unsigned int i = 0; i < date.size(); i++) {
		if ((closing[i] - opening[i]) > increaseMax) {
			increaseMax = (closing[i] - opening[i]);
			day = date[i];
		}
	}
}
// Function to get maximum decrease in one day, by by going through vectors by reference, and altering the reference variable
// parameters to provide max amount as double and date as a string. Nothing is returned from the function
void getMaxDayDecrease(const vector<string> &date, const vector<double> &opening, const vector<double> &closing, double &decreaseMax, string &day) {
	
	// For loop to go through the string vector and two double vectors, then compare close to open differnece and max increase. If less, that
	// value is set to max decrease and date is captured by refernece variable
	for (unsigned int i = 0; i < date.size(); i++) {
		if ((closing[i] - opening[i]) < decreaseMax) {
			decreaseMax = (closing[i] - opening[i]);
			day = date[i];
		}
	}
}