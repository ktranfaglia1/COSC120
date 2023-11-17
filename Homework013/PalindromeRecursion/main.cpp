/* Kyle Tranfaglia
 * 12/12/22
 * Homework#13 - Exercise 2
 * Program to use a recursive function to determine if a user entered string is palindrome 
 */
#include <iostream>
#include <string>

using namespace std;

// Recursion Prototype
bool isPal(const string& str, int startIndex, int endIndex);

int main() {
	
	string str = "";
	
	cout << "Enter a string, no spaces and all lower case: ";
	cin >> str;
	// Statement to call recursive function and if it returns true, states it is a palindrome, and if false, states not
	if (isPal(str, 0, str.length() - 1)) {
		cout << str << " is a palindrome" << endl;
	}
	else {
		cout << str << " is not a palindrome" << endl;
	}
	
	return 0;	
}
// Recursive function to return a a bool of whether or not a word is a palindrome by comparing a word from the outside to the inside recursively
bool isPal(const string& str, int startIndex, int endIndex) {
	// Base case statement to compare starting and ending index and if they are equal, returns true
	if (startIndex == endIndex) {
		return true;
	}
	// Statement to compare the characters at the corresponding string indexes to test if palindrome, and if not equal, returns value
	else if (str[startIndex] != str[endIndex]) {
		return false;
	}
	// Statement to compare starting and ending index variables and if starting index is still less than end index plus one, it recurses
	else if (startIndex < endIndex + 1) {
		return isPal(str, startIndex + 1, endIndex - 1);
	}
	return true; // Returns true if start index becomes larger than end index, meaning all the indexes must have been equal
}