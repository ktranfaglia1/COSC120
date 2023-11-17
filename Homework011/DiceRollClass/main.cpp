/* Kyle Tranfaglia
 * 11/17/22
 * Homework#11 - Exercise 2
 * This program creates a class that acts like an STL vector and rolls two dice per user 
 * selected times and displays number of each roll sum and the probabilities of that sum
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "IntList.h"

using namespace std;

// Prototypes
void CountRolls(IntList&, IntList&);
void printCount(IntList&);
void printProbability(IntList&, int rolls);

int main() {
	
	srand(time(0));
	// Variables
	IntList list1, list2;
	int rollSum = 0, rolls = 0;
	
	cout << "Input the number of rolls: ";
	cin >> rolls;
	// While loop for input validation to make sure that the roll amount is not negative
	while (rolls <= 0) {
		cout << "Invalid input! Please enter an integer value greater than 0";
		cout << "Input the number of rolls: ";
		cin >> rolls;
	}
	cout << endl;
	// For loop to get a sum of two dice rolls and then push that value to the back of an array
	for (int i = 0; i < rolls; i++) {
		rollSum = (rand() % 6 + 1) + (rand() % 6 + 1);
		list1.push_back(rollSum);
	}
	// For loop to create an array of ten with the pushback function and assign 0 to each index
	for (int i = 0; i <= 10; i++) {
		list2.push_back(0);
	}
	CountRolls(list1, list2);
	printCount(list2);
	printProbability(list2, rolls);
	
	return 0;
}
// Function to count the number of each sum of rolls and increment the corresponding index for that count in another list
void CountRolls(IntList& list1, IntList& list2) {
	int value = 0, increment = 0;
	// For loop to get value at list1 at index i minus two to put it in terms of an array of 10 (dice sum values 2-12), get the 
	// value of list2 at index of value, increment that value, and then set the value at that index of the array
	for (int i = 0; i < list1.get_size(); i++) {
		value = list1.get(i) - 2;
		increment = list2.get(value) + 1;
		list2.set(value, increment);
	}
}
// Function to print the elements in an array accessed by a reference to a class containing the integer pointer
void printCount(IntList &list) {
	cout << "Counts" << endl << "------" << endl;
	// For loop to print array elements from the first index until the last index by dereferencing a pointer
	for (int i = 0; i < list.get_size(); i++) {
		cout << i + 2 << ": " << list.get(i) << endl;
	}
	cout << endl;
}
// Function to print the elements in an array accessed by a reference to a class containing the integer pointer
void printProbability(IntList &list, int rolls) {
	cout << "Probabilities" << endl << "-------------" << endl;
	// For loop to print array elements from the first index until the last index by dereferencing a pointer
	for (int i = 0; i < list.get_size(); i++) {
		cout << i + 2 << ": " << list.get(i) / (rolls*1.0) << endl;
	}
	cout << endl;
}