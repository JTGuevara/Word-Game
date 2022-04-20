/*
FILE: GameTimer.hpp
DESCRIPTION: Class definition for in-game timer. A timer stores the points in time the timer was started and ended as well as
			the total duration and current tick. 
*/

#include <chrono>		//C++ date and time library for clocks, time points and durations
#include <iostream>		

class GameTimer{
	
public:
	GameTimer(){}
	//Constructor
	
	void startTimer();
	//Starts the timer. Records the point in time at the timer's start.
	
	
	void tick();
	/*Ticks the timer. Records the point in time of the current tick and the current timer duration as the 
	change in time from the timer's start to the current tick.*/
	
	
	void printTime();
	//Prints the timer's current duration.
	

	void endTimer();
	//Ends the timer. Records the point in time at the timer's end and the timer's total duration.
	
	
	bool isUp(double seconds); 
	/* Returns false if the timer duration is less than the given number of seconds and true otherwise.
	*	PARAMETERS: seconds - number of seconds used for checking timer 
	*/ 
	
	void reset(){duration = std::chrono::steady_clock::now() - std::chrono::steady_clock::now();}
	//Resets timer by setting timer duration to 0.
	

	double getDuration(){return duration.count();}
	//Returns timer's current duration.
	
	
private:
	std::chrono::time_point<std::chrono::steady_clock> start;	
	std::chrono::time_point<std::chrono::steady_clock> currentTick;	
	std::chrono::time_point<std::chrono::steady_clock> end;		
	std::chrono::duration<double> duration;						
};
