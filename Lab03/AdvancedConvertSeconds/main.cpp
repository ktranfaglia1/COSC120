/* Kyle Tranfaglia
 * 09/26/22
 * Lab#3 - Exercise 4
 * This program asks the user for an amount of seconds and converts it to the highest time variable applicable
 * and represents the remainding time as the next highest time variable applicable
 */
 #include <iostream>
 
 int main ()
 {
	 using namespace std;
	 
	 // Variables
	 double seconds = 0, minutes = 0, hours = 0, days = 0, secondsNew = 0;
	 const int MINUTE = 60, HOUR = 3600, DAY = 86400;
	 
	 cout << "Enter the number of seconds: ";
	 cin >> seconds;
	 
	 // Compares constant values to seconds value. Starting with highest possible conversion,
	 // the comparison checks if each statement is true, and if so, it runs that block statment only
	 // and uses the conversion factor to convert seconds into the largest unit variable applicable
	 // The remainder seconds is then calculated and this process is continued to reprsent seconds 
	 // as the highest variable applicable for each remainder. Casting is used to determine remainders
	 if (seconds > DAY){
		 days = seconds / DAY;
		 secondsNew = (days - static_cast<int>(days))*(DAY);
		 hours = secondsNew / HOUR;
		 secondsNew = (hours - static_cast<int>(hours))*(HOUR);
		 minutes = secondsNew / MINUTE;
		 secondsNew = (minutes - static_cast<int>(minutes))*(MINUTE);
		 cout << seconds << " seconds is equivalent to " << static_cast<int>(days) << " days ";
		 cout << static_cast<int>(hours) << " hours " << static_cast<int>(minutes);
		 cout << " minutes " << secondsNew << " seconds\n";
	 }
	 else if (seconds > HOUR){
		 hours = seconds / HOUR;
		 secondsNew = (hours - static_cast<int>(hours))*(HOUR);
		 minutes = secondsNew / MINUTE;
		 secondsNew = (minutes - static_cast<int>(minutes))*(MINUTE);
		 cout << seconds << " seconds is equivalent to " << static_cast<int>(hours) << " hours ";
		 cout << static_cast<int>(minutes) << " minutes " << secondsNew << " seconds\n";
	 }
	 else if (seconds > MINUTE){
		 minutes = seconds / MINUTE;
		 secondsNew = (minutes - static_cast<int>(minutes))*(MINUTE);
		 cout << seconds << " seconds is equivalent to ";
		 cout << static_cast<int>(minutes) << " minutes " << secondsNew << " seconds\n";
	 }
	 else {
		 cout << seconds << " seconds is equivalent to " << seconds << " seconds\n";
	 }
	 return 0;
 }	 