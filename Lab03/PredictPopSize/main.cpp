/* Kyle Tranfaglia
 * 09/26/22
 * Lab#3 - Exercise 7
 * This program predicts the size of a population given starting number of people,
 * average annual population increase, and multiplication years
 */
 #include <iostream>
 #include <iomanip>
 
 int main ()
 {
	 using namespace std;
	 
	 // Variables
	 int startingPop = 0, years = 0;
	 double percent = 0, population = 0;
	 
	 cout << "Enter the starting number of people: ";
	 cin >> startingPop;
	 
	 // Input validation loop. If startingPop is less than 2, the loop runs until the new input is within the range
	 while (startingPop < 2){
		 cout << "Starting population should be at least 2\n";
		 cout << "Enter the starting number of people: ";
		 cin >> startingPop;
	 }
	 
	 cout << "Enter the annual population increase as a percentage: ";
	 cin >> percent;
	 
	 // Input validation loop. If percent is less than 0, the loop runs until the new input is within the range
	 while (percent < 0){
		 cout << "The annual population increase must be positive\n";
		 cout << "Enter the annual population increase as a percentage: ";
		 cin >> percent;
	 }
	 
	 cout << "Enter the number of years: ";
	 cin >> years;
	 
	 // Input validation loop. If years is less than 1, the loop runs until the new input is within the range
	 while (years < 1) {
		 cout << "The number of years must be at least 1\n";
		 cout << "Enter the number of years: ";
		 cin >> years;
	 }
	 
	 percent = (percent/100) + 1;
	 population = startingPop;
	 
	 cout << setprecision(3) << fixed;
	 
	 cout << "   Year" << setw(15) << "Population" << endl;
	 
	 // Loop initializes i = 1. If i is less than the entered value for years, the loop continues. After keeping a 
	 // running total of the population by multiplying by the percent value, the loop iterates.
	 for (int i = 1; i < years + 1; i++){
		 population = (population*percent);
		 cout << setw(5) << i << setw(16) << population << endl;
	 }
	 return 0;
 }