/*
FILE: startGame.cpp
DESCRIPTION: A function definition.
*/

#include <forward_list> //STL data structure for word list
#include <fstream> //C++ IO library for retrieving words from a file

void startGame(){
	////////TO DO///////
	
    //Declare game data:
		//Player, WordList, Timer, score, letterCount, points
	std::forward_list<std::string> WordList;
	
    //Fill word list
	{
		//local variables used to read from a file
		int i = 0;
		std::string wordsRead[5];
		std::ifstream file;
		
		//file directory - make sure to change this if the file is moved!
		file.open("../words/word_directory.txt");
		
		//check for potential errors in opening file
		if(file.fail()){
			std::cout << "Error in opening file!\n";
			exit;
		}
		
		//while loop to read each word from the file and add it to the word list
		while(!file.eof()){
			file >> wordsRead[i];
			WordList.push_front(wordsRead[i]);
			std::cout << "Word List Test: " << WordList.front() << "\n";
			++i;
		}
		
		file.close();
	}
    //WHILE player has not lost(Timer = 0) or quit:
        //Retrieve a word from the word list
        //Scramble word and give to player to solve
        //Set timer
        //Prompt player to solve(unscramble) and type correct word:
		// WHILE word is not solved:
			//> Prompt user to type again:
       //Calculate and give points
    //End game
}