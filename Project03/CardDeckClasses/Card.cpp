/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 1
 * Card Object Implimentation
 */
#include "Card.h"
// Default Constructor
Card::Card() {
	value = 0;
	suit = 0;
}
// Constructor 
Card::Card(int v, int s) {
	value = v;
	suit = s;
}
// Function to convert a card number to a face value stored as a string
string Card::toStringFace() {
	
	string face = "";
	// Statement to determine which face value to return based on the value;
	if (value == 11) {
		face = "J";
	}
	else if (value == 12) {
		face = "Q";
	}
	else if (value == 13) {
		face = "K";
	}
	else if (value == 1) {
		face = "A";
	}
	else {
		face = to_string(value);
	}
	return face;
}
// Function to convert a suit number to a suit represented by a letter and stored in a string
string Card::toStringSuit() {
	
	string type = "";
	// Statement to determine which suit type to return based on the suit number;
	if (suit == 1) {
		type = "D";
	}
	else if (suit == 2) {
		type = "C";
	}
	else if (suit == 3) {
		type = "H";
	}
	else if (suit == 4) {
		type = "S";
	}
	return type;
}
// Function to test if two cards are identical, including value and suit
bool Card::equals(Card card2) {
	
	bool status = false;
	// Sets status to true if the value and suit are equal
	if (value == card2.value && suit == card2.suit) {
		status = true;
	}
	return status;
}
// Function to convert a card with a number for value and suit to a string representation that symbolizes a playing card
string Card::toString() {
	
	return (toStringFace() + toStringSuit());
	
}
// Function to convert a card with a number for value and suit to a string representation that symbolizes a playing card with possibility of a space separation
string Card::toString(bool space) {
	
	string full = "";
	// Statement to determine if a space should be used to seperate values based upon parameter
	if (space) {
		full = toStringFace() + " " + toStringSuit();
	}
	else {
		full = toStringFace() + toStringSuit();
	}
	return full;
}
// Function to determine if a card is greater than other card by comparing their values
bool Card::greater(Card card2) {
	
	bool status = false;
	// Sets status to true if left value is greater than right value
	if (value > card2.value) {
		status = true;
	}
	return status;
}