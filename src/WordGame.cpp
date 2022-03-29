/*
FILE: WordGame.cpp
DESCRIPTION: Word Game Application
*/
#include <iostream>

int main(){
	unsigned int choice;//choice used for user prompt
	
	std::cout << "-------------------------\n";
	std::cout << "\tWORD GAME\n";
	std::cout << "-------------------------\n";
	std::cout << "\nWelcome to Word Game! Type 1 or 2 to continue: ";
	std::cout << "\n   1. Play\n";
	std::cout << "   2. Quit\n";
	
	std::cin >> choice;
	//while loop to check for valid input
	while(choice != 1 && choice != 2){
		std::cout << "Invalid selection. Try again: ";
		std::cin >> choice;
	}

	while(choice == 1){
		std::cout << "Running game...";
		
		std::cout << "Play again?\n";
		std::cout << "\n   1. Play\n";
		std::cout << "   2. Quit\n";
		std::cout << "Type 1 or 2 to continue: ";
		std::cin >> choice;
		
		//while loop to check for valid input
		while(choice != 1 && choice != 2){
			std::cout << "Invalid selection. Try again: ";
			std::cin >> choice;
		}
	}
	std::cout << "\nEnding program...";
	return 0;
}