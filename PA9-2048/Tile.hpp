#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

class Tile : public sf::RectangleShape//, public sf::Font
{
public:
	Tile(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& newColor,
		/*const*/ int newValue, sf::Font newFont) : RectangleShape(size), value(newValue) // took away the const for testing purposes
	{
		setFillColor(newColor);
		setPosition(pos);

		text.setCharacterSize(20);
		text.setFont(newFont);
		text.setFillColor(sf::Color::Black);
		text.setPosition(pos.x, pos.y);
		setValue(newValue); // set initial value and center text
	}

	void setValue(int& newValue);
	void draw(sf::RenderWindow& window);  // Draw tile

private:
	int value;  // Number of tile
	sf::Text text;  // Text object to show number in font and size we want
	sf::Font font;
};