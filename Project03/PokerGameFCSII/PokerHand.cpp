/* Kyle Tranfaglia
 * 12/08/22
 * Project#3 - Exercise 4
 * PokerHand Object Implimentation
 */
#include "PokerHand.h"
// Constructor
PokerHand::PokerHand() {
}
// Function to clear a player's hand by defaulting cards in hand and the cards in the hand
void PokerHand::clearHand() {
	cardsInHand = 0;
}
// Function to add a card to a players hand by assigning the dealth card to the player hand array and incrementing cards in hand
void PokerHand::addToHand(Card card) {
	hand[cardsInHand++] = card;
}
// Function to print the players hand with a space between each card and call and diaply the handtype function
void PokerHand::PrintHand() {
	// Loop to print each card in the players hand separated by a space
	for (int i = 0; i < cardsInHand; i++) {
		cout << " " << hand[i].toString();
	}
	cout << "  ---  " << handType() << endl;
}
// Function to print the players hand spaced with a width specified by the user sent as a parameter and call and diaply the handtype function
void PokerHand::PrintHand(int width) {
	// Loop to print each card in the players hand separated by a distance specified by the width parameter
	for (int i = 0; i < cardsInHand; i++) {
		cout << setw(width) << hand[i].toString();
	}
	cout << setw(width + 3) << "---  " << handType() << setw(width) << endl;
}
// Function to sort a player's hand of cards using a insertion sort and comparing card face values
void PokerHand::sortHand() {
	// For loop to sort the array by going through each element and while the value at one index ahead of another index is greater, that the
	// element is moved to the next larger index and this continues until the the element is no longer larger than the next index
	for (int i = 1; i < cardsInHand; i++) {
		Card temp = hand[i];
		int loc = i - 1;
		while (loc >= 0 && hand[loc].greater(temp)) {
			hand[loc + 1] = hand[loc];
			loc--;
		}
		hand[loc + 1] = temp;
	}
}
// Function to determine the hand type of a player's hand by using a series of loops and comparisons to check for each hand type and return the string of the type name
string PokerHand::handType() {
	
	string type = "";
	int straightCount = 0, suitCount = 0, kindCount = 0, value1 = 0, value2 = 0;
	bool royal = false, threeConsequative = false, fourConsequative = false;
	// Loop to keep a count for multiple testing scenarios to determine identical suits, values, and sequentials
	for (int i = 0; i < 4; i++) {
		value1 = FaceToNum(hand[i].toStringFace()); // Calls Function to convert the string of the face value back to a number
		value2 = FaceToNum(hand[i + 1].toStringFace()); // Calls Function to convert the string of the face value back to a number
		// Statement to determine if sorted hand is sequential by determining if it is incrementing by 1 and keeps a count
		if (value1 + 1 == value2) {
			straightCount++;
		}
		// Statement to determine if a card and its latter are the same suit and keeps a count
		if (hand[i].toStringSuit() == hand[i + 1].toStringSuit()) {
			suitCount++;
		}
		// Statement to determine if a face value and its latter are the same and keeps a count
		if (hand[i].toStringFace() == hand[i + 1].toStringFace()) {
			kindCount++;
		}
	}
	// Loop to run 3 times to prevent reading past array and checks the three different possibilities of three cards in a row and keeps a count
	for (int i = 0; i < 3; i++) {
		if (hand[i].toStringFace() == hand[i + 1].toStringFace() && hand[i + 1].toStringFace() == hand[i + 2].toStringFace()) {
			threeConsequative = true;
		}
	}
	// Statement to check if card 1 and 4 are equal or 2 and 5 are equal and sets variable to true as it signifies that there are 4 kinds in a row
	if (hand[0].toStringFace() == hand[3].toStringFace() || hand[1].toStringFace() == hand[4].toStringFace()) {
		fourConsequative = true;
	}
	// Statement to check if hand is a royal hand by checking if each card meets the requirments and if so sets variable to true
	if (hand[0].toStringFace() == "A" && hand[1].toStringFace() == "10" && hand[2].toStringFace() == "J" &&
		hand[3].toStringFace() == "Q" && hand[4].toStringFace() == "K") {
		royal = true;
	}
	// Statement to check a specific scenario for a straight count in which the Ace needs to be a 14 and not a 1, and increments coutn i true
	if (FaceToNum(hand[0].toStringFace()) + 12 == FaceToNum(hand[4].toStringFace())) {
		straightCount++;
	}
	// Extensive statement in order to assign a hand type if the comparison is true from of best to worst hand possibilities
	// Statement runs until a true match is meet in the list or it hits the else
	if (straightCount == 4 && suitCount == 4 && royal) {
		type = "Royal Flush";
	}
	else if (straightCount == 4 && suitCount == 4) {
		type = "Straight Flush";
	}
	else if (kindCount == 3 && fourConsequative) {
		type = "Four of a Kind";
	}
	else if (kindCount == 3) {
		type = "Full House";
	}
	else if (suitCount == 4) {
		type = "Flush";
	}
	else if (straightCount == 4) {
		type = "Straight";
	}
	else if (kindCount == 2 && threeConsequative) {
		type = "Three of a Kind";
	}
	else if (kindCount == 2) {
		type = "Two Pair";
	}
	else if (kindCount == 1) {
		type = "One Pair";
	}
	else {
		type = "High Card";
	}
	return type;
}
// Function to convert a string of a face card to an integer value
int PokerHand::FaceToNum(string str) {
	
	int num = 0;
	// Statement to assign an integer value to a string face by comparing the string to particular cases, and if none match
	// it is able to access the first element of the string and convert it to a integer by substracting 0
	if (str == "10") {
		num = 10;
	}
	else if (str == "J") {
		num = 11;
	}
	else if (str == "Q") {
		num = 12;
	}
	else if (str == "K") {
		num = 13;
	}
	else if (str == "A") {
		num = 1;
	}
	else {
		num = str[0] - '0';
	}
	return num;
}