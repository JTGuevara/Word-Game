/*
FILE: startGame.cpp
DESCRIPTION: A function definition.
*/

#include <forward_list> 	//STL data structure for word list
#include <fstream> 			//C++ IO library for retrieving words from a file
#include <algorithm> 		//For shuffling algorithm(std::shuffle) used to scramble words
#include <random> 			//For random number generator(std::random_device) and number engine(std::mt19937) used in shuffling algorithm
#include <cassert>			//For testing preconditions

#include "GameTimer.hpp"	


void fillWordList(std::forward_list<std::string> &WordList);
/*	Fills the given word list with words retrieved from a file.
*		PARAMETERS: WordList - word list to modify
*		THROWS: Exception if a file is not found in the given directory.
*/

std::size_t calculateListSize(std::forward_list<std::string> &WordList);
/* Calculates and returns the size of the given word list.
*		PARAMETERS: WordList - word list to traverse
*/

std::string scrambleWord(std::string word);
/* Scrambles the given word and returns a copy. Returns an error if word is empty or less than 2 letters.
*		PARAMETERS: word - word to scramble
*/


std::string retrieveNextWord(std::forward_list<std::string> &WordList, std::size_t &listSize);
/* 	Retrieves the next word in the given word list and returns it. The list is modified such that it cycles the list forward, 
*	with the word in the front of the list pushed to the back and the next word in sequence becoming the new front. This function 
*	is intended to work with with lists no smaller than two words. Returns an error if the list is empty or has less than 2 words.
* 		PARAMETERS: WordList - word list for modifying and retrieving next word
*					listSize - list size used to check for a valid list
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
	std::size_t listSize = 0;
	std::string word;
	std::string scrambledWord;
	std::size_t points = 0;
	GameTimer timer;
	
	fillWordList(WordList);
	
	listSize = calculateListSize(WordList);
	
	//Game loop(where 10 = number of seconds)
	while(timer.getDuration() < 10){
		//Set of statements to scramble and supply a word for player to solve
		word = WordList.front();
		scrambledWord = scrambleWord(word);
		
		timer.startTimer();
		
		std::cout << "\n\n\tWord: " << scrambledWord; 
		std::cout << "\n\tResponse: ";
		std::cin >> player.response;
		
		//Player response loop to make sure the response is correct
		while(player.response != word){
			timer.tick();
			std::cout << "\nNope! Try again!\n";
			std::cout << "\n\tWord: " << scrambledWord;
			std::cout << "\n\tResponse: ";
			std::cin >> player.response;
		}
		
	   //Set of statements executed when response is correct 
	   timer.endTimer();
	   std::cout << "\n\nCorrect!\n";
	   points = word.length() * 100;
	   player.score += points;
	   std::cout << "\n- - - - - - - -";
	   std::cout << "\nScore: " << player.score << " pts"; 
	   std::cout << "\n- - - - - - - -";
	   timer.printTime();
	   std::cout << "\n- - - - - - - -\n";
	   word = retrieveNextWord(WordList, listSize);
	   
	}
	
	//Statements executed on player defeat
	std::cout << "\n\nTime's up!";
	std::cout << "\n- - - - - - - - - - -";
	std::cout << "\nTotal Score: " << player.score << " pts"; 
	std::cout << "\n- - - - - - - - - - -";
	timer.printTime();
	std::cout << "\n- - - - - - - - - - -";
	
	//Slight time delay until game over message so player has
	//time to process in-game results
	timer.reset();
	timer.startTimer();
	while(timer.getDuration() < 3){
		timer.tick();
	}
	timer.endTimer();
	std::cout << "\n\tGame over! ";
}


void fillWordList(std::forward_list<std::string> &WordList){
	//local variables used to read from a file
	std::string wordRead;
	std::ifstream file;
	
	//try-catch statement to attempt to open a file
	try{
		//file directory - make sure to change this if the file is moved!
		file.open("../words/word_directory.txt");
		//check for potential errors in opening file
		if(file.fail()){
			throw std::exception();
		}
	}
	catch(std::exception &e){
		std::cout << "Error: Could not open file!\n";
		exit(1);
	}
		
	//while loop to read each word from the file and add it to the word list
	while(!file.eof()){
		file >> wordRead;
		WordList.push_front(wordRead);
	}
		
	file.close();
}



std::size_t calculateListSize(std::forward_list<std::string> &WordList){
	std::size_t size = 0;//size to return
	std::forward_list<std::string>::iterator it;//iterator to traverse a list
	
	//to calculate the list size, the list is traversed
	for(it = WordList.begin();it != WordList.end();++it)
		++size;
	
	return size;
}



std::string scrambleWord(std::string word){
	//check for valid word
	//assert(word != "");
	//assert(word.length() >= 2);
	
	std::string scrambledWord = word;
	
	//To scramble the given word, a random number generator along with randomizing 
	//and shuffling algorithms are used to shuffle each letter
	std::random_device generator;
	std::mt19937 randomizingAlgorithm(generator());
	std::shuffle(scrambledWord.begin(), scrambledWord.end(), randomizingAlgorithm);
	return scrambledWord;
}



std::string retrieveNextWord(std::forward_list<std::string> &WordList, std::size_t &listSize){
	//check for a valid list
	//assert(!WordList.empty());
	//assert(listSize >= 2);
	
	//To retrieve the next word in the list, the following set of statements modify the list 
	//such that it cycles forward one position. 
	std::string tempFront = WordList.front();
	WordList.pop_front();
	WordList.reverse();
	WordList.push_front(tempFront);
	WordList.reverse();
	
	return WordList.front();
}

