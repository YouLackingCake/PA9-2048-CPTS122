#include "Tile.hpp"

void Tile::setValue(int& newValue)
{
	value = newValue;
	text.setString(std::to_string(value));  // Show number on tile when drawn
}

int Tile::getValue() const
{
	return value;
}

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(*this);  // Since inherited draws this tile rectangle shape
	if (value > 0)
	{
		window.draw(text);  // Text only drawn if value is greater than 0
	}
}
