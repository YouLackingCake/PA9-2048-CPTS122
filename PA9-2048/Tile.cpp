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

	if (value > 0)
	{
		text.setString(std::to_string(value));  // Show number on tile when drawn
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(50);

		sf::FloatRect textBounds = text.getLocalBounds();
		text.setOrigin(textBounds.width / 2, textBounds.height / 2);//set the origin to the center of the text
		sf::Vector2f tileCenter = getPosition() + sf::Vector2f(getSize().x / 2, getSize().y / 2);//get the size and center of tile
		text.setPosition(tileCenter);//set the text position to the center of the tile
	}
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


