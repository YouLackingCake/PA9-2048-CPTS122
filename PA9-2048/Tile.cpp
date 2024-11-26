#include "Tile.hpp"

void Tile::setValue(int& newValue)
{
	value = newValue;
	text.setString(std::to_string(value));  // Show number on tile when drawn

	// center text on tile
	sf::FloatRect textBounds = text.getLocalBounds();
	text.setOrigin(textBounds.width / 2, textBounds.height / 2);
	text.setPosition(getPosition().x + getSize().x / 2, getPosition().y + getSize().y / 2);
}

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(*this);  // Since inherited draws this tile rectangle shape
	if (value > 0)
	{
		window.draw(text);  // Text only drawn if value is greater than 0
	}
}
