/* Kyle Tranfaglia
 * 10/10/22
 * Lab#5 - Exercise 3
 * This program will use a function to ask the user for a number and a tolerance and will replace r with the value of 
 * the product of an equation until two consequtive results are within tolerance
 */
#include <iomanip>
#include <iostream>
#include <cmath>

// Prototypes for user input function and equation function
double getDouble (double min, double max);
double squareroot (double n, double tol);

int main()
{
	using namespace std;
	
	// Variables
	double nMin = 0.000000001, nMax = 1000000000, tolMin = 0.000000000001, tolMax = 1;
	double n = 0, tol = 0;
	
	n = getDouble(nMin, nMax); // Calls user input function, sending min and max as doubles for number
	tol = getDouble(tolMin, tolMax); // Calls user input function, sending min and max as doubles for tolerance
	
	cout << setprecision(15); // Sets precision of output to 15 numbers 
	cout << squareroot(n, tol) << endl; // Prints the value of the call to the equation function, sending number and tolerance as doubles 
	
	return 0;
}
// Function to get user input and return it as long as it is within the range. Double parameters sent to function are min
// and max values to accept for input. Function returns user input as a double within the range. 
double getDouble (double min, double max) {
	
	using namespace std;
	
	double value = 0;
	
	cout << "Input a number between " << min << " and " << max << ": ";
	cin >> value;
	
	while (value < min || value > max) {
		cout << "Invalid input!" << endl;
		cout << "Input a number between " << min << " and " << max << ": ";
		cin >> value;
	}
	return value;
}
// Function to apply equation given parameters n and tol as doubles. r is set to 1 and r is changed
// to the value of the function until the difference between r and its last value is within the tolerance
// Function returns the value of r as double once do while loop finishes
double squareroot (double n, double tol) {
	
	double r = 1, r1 = 1, diff = 0;
	
	// Do while loop to run block at least once. Loop sets r1 (last value of r) as r and then
	// chnages value of r with equation and finds the differnce between the values. If the differnce 
	// is greater than the tolerance the loop terminates
	do {
		r1 = r;
		r = (1.0/2.0)*(r+(n/r));
		diff = std::abs(r1-r);
	} while (diff > tol);
	
	return r;
}