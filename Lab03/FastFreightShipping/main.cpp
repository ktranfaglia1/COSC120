/* Kyle Tranfaglia
 * 09/26/22
 * Lab#3 - Exercise 5
 * This program asks for the weight of a package and diatnace to ship it and calculates the shipping cost
 */
 #include <iostream>
 #include <iomanip>
 
 int main ()
 {
	 using namespace std;
	 
	 // Variables
	 const float PRICE1 = 1.10, PRICE2 = 2.20, PRICE3 = 3.70, PRICE4 = 4.80;
	 double weight = 0, miles = 0, shippingCost = 0;
	 
	 cout << "Enter the weight of the package in kg: ";
	 cin >> weight;
	 
	 // Input validation loop. If weight is not in specified range, the loop runs until the new input is within the range
	 while (weight < 0 || weight > 20){
		 cout << "Weight must be greater than 0 and less than or equal to 20 kg\n";
		 cout << "Enter the weight of the package in kg: ";
		 cin >> weight;
	 }
	 
	 cout << "Enter the distance to ship the package in miles: ";
	 cin >> miles;
	 
	 // Input validation loop. If miles is not in specified range, the loop runs until the new input is within the range
	 while (miles < 10 || weight > 3000){
		 cout << "Can only ship between 10 and 3000 miles\n";
		 cout << "Enter the distance to ship the package in miles: ";
		 cin >> miles;
	 }
	 cout << setprecision(2) << fixed;
	 
	 // If statment is used to determine the charge per 500 miles by comparing weight. Starting with comparing
	 // the lowest weight, if the weight is less than the specified amount the statement runs, if not, it moves 
	 // to the next comparison and will check if true until comparison is true or else is reached. The statements
	 // within each if statement is an equation that calculates shipping cost for that weight of package.
	 if (weight <= 2)
		 shippingCost = (miles*PRICE1)/500;
	 else if (weight <= 6)
		 shippingCost = (miles*PRICE2)/500;
	 else if (weight <= 10)
		 shippingCost = (miles*PRICE3)/500;
	 else 
		 shippingCost = (miles*PRICE4)/500;
	 
	 cout << "Shipping Cost: $" << shippingCost << endl;
	 
	 return 0;
 }