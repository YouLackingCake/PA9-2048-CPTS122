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
#include "Scoring.hpp"

using namespace std;

#define GRID_SIZE 4

class Grid
{
public:
	Grid(const int& rows, const int& cols, const int& newTileSize,
		const sf::Color& newColor, sf::Font& newFont, ScoringStrategy* strategy);

	void draw(sf::RenderWindow& window);  // Draws grid
	void setTileValue(int row, int col, int value);  // Sets number shown on tile

	int getTileSize() const;
	void setTileSize(int newTileSize);

	vector<vector<Tile>> getTiles();
	void initGrid(const int& gridSize);  // Initialize values of grid to be 0

	bool moveLeft(int gridSize);
	bool moveRight(int gridSize);
	bool moveUp(int gridSize);
	bool moveDown(int gridSize);

	bool spawnRandomTile();

	bool isGameOver();

	void setScore(int newScore);
	int getScore();

	void setScoringStrategy(ScoringStrategy* strategy);

	void updateScore(int tileValue);


private:
	vector<vector<Tile>> tiles;  // Creates 2D array out of vectors of Tile
	int tileSize;  // Size of Tile used for spacing
	int score;

	ScoringStrategy* scoringStrategy;
};