/* Kyle Tranfaglia
 * 10/28/22
 * Homework#7 - Exercise 2
 * This program will take in data from a file, copy the data into an vector, and do some calculations on the data
 */
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int COLS = 30, ROWS = 15; // Global constant for array size

// Prototypes
bool PopulatePricesArray(int prices[], fstream &file);
bool PopulateSeatsArray(char seats[][COLS], fstream &file);
int DisplayMenu();
void DisplaySeating(const char seats[][COLS]);
void UpdateSeatsFile(char seats[][COLS], fstream &file);
void CalculateTicketsAndRevenue(const char seats[][COLS], const int prices[], int &tickets, int &totalRevenue);
void ClearTheater(char seats[][COLS]);
void PurchaseTicket(char seats[][COLS], const int prices[]);
void PurchaseBlock(char seats[][COLS], const int prices[]);

int main () {
	
	// variables
	fstream file;
	int input = 0, tickets = 0, totalRevenue = 0;
	int prices[ROWS];
	char seats[ROWS][COLS];
	
	// If statement to call functions to populate arrays and return 1 if for some reason the file does not open
	if (PopulatePricesArray(prices, file) || PopulateSeatsArray(seats, file))
		return 1;
	
	DisplaySeating(seats);
	
	// While loop for user navigation in program. Loop runs as long as value returned from function is not 0. 
	// Nested if, else if statements are used to compare returned value and use a function to change array or
	// do a calculation as needed. Updated seating is displayed after each iteration.
	while ((input = DisplayMenu()) != 0) {
		if (input == 1) {
			PurchaseTicket(seats, prices);
		}
		else if (input == 2) {
			PurchaseBlock(seats, prices);
		}
		else if (input == 3) {
			CalculateTicketsAndRevenue(seats, prices, tickets, totalRevenue);
			cout << "Total Tickets: " << tickets << " Tickets, " << (tickets/4.5) << "%" << endl;
			cout << "Total Revenue: $" << totalRevenue << endl;
		}
		else if (input == 4) {
			CalculateTicketsAndRevenue(seats, prices, tickets, totalRevenue);
			cout << "Total Available Tickets: " << (450 - tickets) << " Tickets, " << (100 - (tickets/4.5)) << "%" << endl;
			cout << "Total Available Revenue: $" << (14130 - totalRevenue) << endl;
		}
		else if (input == 8) {
			ClearTheater(seats);
		}
		else 
			cout << "invalid input. Please eneter a valid number choice from the menu" << endl;
		
		cout << endl;
		DisplaySeating(seats);
	}
	UpdateSeatsFile(seats, file);
	
	return 0;
}
// Function to open prices.txt file and populate prices array and return false if it was a success
bool PopulatePricesArray(int prices[], fstream &file) {
	
	int dummy = 0;
	
	file.open("HW07Files/prices.txt", ios::in);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the function returns true
	if (!file) {
		cerr << "Error opening file: prices.txt";
		return true;
	}
	// For loop to populate prices array. reads in integer value from file and assignes it to array at index
	for (int i = 0; i < ROWS; i++) {
		file >> dummy;
		prices[i] = dummy;
	}
	file.close();
	
	return false;
}
// Function to open seats.txt file and populate seats array and return false if it was a success
bool PopulateSeatsArray(char seats[][COLS], fstream &file) {
	
	char dummy = ' ';
	
	file.open("HW07Files/seats.txt", ios::in);
	
	// If statement is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code within the if statemnt. If there is a problem opening the file, the function returns true
	if (!file) {
		cerr << "Error opening file: seats.txt";
		return true;
	}
	// For loop with nested for loop to populate two-d seats array. Reads in a character from file and assignes it to array at index
	for (int i = 0; i < ROWS; i++) {
		for (int k = 0; k < COLS; k++) {
			file >> dummy;
			seats[i][k] = dummy;
		}
	}
	file.close();
	
	return false;
}
// Function to display the menu for user selection. Returns the integer the user entered
int DisplayMenu() {
	
	int choice = 0;
	
	cout << "\n1. Purchase Ticket\n" << "2. Purchase Block of Tickets\n" << "3. Total Sold\n";
	cout << "4. Total Available\n" << "8. Clear Theater\n" << "0. Quit\n" << endl;
	cout << "Selection: ";
	cin >> choice;
	
	return choice;
}
// Function display the seating of the theater, updated with open and sold seats
void DisplaySeating(const char seats[][COLS]) {
	
	cout << "                   Seats" << endl << "        123456789012345678901234567890" << endl;
	
	// For loop to display the characters held in each index of seats array in a formatted table
	for (int i = 0; i < ROWS; i++) {
		cout << "Row " << left << setw(4) << (i + 1);
		for (int k = 0; k < COLS; k++) {
			cout << seats[i][k];
		}
		cout << endl;
	}
}
// Function to update the seating status after the user has selected to end the program by opening seats.txt and outputing seats array
void UpdateSeatsFile(char seats[][COLS], fstream &file) {
	
	file.open("HW07Files/seats.txt", ios::out);
	
	// For loop to write each character of seats array into the seats.txt file by writing value at index for each iteartion 
	for (int i = 0; i < ROWS; i++) {
		file << endl;
		for (int k = 0; k < COLS; k++) {
			file << seats[i][k];
		}
	}
	file.close();
}
// Function to calculate the tickets sold and revenue and update reference variables for each
void CalculateTicketsAndRevenue(const char seats[][COLS], const int prices[], int &tickets, int &totalRevenue) {
	
	totalRevenue = 0; // resets variables each call of function
	tickets = 0;
	
	// For loop to iterate ticket count if character at array index is '#" and also keep running total using price index
	for (int i = 0; i < ROWS; i++) {
		for (int k = 0; k < COLS; k++) {
			if (seats[i][k] == '#') {
				tickets++;
				totalRevenue += prices[i];
			}
		}
	}
}
// Function to clear the theatre, meaning all seats open
void ClearTheater(char seats[][COLS]) {
	
	// For loop to set the status of all seats to open by setting each index of array to '.'
	for (int i = 0; i < ROWS; i++) {
		for (int k = 0; k < COLS; k++)
			seats[i][k] = '.';
		}
}
// Function to get user input of ticket purchase information and if available, displays the price of seat and updates the array
void PurchaseTicket(char seats[][COLS], const int prices[]) {
	
	int row = 0, seat = 0;
	
	cout << "Select Row: ";
	cin >> row;
	// Input validation loop that runs until user input is within range
	while (row > 15 || row < 1) {
		cout << "Invalid input! Must select a row between 1 and 15\nSelect Row: ";
		cin >> row;
	}
	cout << "Select Column/Seat: ";
	cin >> seat;
	// Input validation loop that runs until user input is within range
	while (seat > 30 || seat < 1) {
		cout << "Invalid input! Must select a seat between 1 and 30\nSelect Column/Seat: ";
		cin >> seat;
	}
	// If statement to check if seat is available, and if so, display purchesed ticket, price, and update array to show that seat as sold 
	if (seats[row - 1][seat - 1] == '.') {
		cout << "Ticket for row " << row << " seat " << seat << endl;
		cout << "Cost =  $" << prices[row - 1] << endl;
		seats[row - 1][seat - 1] = '#';
	}
	else
		cout << "I am sorry, that seat is taken" << endl;
}
// Function to get user information on purchasing block of seats and display price and update array if available
void PurchaseBlock(char seats[][COLS], const int prices[]) {
	
	// Variables
	int begR = 0, endR = 0, begC = 0, endC = 0, blockCost = 0;
	bool dummy = true;
	
	cout << "Select Beginning Row: ";
	cin >> begR;
	// Input validation loop that runs until user input is within range
	while (begR > 15 || begR < 1) {
		cout << "Invalid input! Must select a row between 1 and 15\nSelect Row: ";
		cin >> begR;
	}
	cout << "Select Ending Row: ";
	cin >> endR;
	// Input validation loop that runs until user input is within range
	while (endR > 15 || endR < 1) {
		cout << "Invalid input! Must select a row between 1 and 15\nSelect Row: ";
		cin >> endR;
	}
	cout << "Select Beginning Column/Seat: ";
	cin >> begC;
	// Input validation loop that runs until user input is within range
	while (begC > 30 || begC < 1) {
		cout << "Invalid input! Must select a column between 1 and 30\nSelect Column/Seat: ";
		cin >> begC;
	}
	cout << "Select Ending Column/Seat: ";
	cin >> endC;
	// Input validation loop that runs until user input is within range
	while (endC > 30 || endC < 1) {
		cout << "Invalid input! Must select a column between 1 and 30\nSelect Column/Seat: ";
		cin >> endC;
	}
	dummy = true;
	// For loop to check if any seats in the block are selected by checking value of each array index. If true, dummy variable is set to false
	for (int i = begR; i <= endR; i++) {
		for (int k = begC; k <= endC; k++) {
			if (seats[i - 1][k - 1] == '#')
				dummy = false;
		}
	}
	// If statement runs if dummy variable remains true after test. Ticket block purchased is stated and the price is claculated 
	// using two nested for loops and keeping a running total of difference in columns plus 1 times price at index minus one, which
	// computes the total price of the block. Seats array is also updated by marking all characters in block as '#'
	if (dummy) {
		blockCost = 0;
		cout << "Tickets for rows " << begR << " to " << endR << " and seats ";
		cout << begC << " to " << endC << endl;
		for (int i = begR; i <= endR; i++) {
			blockCost += (((endC - begC) + 1)*(prices[i - 1]));
			for (int k = begC; k <= endC; k++)
				seats[i - 1][k - 1] = '#';
		}
		cout << "Cost = $" << blockCost << endl;
	}
	else
		cout << "I am sorry, not all of those seats are available" << endl;
}