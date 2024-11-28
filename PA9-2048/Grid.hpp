/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. Header for grid type
*****************************************************************/

#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdbool>

#include <SFML/Graphics.hpp>
#include "Tile.hpp"

using namespace std;


class Grid
{
public:
	Grid(const int& rows, const int& cols, const int& newTileSize,
		const sf::Color& newColor, sf::Font& newFont);

	void draw(sf::RenderWindow& window);  // Draws grid
	void setTileValue(int row, int col, int value);  // Sets number shown on tile

	int getTileSize() const;
	void setTileSize(int newTileSize);

	void initGrid(const int& gridSize);  // Initialize values of grid to be 0

	bool moveLeft(int gridSize);
	bool moveRight(int gridSize);
	bool moveUp(int gridSize);
	bool moveDown(int gridSize);

	void spawnRandomTile();

private:
	vector<vector<Tile>> tiles;  // Creates 2D array out of vectors of Tile
	int tileSize;  // Size of Tile used for spacing
	int score;
};