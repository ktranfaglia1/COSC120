/* Kyle Tranfaglia
 * 10/20/22
 * Homework#5 - Exercise 1
 * This program will ask the user for the number of rolls in the simulation and the number of sides to the dice. Then,
 * it will create the array, populate it with the entire simulation, find the number of each roll in the simulation, the
 * longest run length of each roll, and the number of straights
 */
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//Prototypes
int dieRoll(int diesides);
int getPositiveInteger(string str);
void PopulateArray(int A[], int size, int diesides);
int countValues(const int A[], int size, int value);
int MaxRunOf(const int A[],int size, int value);
int countStraights(const int A[], int size, int diesides);

int main() {
	
    srand(time(0));
	
	// Variables
    int size = getPositiveInteger("Input the number of rolls on the simulation: ");
    int diesides = getPositiveInteger("Input the number of sides to the die: ");
    int A[size];
	
    PopulateArray(A, size, diesides);
	
	// For loop to call function to count values of each die roll and print out the value
    for (int i = 1; i <= diesides; i++)
		cout << "Count of " << i << ": " << countValues(A, size, i) << endl;
		
	// For loop to call function to find the max run of each die roll and print out the value
    for (int i = 1; i <= diesides; i++)
		cout << "Max run of " << i << ": " << MaxRunOf(A, size, i) << endl;
		
    cout << "Count of Straights: " << countStraights(A, size, diesides) << endl;
	
    return 0;
}
// Function to roll a die between 1 and user entered number once when called, then returns the value as an integer
int dieRoll(int diesides) {
	
	return (rand() % diesides + 1);
}
// Function to ask the user for an integer value greater than 0 and returns the input when valid
int getPositiveInteger(string str) {
	
	int value = 0;
	
	cout << str;
	cin >> value;
	
	while (value <= 0) {
		cout << "Invalid input. Input must be an integer greater than 0" << endl;
		cout << str;
		cin >> value;
	}
	return value;
}
// Function to populate the array using a for loop to put a random number using function call in each slot 
void PopulateArray(int A[], int size, int diesides) {
	
	for (int i = 0; i < size; i++)
		A[i] = dieRoll(diesides);
}
// Function to count the number of times a face value was rolled by using a for loop to compare array value to face value
// then increment a count and return that value when the loop finishes
int countValues(const int A[], int size, int value) {
	
	int count = 0;
	
	for (int i = 0; i < size; i++) {
		if (A[i] == value)
			count++;
	}
	return count;
}
// Function to return max run of a roll by using for loop to go through the entire array and using nested if statements
// to determine if the value is consequtively rolled and if that stretch is greater than any other run of that value
int MaxRunOf(const int A[], int size, int value) {
	
	int count = 0, maxRun = 0;
	
	for (int i = 0; i < size; i++) {
		if (A[i] == value)
			count++;
		else 
			count = 0;
		if (count > maxRun)
			maxRun++;
	}
	return maxRun;
}
// Function to return integer count of straights by using a for loop to go through array and using nested if statements to determine
// if the array value is equal to count and if count is then greater than diesides, meaning a straight has occured. Else statement
// is used to reset count and use the array value still if it is a 1, which is the beginning of a straight
int countStraights(const int A[], int size, int diesides) {
	
	int count = 1, straights = 0;
	
	for (int i = 0; i < size; i++) {
		if (A[i] == count++) {
			if (count > diesides)
				straights++;
		}
		else {
			count = 1;
			if (A[i] == count) 
				count++;
		}
	}
	return straights;
}