/* Kyle Tranfaglia
 * 09/26/22
 * Lab#3 - Exercise 6
 * This program asks for the number of days works and calculates the salary if it started at 1 penny and doubled each day
 */
 #include <iostream>
 #include <iomanip>
 
 int main ()
 {
	 using namespace std;
	 
	 // Variables
	 int days = 0;
	 double daily = 0.01, salary = 0;
	 
	 cout << setprecision(2) << fixed;
	 
	 cout << "Enter the number of days worked: ";
	 cin >> days;
	 
	 // Input validation loop. If days is not at least 1, the loop runs until the new input is within the range
	 while (days < 1){
		 cout << "Days must be at least 1\n";
		 cout << "Enter the number of days worked: ";
		 cin >> days;
	 }
	 
	 cout << "   Day" << setw(15) << "Salary" << endl;
	 cout << "    1" << setw(15) << "  0.01" << endl;
	 
	 // Loop starts with initializing i = 2 as this is when doubling calculation begins. The loop continues until it iterates to a value 
	 // equal to the days. The loop iterates by one and multiplies the daily earning by 2 and keeps a running total of the salary
	 for (int i = 2; i < days + 1; i++){
		 daily *= 2;
		 salary += daily;
		 cout << setw(5) << i << setw(15) << daily << endl;
	 }
	 cout << "Total Salary:  $" << salary << endl;
	 
	 return 0;
 }