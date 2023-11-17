/* Kyle Tranfaglia
 * 12/12/22
 * Homework#13 - Exercise 3
 * Program to use two recursive functions to display two different sequences (Q & D) given the n numbers in the sequence by the user
 */
#include <iostream>

using namespace std;

// Recursion Prototype
long Q(long n);
long D(long n);

int main() {
	
	long n = 0;
	
	cout << "Input n: ";
	cin >> n;
	
	cout << "Q Numbers: ";
	// Loop to start the sequence at 1 and send each incrementing i value as a parameter to the recursive function Q and diaplsy the results
	for (int i = 1; i <= n; i++ ) {
		cout << Q(i) << " ";
	}
	cout << endl << "D Numbers: ";
	// Loop to start the sequence at 1 and send each incrementing i value as a parameter to the recursive function D and diaplsy the results
	for (int i = 1; i <= n; i++ ) {
		cout << D(i) << " "; 
	}
	
	return 0;
}
// Function to use recursion to determine the value of at the n term in the Q sequence
long Q(long n) {
	// Base case statement return 1 if either comparison is true
	if (n == 1 || n == 2) {
		return 1;
	}
	return Q(n - Q(n - 1)) + Q(n - Q(n - 2)); // Recursively calls the Q fucntion using the sequence function which decrements n
}
// Function to use recursion to determine the value of at the n term in the D sequence
long D(long n) {
	// Base case statement return 1 if either comparison is true
	if (n == 1 || n == 2) {
		return 1;
	}
	return  D(D(n - 1)) + D(n - 1 - D(n - 2)); // Recursively calls the D fucntion using the sequence function which decrements n
} 