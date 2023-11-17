/* Kyle Tranfaglia
 * 09/26/22
 * Lab#3 - Exercise 3
 * This program asks the user for an amount of seconds and converts it to the highest time variable applicable
 */
 #include <iostream>
 
 int main ()
 {
	 using namespace std;
	 
	 // Variables
	 double seconds = 0, minutes = 0, hours = 0, days = 0;
	 const int MINUTE = 60, HOUR = 3600, DAY = 86400;
	 
	 cout << "Enter the number of seconds: ";
	 cin >> seconds;
	 
	 // Compares constant values to seconds value. Starting with highest possible conversion,
	 // the comparison checks if each statement is true, and if so, it runs that block statment only
	 // and uses the conversion factor to convert seconds into the largest unit vaariable applicable
	 if (seconds > DAY){
		 days = seconds/DAY;
		 cout << seconds << " seconds is equivalent to " << days << " days\n";
	 }
	 else if (seconds > HOUR){
		 hours = seconds/HOUR;
		 cout << seconds << " seconds is equivalent to " << hours << " hours\n";
	 }
	 else if (seconds > MINUTE){
		 minutes = seconds/MINUTE;
		 cout << seconds << " seconds is equivalent to " << minutes << " minutes\n";
	 }
	 else {
		 cout << seconds << " seconds is equivalent to " << seconds << " seconds\n";
	 }
	 return 0;
 }	 