#include "ClassicMode.hpp"
#include <iostream>

void ClassicMode::calculateScore(int tileValue)
{
	score += tileValue; // adds merged tile value to score
	updateScoreText(); // update score display
	std::cout << "ClassicMode: Added " << tileValue << " to score.\n";
}