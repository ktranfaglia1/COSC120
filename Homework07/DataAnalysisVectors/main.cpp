/* Kyle Tranfaglia
 * 10/28/22
 * Homework#7 - Exercise 1
 * This program will take in data from a file, copy the data into an vector, and do some calculations on the data
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Prototypes
double AverageTripLength(const vector<float> &data);
double smallestTripDistance(const vector<float> &data);
double largestTripDistance(const vector<float> &data);
double tripsOverTenMiles(const vector<float> &data);
double tripsUnderQuarterMile(const vector<float> &data);

int main() {
	
	// Variables
	fstream inputFile;
	string fileName = "";
	float dummy = 0;
	vector<float> data;
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("HW07Files/" + fileName, ios::in);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error
	// message will be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	// While loop to read in float value from file and push that value to back of vector, increasing vector size as needed
	// Loop terminates when a float value can no longer be read in from the file
	while (inputFile >> dummy) {
		data.push_back(dummy);
	}
	inputFile.close();
	// Prints all the values returned from the called functions
	cout << "Average trip length: " << AverageTripLength(data) << " Miles" << endl;
	cout << "Smallest trip length: " << smallestTripDistance(data) << " Miles" << endl;
	cout << "Largest trip length: " << largestTripDistance(data) << " Miles" << endl;
	cout << "Number of Trips over 10 miles: " << tripsOverTenMiles(data) << " Trips" << endl;
	cout << "Number of Trips under a quarter miles: " << tripsUnderQuarterMile(data) << " Trips" << endl;
	
	return 0;
}
// Function to get average of trips using for loop to keep a running total and return that value divided by vector size as a double
double AverageTripLength(const vector<float> &data) {
	
	double runningTotal = 0;
	// For loop to go through each index of vector to keep a running total
	for (unsigned int i = 0; i < data.size(); i++)
		runningTotal += data[i];
	
	return runningTotal/data.size();
}
// Fuction to get smallest trip distnace by using a for loop to compare each value in the vector and sets a new smallest
// when the value compared is smaller. When loop finishes, the smallest value is returned
double smallestTripDistance(const vector<float> &data) {
	
	double smallestDistance = data[0];
	// for loop to go through each index of vector and use a nested if statament to determine of value at idex is smallest value
	for (unsigned int i = 0; i < data.size(); i++) {
		if (data[i] < smallestDistance)
			smallestDistance = data[i];
	}
	return smallestDistance;
}
// Fuction to get largest trip distnace by using a for loop to compare each value in the vector and sets a new largest
// when the value compared is larger. When loop finishes, the largest value is returned
double largestTripDistance(const vector<float> &data) {
	
	double largestDistance = data[0];
	// for loop to go through each index of vector and use a nested if statament to determine of value at idex is largest value
	for (unsigned int i = 0; i < data.size(); i++) {
		if (data[i] > largestDistance)
			largestDistance = data[i];
	}
	return largestDistance;
}
// Function to get total number of trips over ten miles. Uses a for loop to compare data in vector to value 10
// and will increment count if true. The count value is then returned
double tripsOverTenMiles(const vector<float> &data) {
	
	double over = 0;
	// for loop to go through each index of vector and use nested if to compare value at index to 10
	for (unsigned int i = 0; i < data.size(); i++) {
		if (data[i] > 10)
			over++;
	}
	return over;
}
// Function to get total number of trips under 0.25 miles. Uses a for loop to compare data in vector to value 0.25
// and will increment count if true. The count value is then returned
double tripsUnderQuarterMile(const vector<float> &data) {
	
	double under = 0;
	// for loop to go through each index of vector and use nested if to compare value at index to 0.25
	for (unsigned int i = 0; i < data.size(); i++) {
		if (data[i] < 0.25)
			under++;
	}
	return under;
}