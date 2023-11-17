/* Kyle Tranfaglia
 * 12/12/22
 * Homework#13 - Exercise 1
 * Program to use a recursive function and accept an n value and k value from the user to display the value of n choose k uisng Pascals triangle
 */
#include <iostream>

using namespace std;

// Recursion Prototype
long comb(long n, long k);

int main() {
	// Variables
	long n = 0, k = 0, answer = 0;
	
	cout << "Enter n and k (integer) with a space between them: ";
	cin >> n;
	cin >> k;
	
	answer = comb(n, k); // Calls recursive function and assigns value to answer variable
	
	cout << n << " Choose " << k << " = " << answer << endl;
	
	return 0;
}
// Recursive function to to get the value of n choose k by calling itself until it solves for the nth row kth column 
long comb(long n, long k) {
	// Base case to stop recursion that will return zero if any of the conditions are true
	if (n < 0 || k < 0 || k > n) {
		return 0;
	}
	// Another base case to stop recursion that will return one if any of the conditions are true
	else if (n == 0 || k == 0 || n == k) {
		return 1;
	}
	return (comb(n - 1, k) + comb(n - 1, k - 1)); // Recursive step
}