/* Kyle Tranfaglia
 * 09/23/22
 * Homework#2 - Exercise 5
 * This program asks the user for a number and a tolerance and will replace r with the value of 
 * the product of an equation until two consequtive results are within tolerance
 */
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    using namespace std;

    // Variables
	double n = 0, r = 1, r1 = 1, tol = 0, diff = 0;
	
	cout << "Input a number (>= 0): ";
	cin >> n;
	
	// Invalid input check. Loop runs if the user input is less than 0. An error message will appear
    // and the user will be instructed to enter a value again. This continues until a suitable input is read
	while (n < 0) {
		cout << "Invalid input, please input a number >= 0\n";
		cout << "Input a number (>= 0): ";
		cin >> n;
	}
	cout << "Input a tolerance (> 0): ";
	cin >> tol;
	
	// Invalid input check. Loop runs if the user input is not greater than 0. An error message will appear
    // and the user will be instructed to enter a value again. This continues until a suitable input is read
	while (tol <= 0) {
		cout << "Invalid input, please input a number > 0\n";
		cout << "Input a tolerance (> 0): ";
		cin >> tol;
	}
	// loop runs a minimum of one time and then the loop will keep runnig if difference is greater than 
	// the tolerance. r1 is used to hold the last calculated r value as r is then replaced with the 
	// value of the function of r. The difference is then calculated as abs, and compared to tolerance
	do {
		r1 = r;
		r = (1.0/2.0)*(r+(n/r));
		diff = abs(r1-r);
	} while (diff > tol);
	
	cout << setprecision(14) << fixed;
	cout << r << endl;
	
	return 0;
}