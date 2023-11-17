/* Kyle Tranfaglia
 * 11/17/22
 * Homework#10 - Exercise 1
 * This program uses a strucure to store data about a soccer player
 */
#include <iostream>
#include <vector>

using namespace std;

// Struct for player information
struct Player {
	string name = "";
	int number = 0;
	int scored = 0;
};
// Prototypes
int menuselect();
void addPlayer(vector<Player> &);
void removePlayer(vector<Player> &);
Player findMVP(const vector<Player> &);
int getTotalPoints(vector<Player> &);
void printPlayerInfo(Player);
void printTeamInfo(vector<Player> &);

int main() {
	// Variables
    vector<Player> team;
    bool running = true;
	// Loop to run program until user wants to quit, in which entering 6 chnages running to false and loop terminates.
	// Nested Switch statement used to call the function necessary to perform the task selected by user
    while (running) {
		int selection = menuselect();
		switch (selection) {
		case 1:
			addPlayer(team);
			break;
		case 2:
			removePlayer(team);
			break;
		case 3:
			if (team.size() > 0)
				printPlayerInfo(findMVP(team));
			else
				cout << "No players on the team." << endl;
			break;
		case 4:
			cout << "Total Team Points = " << getTotalPoints(team) << endl;
			break;
		case 5:
			printTeamInfo(team);
			break;
		case 6:
			running = false;
		}
    }
    return 0;
}
// Function to display the menu and take in a user input for menu selection and then return this to the main as an integer
int menuselect() {
	
	int selection = 0;
	// Console menu display
	cout << "\nOptions\n-------" << endl;
	cout << "1: Add Player\n2: Remove Player\n3: Find MVP\n4: Calculate Total Team Points\n5: Print Team Information\n6: Quit" << endl;
	cout << "Selection: ";
	cin >> selection;
	cin.ignore();
	cout << endl;
	// Input validation loop to only accept menu options
	while (selection < 1 || selection > 6) {
		cout << "Invalid Input! Select an option 1-6" << endl;
		cout << "Selection: ";
		cin >> selection;
	}
	return selection;
}
// Function to add a player to the team vector of players by updating the referenced vector with a pushback 
void addPlayer(vector<Player> &team) {
	
	Player playerStorage;
	
	cout << "Input Player Name: ";
	getline(cin, playerStorage.name);
	
	cout << "Input Player Number: ";
	cin >> playerStorage.number;
	// Input validation loop for if the input for player number is negative
	while (playerStorage.number < 0) {
		cout << "Invalid Input!" << endl;
		cout << "Input Player Number: ";
		cin >> playerStorage.number;
	}
	// Input validation loop that checks if the entered player number has already been enetered for another player 
	for (unsigned int i = 0; i < team.size(); i++) {
		if (team[i].number == playerStorage.number) {
			cout << "Invalid Input! This player number was already entered" << endl;
			cout << "Input Player Number: ";
			cin >> playerStorage.number;
			i = -1;
		}
	}
	cout << "Input Player's Points: ";
	cin >> playerStorage.scored;
	// Loop to check if points scored is positive and will run until a positive input is enetered
	while (playerStorage.scored < 0) {
		cout << "Invalid Input!";
		cout << "Input Player's Points: ";
		cin >> playerStorage.scored;
	}
	team.push_back(playerStorage); // Doubles the size of vector if size is reached, and then adds player to last index of vector
}
// Function to remove a player from the team vector of players by updating the referenced vector with erase function
void removePlayer(vector<Player> &team) {
	
	int remove = 0;
	
	cout << "Team List\n---------" << endl;
	cout << "0: Skip" << endl;
	// Loop to display a numbered list starting at 1 of all the players by name only
	for (unsigned int i = 0; i < team.size(); i++) {
		cout << i + 1 << ": " << team[i].name << endl;
	}
	cout << "Remove Player: ";
	cin >> remove; 
	// Input validation loop to only accept values between 0 and the vector size
	while (remove < 0 || remove > team.size()) {
		cout << "Invalid input! Please choose a number option in the list above" << endl;
		cout << "Remove Player: ";
		cin >> remove;
	}
	// If statement that removes the selected player as long as the quit option 0 was not selected
	if (remove != 0) {
		team.erase(team.begin() + remove - 1); // Removes position remove spaces to the right of beginning index minus 1
	}
}
// Function to find the mvp of the team by determing which player scored the most points and return the player
Player findMVP(const vector<Player> &team) {
	
	Player mvp = team[0]; // Sets defualt mvp as first player
	int highest = team[0].scored; // sets default highest score as first players scored
	// For loop to compare all player scores and return the player with the highest score. Loop starts at 1 as first player is already defaulted to MVP 
	// and if there is only 1 player, the loop does not need to run. Nested if Statement used to compare player scores and update highest score and MVP
	for (unsigned int i = 1; i < team.size(); i++) {
		if (team[i].scored > highest) {
			highest = team[i].scored;
			mvp = team[i];
		}
	}
	return mvp;
}
// Function to get the total points scored by the team and return the integer total
int getTotalPoints(vector<Player> &team) {
	
	int totalPoints = 0;
	// For loop to go through each player in the team vector and keep a running total of each player's score
	for (unsigned int i = 0; i < team.size(); i++) {
		totalPoints += team[i].scored;
	}
	return totalPoints;
}
// Function to print the information of a singler player sent in as a parameter
void printPlayerInfo(Player p) {
	
	// Prints each of the values stored in player struct
	cout << p.name << endl;
	cout << "Number: " << p.number << endl;
	cout << "Points Scored: " << p.scored << endl;
}
// Function to print the information for the entire team, including all players and their information, the total points, and the MVP
void printTeamInfo(vector<Player> &team) {
	// For loop to go through every player in the team vector and call teh print player function for each player
	for (unsigned int i = 0; i < team.size(); i++) {
		printPlayerInfo(team[i]);
		cout << endl;
	}
	// Calls two functions and prints them to display the total points scored by the team and the MVP
	cout << "Total Team Points = " << getTotalPoints(team) << endl;
	cout << "MVP is " << findMVP(team).name << endl;
}