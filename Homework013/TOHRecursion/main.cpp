/* Kyle Tranfaglia
 * 12/12/22
 * Homework#13 - Exercise 4
 * Program to display the steps to complete the Tower of Hanoi game with 3 pegs and 4 pegs
 * given the amount of disks and dispalsy a count of the moves needed to solve it
 */
#include <iostream>

using namespace std;

// Prototypes
void hanoi(int n, int &count3, char peg1, char peg3, char peg2);
void hanoi4(int n, int &count4, char peg1, char peg4, char peg2, char peg3);

int main() {
	int n = 0, count3 = 0, count4 = 0;
	char peg1 = 'A', peg2 = 'B', peg3 = 'C', peg4 = 'D';

	cout << "Enter the number of disks: ";
	cin >> n;
	cout << "The solution for n = " << n << " disks. Using 3 pegs." << endl;

	hanoi(n, count3, peg1, peg2, peg3); // Calls the recursive function to display the moves and increment the move count with 3 pegs
	cout << "Number of moves in the solution = " << count3++ << endl << endl;
	
	cout << "The solution for n = " << n << " disks. Using 4 pegs." << endl;

	hanoi4(n, count4, peg1, peg2, peg3, peg4); // Calls the recursive function to display the moves and increment the move count with 4 pegs
	cout << "Number of moves in the solution = " << count4++ << endl;

	return 0;
}
// Recursive function to display the steps to complete he Tower of Hanoi game with 3 pegs and n disks and counts the moves
void hanoi(int n, int &count3, char peg1, char peg3, char peg2) {
	// Base case in which if n is zero, no moves are needed so it returns
	if (n == 0) {
		return;
	}
	// Statement that is true if n is one and does the single move to complete the game. Otherwise, the else statement recursively calls the function and 
	// displays one progressing move using the temporary peg and continues to call the function until solved, meaning n was one and the last move was made
	if (n == 1) {
		cout << "Move " << peg1 << " to " << peg3 << endl;
		count3++;
	}
	else {
		hanoi(n - 1, count3, peg1, peg2, peg3);
		cout << "Move " << peg1 << " to " << peg3 << endl;
		count3++;
		hanoi(n - 1, count3, peg2, peg3, peg1);
	}
}
// Recursive function to display the steps to complete he Tower of Hanoi game with 4 pegs and n disks and counts the moves
void hanoi4(int n, int &count4, char peg1, char peg4, char peg2, char peg3) {
	// Base case in which if n is zero, no moves are needed so it returns
	if (n == 0) {
		return;
	}
	// Statement that is true if n is one and does the single move to complete the game. Otherwise, the else statement recursively calls the function
	// and displays three moves using the temporary pegs and continues to call the function until solved, meaning n was one and the last move was made 
	if (n == 1) {
		cout << "Move " << peg1 << " to " << peg4 << endl;
		count4++;
	}
	else {
		hanoi4(n - 2, count4, peg1, peg2, peg3, peg4); // Recursive step
		cout << "Move " << peg1 << " to " << peg3 << endl;
		cout << "Move " << peg1 << " to " << peg4 << endl;
		cout << "Move " << peg3 << " to " << peg4 << endl;
		count4 += 3;
		hanoi4(n - 2, count4, peg2, peg4, peg1, peg3); // Another recursive step with changes to temporary pegs
	}
}