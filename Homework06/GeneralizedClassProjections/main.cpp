/* Kyle Tranfaglia
 * 10/24/22
 * Homework#6 - Exercise 2
 * This program will take in information about a class, that is, student’s names, amount of students, amount of exams, points remaining,
 * and exam grades and printout areport of the class including averages and grade projections for the final exam using 4 parallel arrays
 */
#include <iostream>
#include <string>
#include <iomanip>

int main() {
	
	using namespace std;
	
	// Variables
	int students = 0, exams = 0, pointsRemaining = 0, sum = 0;
	double needed = 0.9;
	
	cout << "Input the number of students in the class: ";
	cin >> students;
	
	// Input validation check. Loop runs until input is valid, meaning the comparison is false, and it will terminate
	while (students <= 0) {
		cout << "Invalid input! Number of students must be greater than 0!" << endl;
		cout << "Input the number of students in the class: ";
		cin >> students;
	}
	
	cout << "Input the number of exams: ";
	cin >> exams;
	
	// Input validation check. Loop runs until input is valid, meaning the comparison is false, and it will terminate
	while (exams <= 0) {
		cout << "Invalid input! Number of exams must be greater than 0!" << endl;
		cout << "Input the number of exams: ";
		cin >> exams;
	}
	
	cout << "Input the number of points remainig: ";
	cin >> pointsRemaining;
	
	// Input validation check. Loop runs until input is valid, meaning the comparison is false, and it will terminate
	while (pointsRemaining <= 0) {
		cout << "Invalid input! Number of points remaining must be greater than 0!" << endl;
		cout << "Input the number of points remaining: ";
		cin >> pointsRemaining;
	}
	
	// Arrays
	string names[students];
	float scores[students][exams];
	float average[students];
	float projections[students][exams];
	
	// For loop to populate string array and two-d float array. Populates by assigning user input to index. Nested for loop is to
	// assign the values to rows in all columns by assigning all columns after an outside index (row)
	for (int i = 0; i < students; i++) {
		cout << "Input student " << i + 1 << " name: ";
		cin.get();
		getline(cin, names[i]);
		for (int j = 0; j < exams; j++) {
			cout << "Input Exam " << j + 1 << " score for " << names[i] << ": ";
			cin >> scores[i][j];
		}
	}
	// For loop to populate a float array for averages and a nested for loop to populate two-d array for projections.
	// sum and needed is reset and after every outside iteration for valid projection calculations for each row. 
	for (int i = 0; i < students; i++) {
		sum = 0;
		needed = 0.9;
		for (int j = 0; j < exams; j++) {
			sum += scores[i][j];
		}
		average[i] = ((1.0*sum)/exams);
		for (int k = 0; k < 4; k++) {
			projections[i][k] = (needed*(pointsRemaining + (exams*100))) - (sum);
			needed -= 0.1;
		}
	}
	// Prints formattd output in a chart like style. Line 81 setw equations used to auto adjust format of header (works with exam count 1-9 well)
	cout << endl << setw(27 + (exams*3)) << "Exam Scores" << setw(27 + (exams*4)) << "Projections" << endl;
	cout << setw(17) << "Student's name";
	
	// For loop to display the amount of exams using index as a counter and exams variable to end loop
	for (int i = 0; i < exams; i++) {
		cout << setw(7) << "Exam " << i + 1;
	}
	cout << setw(8) << "Avg." << setw(7) << "A" << setw(8) << "B" << setw(8) << "C" << setw(8) << "D" << endl;
	cout << setprecision(2) << fixed << showpoint;
	
	// For loop to display the name of the student by accessing array at an index, and nested for loop to print
	// scores of students via a two-d parallel array, which prints the column data associated with the student (row index i)
	// Other nested for loop to go through another parallel array and print corresponding data that was calculated previosuly.
	// If else if is then used to compare array at index to literal integer to determine one of three corresponding ouputs 
	for (int i = 0; i < students; i++) {
		cout << setw(17) << names[i];
		for (int j = 0; j < exams; j++) {
			cout << setw(8) << scores[i][j];
		}
		cout << setw(8) << average[i] << "  ";
		for (int k = 0; k < 4; k++) {
			if (projections[i][k] >= 0 && projections[i][k] <= pointsRemaining)
				cout << setw(8) << projections[i][k];
			else if (projections[i][k] < 0)
				cout << setw(8) << "0.00";
			else 
				cout << setw(8) << "NA";
		}
		cout << endl;
	}
	return 0;
}