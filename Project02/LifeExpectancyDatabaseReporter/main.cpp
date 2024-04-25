/* Kyle Tranfaglia
 * 11/28/22
 * Project#2
 * This program will read in a data file on life expectancy, place the data is a struct vector,
 * and assess the data to report life expectancy given information provided by the user
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
// Struct to store a line of data from a database 
struct LifeExp {
	string code = "";
	string country = "";
	string region = "";
	string income = "";
	string gender = "";
	unsigned int year = 0;
	double expectancy = 0;
};
// Prototypes
string trim_copy(string);
bool PopulateDataBase(vector<LifeExp> &);
void PopulateSortGender(const vector<LifeExp> &, vector<string> &);
void PopulateSortYear(const vector<LifeExp> &, vector<unsigned int> &);
void PopulateSortCountry(const vector<LifeExp> &, const vector<unsigned int> &, const vector<string> &, vector<string> &, unsigned int, unsigned int);
void DisplayResults(const vector<LifeExp> &, const vector<unsigned int> &, const vector<string> &, const vector<string> &, unsigned int, unsigned int, unsigned int);

int main () {
	// Variables
	vector<LifeExp> dataBase;
	vector<string> gender, country;
	vector<unsigned int> year;
	unsigned int selection1 = 0, selection2 = 0, selection3 = 0;
	bool check = true;
	// Function to call function to populate the database vector of stucts and terminate the program with an error code of 1 if the file does not open in the function
	if (PopulateDataBase(dataBase)) {
		return 1;
	}
	cout << "Select Gender Type" << endl << "-------------------" << endl;
	PopulateSortGender(dataBase, gender); // Calls function to populate gender options from database
	// For loop to go through all indexes of gender vector and print them in a numbered list to the console
	for (unsigned int i = 0; i < gender.size(); i++) {
		cout << i + 1 << ". " << gender[i] << endl;
	}
	cout << "\nSelection: ";
	cin >> selection1;
	// Input validation loop for first user selection. Loop runs until input is a choice listed in the console (an index in the vector)
	while (selection1 <= 0 || selection1 > gender.size()) {
		cout << "Invalid Input! Enter a value from the selection above" << endl;
		cout << "Selection: ";
		cin >> selection1;
	}
	cout << "Select Birth Year" << endl << "------------------" << endl;
	PopulateSortYear(dataBase, year); // Calls function to populate the year options from database
	// For loop to go through all the indexes of year vector and print them out to the console
	for (unsigned int i = 0; i < year.size(); i++) {
		cout << year[i] << endl;
	}
	cout << "\nSelection: ";
	cin >> selection2;
	// While loop for input validation. Loop uses a count to determine the if the option selected is a valid choice, the count should be one, meaning 
	// it found a match in the vetcor, and the loop will terminate, otherwise, the count will be zero and the user will be instructed to enter a selection again
	while (check) {
		unsigned int count = 0;
		for (unsigned int i = 0; i < year.size(); i++) {
			if (selection2 == year[i]) {
				count++;
			}
		}
		if (count == 0) {
			cout << "Invalid Input! Enter a value from the selection above" << endl;
			cout << "Selection: ";
			cin >> selection2;
		}
		else {
			check = false;
		}
	}
	cout << "Select Country" << endl << "--------------" << endl;
	PopulateSortCountry(dataBase, year, gender, country, selection1, selection2); // Calls function to populate vector of countries from database given year and gender
	// For loop to go through all indexes of country vector and print them in a numbered list to the console
	for (unsigned int i = 0; i < country.size(); i++) {
		cout << i + 1 << ". " << country[i] << endl;
	}
	cout << "\nSelection: ";
	cin >> selection3;
	// Input validation loop for first user selection. Loop runs until input is a choice listed in the console (an index in the vector)
	while (selection3 <= 0 || selection3 > country.size()) {
		cout << "Invalid Input! Enter a value from the selection above" << endl;
		cout << "Selection: ";
		cin >> selection3;
	}
	DisplayResults(dataBase, year, gender, country, selection1, selection2, selection3); // Calls function display the records found
	
	return 0;
}  
// Function to create a copy of the string, erase any unwanted space before or after the string, and then return that copy
string trim_copy(string str) {
	str.erase(0, str.find_first_not_of("\t\n\r\v\f "));
	str.erase(str.find_last_not_of("\t\n\r\v\f ") + 1);
	return str;
}
// Function to populate the database vector by reading in the life expectancy file line by line and storing the information in a vector of structs 
bool PopulateDataBase(vector<LifeExp> &dataBase) {
	//Variables
	fstream file;
	LifeExp life;
	string line = "";
	int pos = 0, lastPos = 0;
	
	// Opens File
	file.open("LifeExpWorld.txt", ios::in);
	// Checks if file opened and returns true and error message if the file did not open
	if (!file) {
		cerr << "Error opening file.\n";
		return true;
	}
	getline(file, line); // Eats the header line in the file
	// While loop to read in the file line by line and use the find and substrings function to parse the data and place the data in the appropriate section of the struct
	while (getline(file, line)) {
		pos = line.find('\t');
		life.code = trim_copy(line.substr(0, pos));

		lastPos = pos;
		pos = line.find('\t', pos + 1);
		life.country = trim_copy(line.substr(lastPos, pos - lastPos));

		lastPos = pos;
		pos = line.find('\t', pos + 1);
		// Checks if the position is a tab, and if so, it will set the member variable to a defualt value, otherwise, its value is the substring
		if (line.substr(lastPos, pos - lastPos) != "\t") {
			life.region = trim_copy(line.substr(lastPos, pos - lastPos));
		}
		else {
			life.region = "";
		}
		lastPos = pos;
		pos = line.find('\t', pos + 1);
		// Checks if the position is a tab, and if so, it will set the member variable to a defualt value, otherwise, its value is the substring
		if (line.substr(lastPos, pos - lastPos) != "\t") {
			life.income = trim_copy(line.substr(lastPos, pos - lastPos));
		}
		else {
			life.income = "";
		}
		lastPos = pos;
		pos = line.find('\t', pos + 1);
		life.gender = trim_copy(line.substr(lastPos, pos - lastPos));

		lastPos = pos;
		pos = line.find('\t', pos + 1);
		life.year = stoi(trim_copy(line.substr(lastPos, pos - lastPos)));
		
		lastPos = pos;
		pos = line.find('\t', pos + 1);
		// Checks if the position is a tab, and if so, it will set the member variable to a defualt value, otherwise, its value is the substring
		if (line.substr(lastPos, pos - lastPos) != "\t") {
			life.expectancy = stod(trim_copy(line.substr(lastPos, pos - lastPos)));
		}
		else {
			life.expectancy = 0;
		}
		dataBase.push_back(life); // Pushes the stuct to the back of the database vector
	}
	file.close();
	
	return false;
}
// Function to populate and sort the gender vector in alphabetically ascedening order via reference with only unique data
void PopulateSortGender(const vector<LifeExp> &dataBase, vector<string> &gender) {
	// Loop to go through all indexes of the database vector and use a count to only populate unique gender options by comparing each gender option 
	// to indexes in gender vector, and if it does not exist in the gender vector, it pushes the gender option to the back of the vector
	for (unsigned int i = 0; i < dataBase.size(); i++) {
		int count = 0;
		for (unsigned int k = 0; k < gender.size(); k++) {
			if (dataBase[i].gender == gender[k])
				count++;
		}
		if (count == 0)
			gender.push_back(dataBase[i].gender);
	}
	sort(gender.begin(), gender.end()); // Uses the algorithm sort to sort the vector in alphabetically ascedening order
}
// Function to populate and sort the year vector in ascedening order via reference with only unique data
void PopulateSortYear(const vector<LifeExp> &dataBase, vector<unsigned int> &year) {
	// Loop to go through all indexes of the database vector and use a count to only populate unique year options by comparing each year option 
	// to indexes in year vector, and if it does not exist in the year vector, it pushes the year option to the back of the vector
	for (unsigned int i = 0; i < dataBase.size(); i++) {
		int count = 0;
		for (unsigned int k = 0; k < year.size(); k++) {
			if (dataBase[i].year == year[k])
				count++;
		}
		if (count == 0)
			year.push_back(dataBase[i].year); // Uses the algorithm sort to sort the vector in ascedening order
	}
	sort(year.begin(), year.end());
}
// Function to populate and sort the country vector in alphabetically ascedening order via reference
void PopulateSortCountry(const vector<LifeExp> &dataBase, const vector<unsigned int> &year, const vector<string> &gender, 
										vector<string> &country, unsigned int selection1, unsigned int selection2) {
	// Loop to go through all indexes of the database vector and only populate unique country options by checking if the country's
	// year and gender information both matches the user selection, and if so, pushes the country name to the back of the country vector
	for (unsigned int i = 0; i < dataBase.size(); i++) {
		if (dataBase[i].year == selection2 && dataBase[i].gender == gender[selection1 - 1]) {
			country.push_back(dataBase[i].country);
		}
	}
	sort(country.begin(), country.end()); // Uses the algorithm sort to sort the vector in alphabetically ascedening order
}
// Function to find and display the records found that match the user selections without repeating and possibly displaying multiple records
void DisplayResults(const vector<LifeExp> &dataBase, const vector<unsigned int> &year, const vector<string> &gender, 
						const vector<string> &country, unsigned int selection1, unsigned int selection2, unsigned int selection3) {
											
	cout << endl << "Records Found" << endl << "-------------" << endl;
	// For loop to go through all indexes of database vector and compare the year, country, and gender of that index and compare them to user selections.
	// If the index matches all the selections, a nested for loop is used to display the information by checking if the value of each member variable of the 
	// struct is not a defualt value, and if it is, it will skip the print of that member variable, or print none given if there is no life expectancy data
	for (unsigned int i = 0; i < dataBase.size(); i++) {
		if (dataBase[i].year == selection2 && dataBase[i].gender == gender[selection1 - 1] && dataBase[i].country == country[selection3 - 1]) {
			cout << "Country: " << dataBase[i].country << " (" << dataBase[i].code << ")" << endl;
			if (dataBase[i].region != "") {
				cout << "Region: " << dataBase[i].region << endl;
			}
			if (dataBase[i].income != "") {
				cout << "Income Group: " << dataBase[i].income << endl;;
			}
				cout << "Gender: " << dataBase[i].gender << endl;
				cout << "Year of Birth: " << dataBase[i].year << endl;
			if (dataBase[i].expectancy != 0) {
				cout << "Life Expectancy: " << dataBase[i].expectancy << " Years" << endl << endl;
			}
			else {
				cout << "Life Expectancy: None Given" << endl << endl;
			}
		}
	}
}