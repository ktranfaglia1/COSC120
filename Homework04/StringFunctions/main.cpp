/* Kyle Tranfaglia
 * 10/10/22
 * Homework#4 - Exercise 1
 * This program will create a few useful functions for strings
 */
#include <iostream>
#include <string>

using namespace std;

// Prototypes for some useful string functions
void to_uppercase(string &str);
void to_lowercase(string &str);
string to_uppercase_copy(string str);
string to_lowercase_copy(string str);
void ltrim(string &str);
void rtrim(string &str);
void trim(string &str);
string ltrim_copy(string str);
string rtrim_copy(string str);
string trim_copy(string str);

int main () {
	
	string str = "Hi There 123 &*^#$%#";
    string str2 = "";
	
    cout << str << endl;
    to_uppercase(str); // Calls reference uppercase function
    cout << str << endl;
    to_lowercase(str); // Calls reference lowercase function
    cout << str << endl;
    cout << endl;
	
    str2 = to_uppercase_copy(str); // Calls value uppercase function
    cout << str << endl;
    cout << str2 << endl;
    cout << endl;
	
    to_uppercase(str); // Calls reference uppercase function
    str2 = to_lowercase_copy(str); // // Calls value lowercase function
    cout << str << endl;
    cout << str2 << endl;
    cout << endl;
	
    str = "   Hi There   ";
	
    cout << "*****" << str << "*****" << endl;
	
    ltrim(str); // Calls reference left trim function
    cout << "*****" << str << "*****" << endl;
	
    str = "   Hi There   ";
    rtrim(str); // Calls reference right trim function
    cout << "*****" << str << "*****" << endl;
	
    str = "   Hi There   ";
    trim(str); // Calls reference trim function
    cout << "*****" << str << "*****" << endl;
    cout << endl;
	
    str = "   Hi There   ";
    str2 = ltrim_copy(str); // Calls value left trim function
    cout << "*****" << str << "*****" << endl;
    cout << "*****" << str2 << "*****" << endl;

    str2 = rtrim_copy(str); // Calls value right trim function
    cout << "*****" << str << "*****" << endl;
    cout << "*****" << str2 << "*****" << endl;
	
    str2 = trim_copy(str); // Calls value trim function
    cout << "*****" << str << "*****" << endl;
    cout << "*****" << str2 << "*****" << endl;

	return 0;
}
// Pass by reference function that converts a string to uppercase using a for loop that uses the toupper
// command to change the word to uppercase character by character
void to_uppercase(string &str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
}
// Pass by reference function that converts a string to lowercase using a for loop that uses the tolower
// command to change the word to lowercase character by character
void to_lowercase(string &str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
}
// Pass by value function that converts a string to uppercase using a for loop that uses the toupper
// command to change the word to uppercase character by character and then the uppercase string is returned
string to_uppercase_copy(string str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
		
	return str;
}
// Pass by value function that converts a string to lowercase using a for loop that uses the tolower
// command to change the word to lowercase character by character and then the lowercase string is returned
string to_lowercase_copy(string str) {
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
		
	return str;
}
// Pass by reference function that left trims a string by erasing any space before the first nonspace charcter
void ltrim(string &str) {
	str.erase(0, str.find_first_not_of("\t\n\r\v\f "));
}
// Pass by reference function that right trims a string by erasing any space after the first nonspace charcter
void rtrim(string &str) {
	str.erase(str.find_last_not_of("\t\n\r\v\f ") + 1);
}
// Pass by reference function that trims a string by erasing any space before and after the first nonspace charcter
void trim(string &str) {
	str.erase(0, str.find_first_not_of("\t\n\r\v\f "));
	str.erase(str.find_last_not_of("\t\n\r\v\f ") + 1);
}
// Pass by value function that left trims a string by erasing any space before the first
// nonspace charcter and then returns the string
string ltrim_copy(string str) {
	str.erase(0, str.find_first_not_of("\t\n\r\v\f "));
	return str;
}
// Pass by value function that right trims a string by erasing any space after the first
// nonspace charcter and then returns the string
string rtrim_copy(string str) {
	str.erase(str.find_last_not_of("\t\n\r\v\f ") + 1);
	return str;
}
// Pass by value function that trims a string by erasing any space before and after
// the first nonspace charcter and then returns the string
string trim_copy(string str) {
	str.erase(0, str.find_first_not_of("\t\n\r\v\f "));
	str.erase(str.find_last_not_of("\t\n\r\v\f ") + 1);
	return str;
}