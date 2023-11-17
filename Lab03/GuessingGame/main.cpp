/* Kyle Tranfaglia
 * 09/26/22
 * Lab#3 - Exercise 8
 * This program generates a random number between 1 and 100 and guides the user to guessing the number
 * The user is informed if the guess is too high or too low
 */
 #include <iostream>
 #include <cstdlib>
 #include <ctime>

 int main ()
 {
	 using namespace std;
	 
	 // Variables
	 int number = 0, guess = 0, i = 1;
	 
	 srand(time(0)); // Sets the seed of the random number generator
	 
	 number = (rand() % 100) + 1;
	 
	 cout << "Enter your guess: ";
	 cin >> guess;
	 
	 // This starts as an if statement to assess if the guess is correct or not. If not, a while loop
	 // starts that will run until i is equal to 7. Then another if statement is used to assess again
	 // if the guess is right for each re-guess and the nested if statement determines if the guess 
	 // was too low or too high. Once the guess if correct, the user is congratulated and a return is
	 // used to terminate the loop. If the user is wrong for 7 guesses, the loop ends and the user is
	 // informed of the loss using an if statement outside of the while loop.
	 if (guess != number){
		 while (i < 7){
			 if (guess != number){
				 i++;
				 if (guess > number) {
					 cout << "Too high, try again\n";
					 cout << "Enter your guess: ";
					 cin >> guess;
					}
				 else {
					 cout << "Too low, try again\n";
					 cout << "Enter your guess: ";
					 cin >> guess;
					}
				 }
			 else {
				 cout << "Congratulations, your guess was correct!\n";
				 return 0;
			 }
		 }
	 }
	 else 
		 cout << "Congratulations, your guess was correct!\n";
	 if (i == 7)
		 cout << "Your 7 guesses are up, you lose\n";
		 
	 return 0;
 }