/* Kyle Tranfaglia
 * 10/10/22
 * Lab#5 - Exercise 2
 * This program will use a function to generate the 3n + 1 sequence and print it to the screen along
 * with the length of the sequence
 */
#include <iostream>

// prototypes for user input function and sequential equation function
int nifty (int n);
int getInt (int min, int max);

int main()
{
	using namespace std;
	
	// Variables
	int n = 0, min = 2, max = 1000000, count = 1;
	
	n = getInt(min, max); // Call to user input function, sending min and max as ints
	
	cout << "Sequence: " << n << "  ";
	
	// While loop runs if user input is not one and will continue calling the sequential equation function 
	// to chnage the user input value n accordingly until the value is one. Count variable tracks iterations
	while (n != 1) {
		n = nifty(n); // Calls sequential equation function, number as int
		cout << n << "  ";
		count++;
	}
	cout << endl << "Number of integers in list = " << count << endl;
	
	return 0;
}
// Function to get user input and return it as long as it is within the range. Int parameters sent to function are min
// and max values to accept for input. Function returns user input as an integer within the range. 
int getInt (int min, int max) {
	
	using namespace std;
	
	int n = 0;
	
	cout << "Input an integer between 2 and 1000000: ";
	cin >> n;
	
	// Bound check. If user input is not in range, loop runs until user input is valid. Loop skipped if input within range
	while (n < 2 || n > 1000000) {
		cout << "Invalid input!" << endl;
		cout << "Input an integer between 2 and 1000000: ";
		cin >> n;
	}
	return n;
}
// Function that applies sequential equation determined by if statement, and takes in integer n (user input)
// as a parameter and returns an integer  
int nifty (int n) {
	
	// If statement to determine which equation to use. If odd, first equation is used. If even, divide by two
	if (n % 2 == 1)
		n = 3*(n) + 1;
	else
		n /= 2;
		
	return n;
}