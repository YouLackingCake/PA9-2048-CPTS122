#include "ClassicMode.hpp"
#include <iostream>
#include <string>

void ClassicMode::calculateScore(int tileValue) //, sf::RenderWindow& window)
{
	score += tileValue; // adds merged tile value to score
	updateScoreText(); // update score display
}
