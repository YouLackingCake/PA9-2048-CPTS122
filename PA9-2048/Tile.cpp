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
	switch (value)
	{
	case 0: setFillColor(sf::Color(200, 200, 200)); break; //Light gray for empty tiles
	case 2: setFillColor(sf::Color(238, 228, 218)); break; //Beige
	case 4: setFillColor(sf::Color(237, 224, 200)); break; //Light orange
	case 8: setFillColor(sf::Color(242, 177, 121)); break; //Orange
	case 16: setFillColor(sf::Color(245, 149, 99)); break; //Darker orange
	case 32: setFillColor(sf::Color(246, 124, 95)); break; //Red-orange
	case 64: setFillColor(sf::Color(246, 94, 59)); break; //Bright red
	case 128: setFillColor(sf::Color(237, 207, 114)); break; //Yellow
	case 256: setFillColor(sf::Color(237, 204, 97)); break; //Yellow-gold
	case 512: setFillColor(sf::Color(237, 200, 80)); break; //Gold
	case 1024: setFillColor(sf::Color(237, 197, 63)); break; //Dark gold
	case 2048: setFillColor(sf::Color(237, 194, 46)); break; //Bright gold
	default: setFillColor(sf::Color(60, 58, 50)); break; //Dark gray for higher numbers
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