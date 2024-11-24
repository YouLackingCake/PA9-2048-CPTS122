#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.hpp"

using std::vector;

class Grid
{
public:
	Grid(const int& rows, const int& cols, const int& newTileSize);
	void draw(sf::RenderWindow& window);  // Draws grid
	void setTileValue(const int& row, const int& col, const int& value);  // Sets number shown on tile

	int getTileSize() const;
	void setTileSize(int& newTileSize);


private:
	vector<vector<Tile>> tiles;  // Creates 2D array out of vectors of Tile
	int tileSize;  // Size of Tile used for spacing
}