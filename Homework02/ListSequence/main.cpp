/* Kyle Tranfaglia
 * 09/23/22
 * Homework#2 - Exercise 4
 * This program asks the user for an integer and then performs a 3n + 1 sequence
 * until it reaches 1 and then the total numbers in the list are displayed
 */
#include <iostream>

int main()
{
    using namespace std;

    // Variables
    int num = 0, list = 1;

    cout << "Enter an integer (> 1): ";
    cin >> num;
	
	// Input validation loop. If num is not more than 1, the loop runs until the new input is within the range
    while (num <= 1) {
		cout << "Invalid input, please input a number > 1\n";
		cout << "Enter an integer (> 1): ";
		cin >> num;
    }
	cout << num;
	
	// This loop runs until num contains 1. This loop runs at least once. After every loop, list is 
	// incremented by one to keep track of how many numbers are in teh created list. The if statement within
	// is used to determine which equation to use. If the num % 2 has a remainder, it is an odd 
	// number and its corresponding equation is used. Otherwise, the else statment equation is used.
	do {
		list++;
		
		if ((num % 2) == 1)
			num = (3*num) + 1;
		else
			num /= 2;
			
		cout << " " << num;
		
	} while (num != 1);
	
	cout << endl;
	cout << "Number of integers in list = " << list << endl;
		
	return 0;
}