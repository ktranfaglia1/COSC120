/* Kyle Tranfaglia
 * 10/24/22
 * Homework#6 - Exercise 1
 * This program will take in information about a class, that is, student’s names and exam grades and printout a
 * report of the class including averages and grade projections for the final exam using 4 parallel arrays
 */
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int COLS = 4; // Global constant to set columns in two-d array

// Prototypes
void PopulateArrays(string names[], float scores[][COLS], int students);
void CalculationsPopulateArrays(const float scores[][COLS], int students, float average[], float projections[][COLS]);

int main() {
	
	// Variables
	int students = 0;
	
	cout << "Input the number of students in the class: ";
	cin >> students;
	
	// Input validation check. Loop runs until input is valid, meaning the comparison is false, and it will terminate
	while (students <= 0) {
		cout << "Invalid input! Number of students must be greater than 0!" << endl;
		cout << "Input the number of students in the class: ";
		cin >> students;
	}
	// Arrays
	string names[students];
	float scores[students][COLS];
	float average[students];
	float projections[students][COLS];
	
	PopulateArrays(names, scores, students); // Call to function to populate arrays
	CalculationsPopulateArrays(scores, students, average, projections); // Call to function to do some calculations and populate more arrays
	
	// Prints formattd output in a chart like style
	cout << endl << setw(45) << "Exam Scores" << setw(50) << "Projections" << endl;
	cout << setw(18) << "Student's name" << setw(10) << "Exam 1" << setw(10) << "Exam 2" << setw(10) << "Exam 3";
	cout << setw(10) << "Exam 4" << setw(10) << "Avg." << setw(7) << "A" << setw(10) << "B"; 
	cout << setw(10) << "C" << setw(10) << "D" << endl;
	cout << setprecision(2) << fixed << showpoint; // Sets decimal precision to two with trailing zeros
	
	// For loop to display the name of the student by accessing array at an index, and nested for loop to print
	// scores of students via a two-d parallel array, which prints the column data associated with the student (row index i)
	// Other nested for loop to go through another parallel array and print corresponding data that was calculated previosuly.
	// If else if is then used to compare array at index to literal integer to determine one of three corresponding ouputs 
	for (int i = 0; i < students; i++) {
		cout << setw(18) << names[i];
		for (int j = 0; j < COLS; j++) {
			cout << setw(10) << scores[i][j];
		}
		cout << setw(10) << average[i];
		for (int k = 0; k < COLS; k++) {
			if (projections[i][k] >= 0 && projections[i][k] <= 200)
				cout << setw(10) << projections[i][k];
			else if (projections[i][k] < 0)
				cout << setw(10) << "0.00";
			else 
				cout << setw(10) << "NA";
		}
		cout << endl;
	}
	return 0;
}
// Function to populate arrays using a for loop to get input and assign it to index. No retrun value, only alters reference to arrays
void PopulateArrays(string names[], float scores[][COLS], int students) {
	
	// For loop to populate string array and two-d float array. Populates by assigning user input to index. Nested for loop is to
	// assign the values to rows in all columns by assigning all columns after an outside index (row)
	for (int i = 0; i < students; i++) {
		cout << "Input student " << i + 1 << " name: ";
		cin.get();
		getline(cin, names[i]);
		for (int j = 0; j < COLS; j++) {
			cout << "Input Exam " << j + 1 << " score for " << names[i] << ": ";
			cin >> scores[i][j];
		}
	}
}
// Function to do some calculations and place the values at the corresponding index to parallel arrays. Nothing is returned
void CalculationsPopulateArrays(const float scores[][COLS], int students, float average[], float projections[][COLS]) {

	int sum = 0;
	double needed = 0.9; // Minimum to get A, which will be decremented by 0.1 in function each iteration
	
	// For loop to populate a float array for averages and a nested for loop to populate two-d array for projections.
	// sum and needed is reset and after every outside iteration for valid projection calculations for each row. 
	for (int i = 0; i < students; i++) {
		sum = 0;
		needed = 0.9;
		for (int j = 0; j < COLS; j++) {
			sum += scores[i][j];
			projections[i][j] = (needed*600) - (scores[i][0] + scores[i][1] + scores[i][2] + scores[i][3]);
			needed -= 0.1;
		}
		average[i] = (sum/4.0);
	}
}