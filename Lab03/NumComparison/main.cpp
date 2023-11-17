/* Kyle Tranfaglia
 * 09/26/22
 * Lab#3 - Exercise 1
 * This program asks the user for two numbers and compares them
 */
 #include <iostream>
 
 int main ()
 {
	 using namespace std;
	 
	 // Variables
	 double num1 = 0, num2 = 0;
	 
	 cout << "Enter two numbers: ";
	 cin >> num1 >> num2;
	 
	 // If statement compares the two numbers. If num1 is greater than num2, the first block statement runs.
	 // If num2 is greater than num1, the second block statement run. Otherwise, the last line runs as they must be equal
	 if (num1 > num2){
		 cout << "Smaller number: " << num2 << endl;
		 cout << "Larger number: " << num1 << endl;
	 }
	 else if (num1 < num2){
		 cout << "Smaller number: " << num1 << endl;
		 cout << "Larger number: " << num2 << endl;
	 }
	 else {
		 cout << "The two numbers are equal" << endl;
	 }
	 return 0;
 }