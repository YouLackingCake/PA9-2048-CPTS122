#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

class Tile : public sf::RectangleShape, public sf::Font
{
public:
	Tile(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& newColor,
		const int newValue, sf::Font& newFont) : RectangleShape(size), value(newValue)
	{
		setFillColor(newColor);
		setPosition(pos);
		text.setFont(newFont);
		text.setCharacterSize(20);
		text.setFillColor(sf::Color::White);
		text.setPosition(pos.x + size.x /2.f, pos.y + size.y / 2.f );  //work in progress. issues with bounds of text

	}
	void setValue(int newValue);
	void draw(sf::RenderWindow& window);  // Draw tile

private:
	int value;  // Number of tile
	sf::Text text;  // Text object to show number in font and size we want
	sf::Font font;
};