/*
FILE: WordGame.cpp
DESCRIPTION: Word Game Application
*/
#include <iostream>

//void startGame - Runs the game. The game runs indefinitely until the player loses or quits.
void startGame();

int main(){
	unsigned int choice;//choice used for user prompt
	
	std::cout << "\n";
	std::cout << "\t* * * * * * * * * * * * * *\n";
	std::cout << "\t*\tWORD BLAST\t  *\n";
	std::cout << "\t* * * * * * * * * * * * * *\n";
	std::cout << "\nWelcome to Word Blast! Type 1 or 2 to continue: ";
	std::cout << "\n\t   1. Play\n";
	std::cout << "\t   2. Quit\n";
	
	std::cin >> choice;
	//while loop to check for valid input
	while(choice != 1 && choice != 2){
		std::cout << "Invalid selection. Try again: ";
		std::cin >> choice;
	}

	while(choice == 1){
		startGame();
		
		std::cout << "Play again?\n";
		std::cout << "\n\t   1. Play\n";
		std::cout << "\t   2. Quit\n";
		std::cout << "\tType 1 or 2 to continue: ";
		std::cin >> choice;
		
		//while loop to check for valid input
		while(choice != 1 && choice != 2){
			std::cout << "Invalid selection. Try again: ";
			std::cin >> choice;
		}
	}
	std::cout << "\nThanks for playing!";
	return 0;
}



