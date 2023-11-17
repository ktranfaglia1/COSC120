/* Kyle Tranfaglia
 * 09/23/22
 * Homework#2 - Exercise 6
 * This program does a simple Caesar cipher on an input message
 */
#include <iostream>
#include <string>

int main()
{
    using namespace std;

    // Variables
	int shift = 0;
	string message = "", dMessage = "", eMessage = "", newMessage = "";
	char direction = ' ';
	
	cout << "Input the message: ";
	getline (cin, message);
	
	// Loop runs for length of the inputted message. The if statement within the loop goes through each character.
	// If the character contains an alphabetical character, it is set to uppercase and placed in a newMessage string
	for (unsigned int i = 0; i < message.length(); i++) {
        if ((message[i] >= 'A' && message[i] <= 'Z') || (message[i] >= 'a' && message[i] <= 'z')) {
            newMessage += toupper(message[i]);
        }
	}
	message = newMessage;
	
	cout << "Input the shift (0 - 25): ";
	cin >> shift;
	
	// Invalid input check. Loop runs if the user input is less than 0 or more than 25. An error message will appear
    // and the user will be instructed to enter a value again. This continues until a suitable input is read
	while (shift < 0 || shift > 25) {
		cout << "Invalid input, please input a number (0 - 25)\n";
		cout << "Input the shift (0 - 25): ";
		cin >> shift;
	}
	cout << "Input E to encrypt and D to decrypt: ";
	cin >> direction;
	
	direction = toupper(direction);
	
	// Invalid input check. Loop runs if the user input is not E or D after being converted to uppercase. An error message
    // will appear and the user will be instructed to enter a value again. This continues until a suitable input is read
	while (direction != 'E' && direction != 'D'){
		cout << "Invalid input, please input E or D\n";
		cout << "Input E to encrypt and D to decrypt: ";
		cin >> direction;
		direction = toupper(direction);
	}
	// If statement containg for loops is used to encrypt and decrypt the message. If the used input was E, the encryption loop
	// runs. This loop runs through each character in the string. Each character has the shift added to it and then is placed
	// in a new string of characters. The same occurs for the else (decryption) except the shift is subracted in the equation 
	// within the for loop. The modulo 26 is used to keep the characters from being converted to a letter outside of the alphabet
	if (direction == 'E'){
		for (unsigned int i = 0; i < message.length(); i++){
			eMessage += (message[i] -'A'+ shift) % 26 + 'A';
		}
		cout << "Encrypted Message: " << eMessage << endl;
	}
	else {
		for (unsigned int i = 0; i < message.length(); i++){
			dMessage += (message[i] -'A'- shift + 26) % 26 + 'A';
	}
		cout << "Decrypted Message: " << dMessage << endl;
	}
	
	return 0;
}