/* Kyle Tranfaglia
 * 10/3/22
 * Homework#3 - Exercise 3
 * This program will read in from a file integer numbers and determine the minimum and maximum of those numbers
 */
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;

    // Variables
	ifstream inputFile;
	ofstream outputFile;
	int shift = 0;
	string fileName = "", message = "", dMessage = "", eMessage = "", newMessage = "", fullMessage = "";
	char direction = ' ';
	
	cout << "Input the fileName: ";
	cin >> fileName;
	
	inputFile.open("HW03Files/" + fileName);
	
	// Loop is used to check if the file opened. If the file opened correctly, the program skips over this block
	// of code. If there is a problem opening the file, the comparison is true and an error message will be displayed 
	// and the user will be instructed to the file name again. Loop runs until file successfully opens
	while (!inputFile) {
		cout << "Invalid filename, file " << fileName << " not found\n";
		cout << "Input the fileName: ";
		cin >> fileName;
		inputFile.open("HW03Files/" + fileName);
	}
	// While loop reads in the file by getting one line at a time. For Loop runs for length of the line. The if statement 
	// within the loop goes through each character. If the character contains an alphabetical character, it is set to
	// uppercase and placed in a newMessage string. This is reapeated for all lines and the upercase lines are concatenated
	// and stored as one string
	while (getline(inputFile, message)) {
	for (unsigned int i = 0; i < message.length(); i++) {
        if ((message[i] >= 'A' && message[i] <= 'Z') || (message[i] >= 'a' && message[i] <= 'z')) {
            newMessage += toupper(message[i]);
        }
	}
	fullMessage += newMessage;
	}
	inputFile.close();
	
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
	// within the for loop. The modulo 26 is used to keep the characters from being converted to a letter outside of the alphabet.
	// A corresponding output file is opened encryption and decryption, and the results of each are written into the opened file
	if (direction == 'E') {
		outputFile.open("HW03Files/CipherInputFile.txt.out.txt");
		for (unsigned int i = 0; i < fullMessage.length(); i++){
			eMessage += (fullMessage[i] -'A'+ shift) % 26 + 'A';
		}
		outputFile << eMessage << endl;
	}
	else {
		outputFile.open("HW03Files/CipherInputFile.txt.out.txt.out.txt");
		for (unsigned int i = 0; i < fullMessage.length(); i++){
			dMessage += (fullMessage[i] -'A'- shift + 26) % 26 + 'A';
	}
		outputFile << dMessage << endl;
	}
	outputFile.close();
	
	return 0;
}