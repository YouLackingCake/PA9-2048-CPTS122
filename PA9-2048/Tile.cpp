/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. .CPP for tile type
*****************************************************************/

#include "Tile.hpp"

void Tile::setValue(int newValue)
{
	value = newValue;
	
	text.setString(std::to_string(value));  // Show number on tile when drawn
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(50);
}

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(*this);  // Since inherited draws this tile rectangle shape
	if (value > 0)
	{
		window.draw(text);  // Text only drawn if value is greater than 0
	}
}

int Tile::getValue() const
{
	return value;
}


