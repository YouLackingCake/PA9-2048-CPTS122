#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class GameMode
{
protected:
	int score;
	sf::Font font;
	sf::Text scoreText;

public:
	GameMode() : score(0)
	{
		if (!font.loadFromFile("SparkyStonesRegular-BW6ld.ttf"))
		{
			throw std::runtime_error("Failed to load font");
		}
		scoreText.setFont(font);
		scoreText.setCharacterSize(40);		
		scoreText.setFillColor(sf::Color::White);
		scoreText.setPosition(10, 10);
		updateScoreText();
	}

	virtual void calculateScore(int tileValue) = 0;

	int getScore() const { return score; }
	
	void updateScoreText()
	{
		scoreText.setString("Score: " + std::to_string(score));
	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(scoreText);
	}

	virtual ~GameMode() {};

};