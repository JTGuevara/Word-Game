/*
FILE: GameTimer.hpp
DESCRIPTION: Class definition for in-game timer.

MEMBER FUNCTIONS:
	gameTimer(){}				Constructor
	void startTimer()			Starts the timer. Records the point in time at the timer's start.
	void tick()					Ticks the timer. Records the point in time of the current tick and the current timer duration as the 
								change in time from the timer's start to the current tick.
	void endTimer()				Ends the timer. Records the point in time at the timer's end and the timer's total duration.
	void printTime()			Prints the timer's current duration.
	bool isUp(double seconds)	Returns false if the timer duration is less than the given number of seconds and true otherwise.
	void reset()				Resets timer by setting timer duration to 0.
	double getDuration()		Returns timer's current duration.
*/

#include <chrono>//C++ date and time library for clocks, time points and durations

class GameTimer{
	
public:
	GameTimer(){}
	void startTimer();
	void tick();
	void printTime();
	void endTimer();
	bool isUp(double);
	void reset(){duration = std::chrono::steady_clock::now() - std::chrono::steady_clock::now();}
	double getDuration(){return duration.count();}
	
private:
	std::chrono::time_point<std::chrono::steady_clock> start;	
	std::chrono::time_point<std::chrono::steady_clock> currentTick;	
	std::chrono::time_point<std::chrono::steady_clock> end;		
	std::chrono::duration<double> duration;						
};

#include "GameTimer.cpp"