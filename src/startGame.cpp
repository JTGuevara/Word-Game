/*
FILE: startGame.cpp
DESCRIPTION: A function definition.
*/

#include <forward_list> 	//STL data structure for word list
#include <fstream> 			//C++ IO library for retrieving words from a file
#include <algorithm> 		//For shuffling algorithm(std::shuffle) used to scramble words
#include <random> 			//For random number generator(std::random_device) and number engine(std::mt19937) used in shuffling algorithm
#include <cassert> 			//For testing preconditions.

#include "GameTimer.hpp"
std::string scrambleWord(std::string word);
//Scrambles the given word and returns a copy. Returns an error if word is empty or less than 2 letters.


void startGame(){
	////////TO DO///////
	
    //Declare game data:
		//Player, WordList, Timer, score, letterCount, points, etc.
	std::forward_list<std::string> WordList;
	const std::size_t LIST_SIZE = 5;
	std::string word;
	std::string scrambledWord;
	std::size_t points = 0;
	GameTimer timer;
	std::string playerResponse;
	
    //Fill word list
	{
		//local variables used to read from a file
		int i = 0;
		std::string wordsRead[LIST_SIZE];
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
		word = WordList.front();
        //Scramble word and give to player to solve
		scrambledWord = word;
		std::cout << "\n\nWORD SCRAMBLE TEST\n------------------";
		std::cout << "\nWord before scramble: " << scrambledWord;
		scrambledWord = scrambleWord(word);
		std::cout << "\nWord after scramble: " << scrambledWord;
	
        //Set timer
		std::cout << "\n\n\nTIMER TEST\n-----------";
		timer.startTimer();
		while(!timer.isUp(3)){
			timer.tick();
		}
		timer.endTimer();
		timer.printTime();
		timer.startTimer();
		
        //Prompt player to solve(unscramble) and type correct word:
		std::cout << "\n\n\nPLAYER TEST\n----------------";
		std::cout << "\nWord: " << scrambledWord; 
		std::cout << "\nResponse: ";
		std::cin >> playerResponse;
		
		// WHILE word is not solved:
		while(playerResponse != word){
			timer.tick();
			//> Prompt user to type again:
			std::cout << "\nNope! Try again!\n";
			std::cout << "\nResponse: ";
			std::cin >> playerResponse;
		}
       //Calculate and give points
	   std::cout << "\n\nCorrect!\n";
	   points += word.length() * 100;
	   std::cout << "\n- - - - - - - -";
	   std::cout << "\nScore: " << points << " pts"; 
	   std::cout << "\n- - - - - - - -";
	   
	   timer.endTimer();
	   timer.printTime();
	
	std::cout << "\nGame over!";
    //End game
}

std::string scrambleWord(std::string word){
	//check for valid word
	assert(word.length() >= 2 || word != "");
	
	std::string scrambledWord = word;
	
	//To scramble the given word, a random number generator along with randomizing 
	//and shuffling algorithms are used to shuffle each letter
	std::random_device generator;
	std::mt19937 randomizingAlgorithm(generator());
	std::shuffle(scrambledWord.begin(), scrambledWord.end(), randomizingAlgorithm);
	return scrambledWord;
}


