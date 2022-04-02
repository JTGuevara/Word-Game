/*
FILE: GameTimer.cpp
DESCRIPTION: GameTimer function definitions.
*/

void GameTimer::startTimer(){
		start = std::chrono::steady_clock::now();
	}
	
void GameTimer::tick(){
		currentTick = std::chrono::steady_clock::now();
		duration = currentTick - start;
	}
	
void GameTimer::endTimer(){
		end = std::chrono::steady_clock::now();
		duration = end - start;
	}
	
void GameTimer::printTime(){
		std::cout << "\nTime : " << duration.count();
	}
	
bool GameTimer::isUp(double seconds){
	if(duration.count() < seconds){
		return false;
	}
	return true;
}