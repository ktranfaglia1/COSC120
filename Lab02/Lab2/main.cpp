/* Kyle Tranfaglia
 * 09/12/22
 * Lab#2
 */
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int main()
{
	using namespace std;
	
    // E.1 This program calculates a car's gas mileage given tank size and miles driven on full tank

    double tankSize=0, fullTank=0, milesPerGallon=0;

    cout << "This program calculates the miles per gallon of your vehicle.\n";
    cout << "Enter the amount of gallons that your tank can hold: "; 
	cin >> tankSize;
    cout << "Enter the miles you can drive on a full tank: ";
	cin >> fullTank;
	
	milesPerGallon = (fullTank)/(tankSize);
	
	cout << "Your car gets " << milesPerGallon << " miles per gallon.\n";
	
	// E.2 This program asks the user how many cookies they wish to make and calculates the amount of ingredients
	// needed using the base as instructions to make 48 cookies
	
	const double SUGAR = 1.5;
	const double BUTTER = 1;
	const double FLOUR = 3;
	const double BASE_COOKIES = 48;
	
	double sugar=0, butter=0, flour=0, cookies=0, percentOfRecipe=0;
	
	cout << "This programs gives you ingredient quantities to make cookies.\n";
	cout << "How many cookies would you like to make?\n";
	cin >> cookies;
	
	percentOfRecipe = BASE_COOKIES/cookies;
	sugar = SUGAR/percentOfRecipe;
	butter = BUTTER/percentOfRecipe;
	flour = FLOUR/percentOfRecipe;
	
	cout << "To make " << cookies << " cookies you should use: \n";
	cout << sugar << " cups of sugar\n" << butter << " cups of butter\n" << flour << " cups of flour.\n"; 
	
	// E.3 This program converts Celcius to Fahrenheit temperatures
	
	double celcius=0, fahrenheit=0;
	
	cout << "This program converts Celcius to Fahrenheit.\n";
	cout << "Enter a temperature in Celcius: ";
	cin >> celcius;
	
	fahrenheit = ((9)*(celcius)/5) + 32;
	
	cout << celcius << " degrees Celcius is " << fahrenheit << " degrees Fahrenheit.\n";
	
	// E.4 This program converts fahrenheit to celcius temperatures 
	// The variables from E.3 are resued here
	
	cout << "This program converts Fahrenheit to Celcius.\n";
	cout << "Enter a temperature in Fahrenheit: ";
	cin >> fahrenheit;
	
	celcius = ((5)*(fahrenheit - 32)/9);
	
	cout << fahrenheit << " degrees Fahrenheit is " << celcius << " degrees Celcius\n";
	
	// E.5 This program converts US Dollars to another currency given exchange rate and name
	
	string currency="";
	double usDollars=0, exchangeRate=0, currencyValue=0;
	
	cout << "This porgram converts US Dollars to another currency\n";
	cout << "How many US dollars would you like to convert?\n";
	cin >> usDollars;
	cout << "What currency would you like to convert to?\n";
	cin >> currency;
	cout << "What is the exchnage rate of " << currency << " (1 US Dollar is how many " << currency << ")?\n";
	cin >> exchangeRate;
	
	currencyValue = usDollars*exchangeRate;
	
	cout << usDollars << " is equal to " << currencyValue << " " << currency << endl;
	
	// E.6 This program displays the sine, cosine, and tangent of a given angle
	
	double angle=0, cos1=0, tan1=0, sin1=0;
	
	cout << "This program displays the sine, cosine, and tangent of a given angle\n";
	cout << "Enter an angle (in radians): ";
	cin >> angle;
	
	cos1 = cos(angle);
	tan1 = tan(angle);
	sin1 = sin(angle);
	
	cout << "sin(" << angle << ") = " << sin1 << endl;
	cout << "cos(" << angle << ") = " << cos1 << endl;
	cout << "tan(" << angle << ") = " << tan1 << endl;
	
	// E.7 This program calculates compund interest given interest, starting amount, and duration
	
	int timesCompunded=0;
	double startingValue=0, interestRate=0, interest=0, totalSavings=0;
	
	cout << "This program calculates compund interest\n";
	cout << "Enter the amount in your acount (principal): ";
	cin >> startingValue;
	cout << "Enter the annual interest rate in decimal form (4% = 0.04): ";
	cin >> interestRate;
	cout << "Enter the amount of times the interest is compunded per year: ";
	cin >> timesCompunded;
	
	totalSavings = (startingValue)*pow((1 + (interestRate/timesCompunded)), timesCompunded);
	interest = totalSavings - startingValue;
	
	cout << setprecision(2) << fixed << endl;
	cout << "Interest rate: " << setw(10) << interestRate*100 << "%" << endl;
	cout << "Times compounded: " << setw(4) << timesCompunded << endl;
	cout << "Principal:         $" << setw(5) << startingValue << endl;
	cout << "interest:          $" << setw(5) << interest << endl;
	cout << "Amount in savings: $" << setw(5) << totalSavings << endl;
	
	// E.8 This program calculates the monthly payment of a loan
	
	int numberOfPayments=0;
	double annualInterest=0, loanAmount=0, totalPaid=0, interestPaid=0, monthlyPayment=0;
	
	cout << "This program calculates the monthly payment of a loan\n";
	cout << "Enter the annual interest rate: ";
	cin >> annualInterest;
	cout << "Enter the the number of payments: ";
	cin >> numberOfPayments;
	cout << "Enter the amount of the loan: ";
	cin >> loanAmount;
	
	monthlyPayment = (((annualInterest/12)*pow((1 + annualInterest/12),numberOfPayments))
	/((pow((1 + annualInterest/12),numberOfPayments)) - 1))*(loanAmount);
	totalPaid = monthlyPayment*numberOfPayments;
	interestPaid = totalPaid - loanAmount; 
	
	cout << setprecision(2) << fixed << endl;
	cout << "Interest rate: " << setw(10) << annualInterest*100 << "%" << endl;
	cout << "Number of payments: " << setw(4) << numberOfPayments << endl;
	cout << "Loan amount:        $" << setw(5) << loanAmount << endl;
	cout << "Monthly payment:    $" << setw(5) << monthlyPayment << endl;
	cout << "Amount paid back:   $" << setw(5) << totalPaid << endl;
	cout << "Interest paid:      $" << setw(5) << interestPaid << endl;
	
	return 0;
}