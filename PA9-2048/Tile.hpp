#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

	class Tile : public sf::RectangleShape, public sf::Font
{
public:
	Tile(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& newColor) : RectangleShape(size)
	{
		setFillColor(newColor);
		setPosition(pos);
	}

	
private:

};