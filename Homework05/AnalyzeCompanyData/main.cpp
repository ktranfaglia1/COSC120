/* Kyle Tranfaglia
 * 10/20/22
 * Homework#5 - Exercise 2
 * This program will take in data from a file, copy the data into an array, and do some calculations on the data
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Prototypes
double sumTripLength(const float data[], int size);
double smallestTripDistance(const float data[], int size);
double largestTripDistance(const float data[], int size);
double tripsOverTenMiles(const float data[], int size);
double tripsUnderQuarterMile(const float data[], int size);

int main() {
	
	// Variables
	fstream inputFile;
	string fileName = "";
	int over = 0, under = 0, lines = 0;
	float dummy = 0, largest = 0, smallest = 0;
	double sum = 0;
	bool firstTime = true;
	float data[100000] = {0};
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("HW05Files/" + fileName, ios::in);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the comparison is true and an error
	// message will be displayed and the program will abruptly terminate
	if (!inputFile) {
		cerr << "Error opening file.\n";
		return 1;
	}
	// While loop to read in a word from file and increment count until it can no longer read in a string
	while (inputFile >> dummy)
		lines++;
	
	// Resets pointer
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	
	// While loop to check if pointer is at end of file. If not, size is initialized and a for loop runs that 
	// reads in 100000 words of data and store it into an array, largest and smallest are initialized once,
	// and then the array is used and cleared and the process repeats until nothing more can be read in
	while (inputFile.peek() != EOF) {
		int size = 0;
		for (int i = 0; i < 100000; i++) {
			if (inputFile.peek() != EOF) {
				inputFile >> dummy;
				data[i] = dummy;
				size++;
				if (firstTime) {
					largest = smallest = data[i];
					firstTime = false;
				}
			}
			else
				i = 100000;
		}
		sum += sumTripLength(data, size);
		if (smallest > smallestTripDistance(data, size)) // Tests if return value is smaller than previous smallest
			smallest = smallestTripDistance(data, size);
		if (largest < largestTripDistance(data, size)) // Tests if return value is larger than previous largest
			largest = largestTripDistance(data, size);
		over += tripsOverTenMiles(data, size);
		under += tripsUnderQuarterMile(data, size);
	}
	// Prints data
	cout << "Average trip length: " << (sum/lines) << " Miles" << endl;
	cout << "Smallest trip length: " << smallest << " Miles" << endl;
	cout << "Largest trip length: " << largest << " Miles" << endl;
	cout << "Number of Trips over 10 miles: " << over << " Trips" << endl;
	cout << "Number of Trips under a quarter miles: " << under << " Trips" << endl;
	
	return 0;
}
// Function to get sum of trips using for loop to keep a running total and return it as a double
double sumTripLength(const float data[], int size) {
	
	double runningTotal = 0;
	
	for (int i = 0; i < size; i++)
		runningTotal += data[i];
	
	return runningTotal;
}
// Fuction to get smallest trip distnace by using a for loop to compare each value in the array and sets a new smallest
// when the value compared is smaller. When loop finishes, the smallest value is returned
double smallestTripDistance(const float data[], int size) {
	
	double smallestDistance = data[0];
	
	for (int i = 0; i < size; i++) {
		if (data[i] < smallestDistance)
			smallestDistance = data[i];
	}
	return smallestDistance;
}
// Fuction to get largest trip distnace by using a for loop to compare each value in the array and sets a new largest
// when the value compared is larger. When loop finishes, the largest value is returned
double largestTripDistance(const float data[], int size) {
	
	double largestDistance = data[0];
	
	for (int i = 0; i < size; i++) {
		if (data[i] > largestDistance)
			largestDistance = data[i];
	}
	return largestDistance;
}
// Function to get total number of trips over ten miles. Uses a for loop to compare data in array to value 10
// and will increment count if true. The count value is then returned
double tripsOverTenMiles(const float data[], int size) {
	
	double over = 0;
	
	for (int i = 0; i < size; i++) {
		if (data[i] > 10)
			over++;
	}
	return over;
}
// Function to get total number of trips under 0.25 miles. Uses a for loop to compare data in array to value 0.25
// and will increment count if true. The count value is then returned
double tripsUnderQuarterMile(const float data[], int size) {
	
	double under = 0;
	
	for (int i = 0; i < size; i++) {
		if (data[i] < 0.25)
			under++;
	}
	return under;
}