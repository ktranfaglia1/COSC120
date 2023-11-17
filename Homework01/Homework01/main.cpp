/* Kyle Tranfaglia
 * 09/16/22
 * Homework#1
 * This program will compute some calculations for 15 excerises
 */
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    using namespace std;

    // E.1
    // This program converts miles to feet
    // Variables - constant conversion, input, and output
	
    const int FEET_PER_MILE = 5280;
    double miles, feet;

    cout << "This program converts miles to feet.\n";
    cout << "Enter the number of miles: \n";
    cin >> miles;

    feet = (miles) * (FEET_PER_MILE);

    cout << "There are " << feet << " feet in " << miles << " mile(s)\n";

    // E.2
    // This program converts feet to miles
    // Same variables will be used from E.1

    cout << "This program converts feet to miles.\n";
    cout << "Enter the number of feet: ";
    cin >> feet;

    miles = (feet) / (FEET_PER_MILE);

    cout << "There are " << miles << " mile(s) in " << feet << " feet\n";

    // E.3
    // This program converts feet to feet and inches
    // constant inches in foot, inches calculation, and foot truncation

    const int INCHES_IN_FOOT = 12;
    double inches;
    int ft;

    cout << "This program converts feet to feet and inches.\n";
    cout << "Enter the number of feet: ";
    cin >> feet;

    ft = feet;
    inches = (feet - ft) * (INCHES_IN_FOOT);

    cout << "There are " << ft << " feet and " << inches << " inches in " << feet << " feet\n";

    // E.4
    // This program calculates the volume of a pyramid
    // input variables lenght, width, and height to store user input, and volume to store calculation

    double length, width, height, volume;

    cout << "This program calculates the volume of a pyrmaid.\n";
    cout << "Enter the following dimensions\n";
    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;

    volume = (length * width * height) / (3);

    cout << "The volume of the pyramid is " << volume << endl;

    // E.5
    // This program calculates the volume of a sphere
    // radius variable to hold user input and pi variable to hold the constant pi approximation
    // Volume variable used from E.4

    const double PI = 3.141592653589793;
    double radius;

    cout << "This program calculates the volume of a sphere.\n";
    cout << "Enter the radius of the shpere\n";
    cin >> radius;

    volume = (4) * (PI) * (pow(radius, 3)) / 3;

    cout << "The volume of the sphere is " << volume << endl;

    // E.6
    // This program rolls each of the five platonic solids in Dungeons and Dragons
    // 5 di variables
	
    int d4, d6, d8, d12, d20;

    cout << "This program rolls each of the five platonic solids in Dungeons and Dragons\n";

    d4 = (rand() % 4) + 1;
    d6 = (rand() % 6) + 1;
    d8 = (rand() % 8) + 1;
    d12 = (rand() % 12) + 1;
    d20 = (rand() % 20) + 1;

    cout << "Dice: " << d4 << " " << d6 << " " << d8 << " " << d12 << " " << d20 << endl;

    // E.7
    // This program generates a random integer number
    // variables upper and lower bound

    int upper, lower;

    cout << "This program generates a random integer number\n";
    cout << "Please assign the bounds\n";
    cout << "Lower bound:";
    cin >> lower;
    cout << "upper bound:";
    cin >> upper;
    cout << "Random number:" << (rand() % (upper - lower + 1)) + lower << endl;

    // E.8
    // This program generates the total bill at a restaurant
    // Variables for user input, constants for tip and tax, and the total, and calculated tip and tax

    const double TAX = 0.06;
    const double TIP = 0.15;
    double bill, tax, tip, total;

    cout << "This program generates the total bill at a restaurant\n";
    cout << "Enter the bill amount: ";
    cin >> bill;

    tax = (bill) * (TAX);
    tip = (bill) * (TIP);
    total = bill + tax + tip;

    cout << setprecision(2) << fixed;
    cout << "Bill:  $ " << right << setw(5) << bill << endl;
    cout << "Tax:   $ " << right << setw(6) << tax << endl;
    cout << "Tip:   $ " << right << setw(6) << tip << endl;
    cout << "Total: $ " << right << setw(5) << total << endl;

    // E.9
    // This program converts a person's informal name to their formal name
    // Variables for first name, and last namespace

    string firstName, lastName;

    cout << "This program converts a person's informal name to their formal name\n";
    cout << "Enter your informal name: ";
    cin >> firstName;
    cin.get();
    getline(cin, lastName);
    cout << lastName << ", " << firstName << endl;

    // E.10
    // This program has the user eneter XXX and YYY within a string and then replaces the XXX and YYY with user input
    // Variables for user input sentence, replacement 1 and 2, and the integer xxx and yyy variables to hold loacation

    string sentence, rep1, rep2;
    int xxx, yyy;

    cout << "Input merge format sentence: ";
    getline(cin, sentence);

    xxx = sentence.find("XXX");
    yyy = sentence.find("YYY");

    cout << "Input XXX replacement: ";
    cin >> rep1;
    cout << "Input YYY replacement: ";
    cin >> rep2;

    sentence.replace(xxx, 3, rep1);
    sentence.replace(yyy, 3, rep2);

    cout << sentence << endl;

    // E.11
    // This program asks the user for a sentence and a phrase and splits the sentence starting with the phrase
    // Variables to store phrase word and sentence and int to store position of phrase

    string sent, phrase;
    int pos;

    cout << "Input a sentence: ";
    getline(cin, sent);
    cout << "Enter a phrase (in the sentence): ";
    getline(cin, phrase);

    pos = sent.find(phrase);

    sent.insert(pos, "\n");

    cout << sent << endl;

    // E.12
    // This program asks the user to enter the length from the center of the octagon to one of the vertices
    // and calculates the area and perimeter
    // Variables to capture s, r, and h, and to hold calculates values area and perimeter

    double side, rad, leng, area, perimeter;

    cout << "This program calculates the area and perimeter of an octagon\n";
    cout << "Enter the radius: ";
    cin >> rad;

    side = (rad) * (sqrt(2 - sqrt(2)));
    leng = sqrt(pow(rad, 2.0) - pow((side / 2), 2.0));
    area = (side / 4) * (leng) * (16);
    perimeter = (side) * (8);

    printf("Area = %0.15f \nPerimeter =  %0.15f\n", area, perimeter);

    // E.13
    // This program displays the amount of change as the number of twenties, tens, fives, one dollars,
    // quarters, dimes, nickels, and pennies
    // Variables for change, change converted to int, decimal of change, and all change options
    // This is likley not efficent coding but its all I could think to do

    int change1, changeDecimal1;
    double change, changeDecimal;
    int twenty = 0, ten = 0, five = 0, one = 0, quarter = 0, dime = 0, nickel = 0, penny = 0;

    cout << "This program displays the amount of change as the number of each form of currency\n";
    cout << "Enter the amount of change: ";
    cin >> change;

    changeDecimal = change - static_cast<int>(change);
    changeDecimal *= 100;
    changeDecimal1 = static_cast<int>(changeDecimal);
    change1 = static_cast<int>(change);

    twenty = change1 / 20;
    change1 %= 20;
    ten = change1 / 10;
    change1 %= 10;
    five = change1 / 5;
    change1 %= 5;
    one = change1;

    quarter = changeDecimal1 / 25;
    changeDecimal1 %= 25;
    dime = changeDecimal1 / 10;
    changeDecimal1 %= 10;
    nickel = changeDecimal1 / 5;
    changeDecimal1 %= 5;
    penny = changeDecimal1;

    cout << "Change\n"
         << "------------------" << endl;
    cout << "Twenties: " << twenty << "\nTens: " << ten << "\nFives: " << five << "\nOnes: " << one << endl;
    cout << "Quarters: " << quarter << "\nDimes: " << dime << "\nNickels: " << nickel << "\nPennies: " << penny << endl;

    // E.14
    // This program calculates the internal angles of a triangle given the three side lengths
    // Variables for side a, b, and c, rad angles A, B, and C, and deg angles A, B, and C.
    // Constnat PI reused from earlier exercise

    double a, b, c, radA, radB, radC, degA, degB, degC;

    cout << "This program calculates the internal angles of a triangle given the three side lengths\n";
    cout << "Enter side length a: ";
    cin >> a;
    cout << "Enter side length b: ";
    cin >> b;
    cout << "Enter side length c: ";
    cin >> c;

    radA = acos((pow(a, 2.0) + pow(b, 2.0) - pow(c, 2.0)) / ((2) * (a) * (b)));
    radB = acos((pow(b, 2.0) + pow(c, 2.0) - pow(a, 2.0)) / ((2) * (b) * (c)));
    radC = acos((pow(c, 2.0) + pow(a, 2.0) - pow(b, 2.0)) / ((2) * (c) * (a)));
    degA = radA * (180 / PI);
    degB = radB * (180 / PI);
    degC = radC * (180 / PI);

    printf("Angles in radians: %0.15f %0.15f %0.15f\n", radB, radC, radA);
    printf("Angles in degrees: %0.15f %0.15f %0.15f\n", degB, degC, degA);

    // E.15
    // This program calculates the number of points and percentage the user needs for the rest of the
    // semester to get their target average
    // Variables for total points so far, earned points so far, points remaining,
    // target percentage, needed points, percentage to achieve target

    double targetPercent, neededPercent, currentTotal, currentEarned, pointsRemaining, pointsNeeded;

    cout << "This program calculates the number of points and percentage the user needs ";
    cout << "for the rest of the semester to get their target average\n";
    cout << "Input the number of points on all assignments so far: ";
    cin >> currentTotal;
    cout << "Input the number of points you have earned so far: ";
    cin >> currentEarned;
    cout << "Input the number of points remaining: ";
    cin >> pointsRemaining;
    cout << "Input your target percentage: ";
    cin >> targetPercent;

    pointsNeeded = (targetPercent / 100) * (currentTotal + pointsRemaining) - currentEarned;
    neededPercent = ((pointsNeeded) / (pointsRemaining)) * 100;

    cout << "You need " << pointsNeeded << " out of " << pointsRemaining << " to have a ";
    cout << targetPercent << "% at the end of the semester\n";
    cout << "So you need to do an average of " << neededPercent << "% from now to the end of the semester\n";

    return 0;
}