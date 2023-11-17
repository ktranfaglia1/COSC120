/* Kyle Tranfaglia
 * 09/26/22
 * Lab#3 - Exercise 2
 * This program asks the user for height and weight and calculates BMI and states the meaning of the result
 */
 #include <iostream>
 #include <cmath>
 
 int main ()
 {
	 using namespace std;
	 
	 // Variables
	 double inches = 0, pounds = 0, bmi = 0;
	 
	 cout << "Enter your weight in pounds: ";
	 cin >> pounds;
	 cout << "Enter your height in inches: ";
	 cin >> inches;
	 
	 bmi = ((pounds*703)/(pow(inches, 2.0)));
	 
	 cout << "Your Body Mass Index is: " << bmi << endl;
	 
	 // Statement compares bmi. If bmi is over 25, the first statement runs, if bmi is under 18.5, 
	 // the second statement runs. Else statement runs when the weight is in between the upper and lower bound
	 if (bmi > 25)
		 cout << "You are overweigth\n";
	 else if (bmi < 18.5)
		 cout << "You are underweight\n";
	 else 
		 cout << "You are at an optimal weight\n";
		 
	 return 0;
 }