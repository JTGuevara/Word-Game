/*
FILE: startGame.cpp
DESCRIPTION: A function definition.
*/

#include <forward_list> 	//STL data structure for word list
#include <fstream> 			//C++ IO library for retrieving words from a file
#include <algorithm> 		//For shuffling algorithm(std::shuffle) used to scramble words
#include <random> 			//For random number generator(std::random_device) and number engine(std::mt19937) used in shuffling algorithm
//#include <cassert>			//For testing preconditions

#include "GameTimer.hpp"
std::string scrambleWord(std::string word);
//Scrambles the given word and returns a copy. Returns an error if word is empty or less than 2 letters.


std::string retrieveNextWord(std::forward_list<std::string> &WordList, const std::size_t &LIST_SIZE);
/*Retrieves the next word in the given word list and returns it. The list is modified such that it cycles the list forward, with the word in the
* front of the list pushed to the back and the next word in sequence becoming the new front. This function is intended to work with with lists 
* no smaller than two words. Returns an error if the list is empty or has less than 2 words.
* 		PARAMETERS: WordList - word list for modifying and retrieving next word
*					LIST_SIZE - list size used to check for a valid list
*/


void startGame(){
    //Game data
	struct Player{
		std::size_t score;
		std::string response;
	};
	Player player;
	player.score = 0;
	std::forward_list<std::string> WordList;
	const std::size_t LIST_SIZE = 5;
	std::string word;
	std::string scrambledWord;
	std::size_t points = 0;
	GameTimer timer;
	
    //Set of statements to fill word list
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
			++i;
		}
		
		file.close();
	}
	
	//Game loop
	while(timer.getDuration() < 10){
		//Set of statements to scramble and supply a word for player to solve
		word = WordList.front();
		scrambledWord = scrambleWord(word);
		
		timer.startTimer();
		
		std::cout << "\nWord: " << scrambledWord; 
		std::cout << "\nResponse: ";
		std::cin >> player.response;
		
		//Player response loop to make sure the response is correct
		while(player.response != word){
			timer.tick();
			std::cout << "\nNope! Try again!\n";
			std::cout << "\nResponse: ";
			std::cin >> player.response;
		}
		
	   //Set of statements executed when response is correct
	   std::cout << "\n\nCorrect!\n";
	   points = word.length() * 100;
	   player.score += points;
	   std::cout << "\n- - - - - - - -";
	   std::cout << "\nScore: " << player.score << " pts"; 
	   std::cout << "\n- - - - - - - -";
	   
	   timer.endTimer();
	   word = retrieveNextWord(WordList, LIST_SIZE);
	   timer.printTime();
	}
	std::cout << "\nGame over!";
    //End game
}


std::string scrambleWord(std::string word){
	//check for valid word
	//assert(word.length() >= 2 || word != "");
	
	std::string scrambledWord = word;
	
	//To scramble the given word, a random number generator along with randomizing 
	//and shuffling algorithms are used to shuffle each letter
	std::random_device generator;
	std::mt19937 randomizingAlgorithm(generator());
	std::shuffle(scrambledWord.begin(), scrambledWord.end(), randomizingAlgorithm);
	return scrambledWord;
}



std::string retrieveNextWord(std::forward_list<std::string> &WordList, const std::size_t &LIST_SIZE){
	//check for a valid list
	//assert(LIST_SIZE >= 2 || !WordList.empty());
	
	//To retrieve the next word, the following set of statements modify the list 
	//such that it cycles forward
	std::string tempFront = WordList.front();
	WordList.pop_front();
	WordList.reverse();
	WordList.push_front(tempFront);
	WordList.reverse();
	
	return WordList.front();
}

