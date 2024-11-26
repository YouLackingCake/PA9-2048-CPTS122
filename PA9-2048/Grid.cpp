#include "Grid.hpp"
//#include "Grid.hpp"

Grid::Grid(const int& rows, const int& cols, const int& newTileSize, 
	const sf::Color& newColor, sf::Font &newFont)
{
	tileSize = newTileSize;

	for (int i = 0; i < rows; ++i)  // i - rows
	{
		vector<Tile> row;  // Create new row
		for (int j = 0; j < cols; ++j)  // j - cols
		{
			int x = j * tileSize + (j + 1) * 5;  // Add padding between cols of tiles / position tile
			int y = i * tileSize + (i + 1) * 5;  // Add padding between rows of tiles / position tile
			//row.emplace_back(x, y, tileSize);  // Place tile into correct row spot
			row.emplace_back(sf::Vector2f(tileSize, tileSize), sf::Vector2f(x + 90, y + 90), 
				newColor, 0/*value*/, newFont);  // Pass the new arguments
		}
		tiles.push_back(row);  // Add each row to member vector tiles to create array
	}
}

// Draws the grids
void Grid::draw(sf::RenderWindow& window)
{
	for (vector<Tile>& row : tiles)  // For row in vector 2D array tiles
	{
		for (Tile& tile : row)  // For tile in each row
		{
			tile.draw(window);  // Draws tile to window
		}
	}
}

// Set number shown on tile
void Grid::setTileValue(int row, int col, int value)
{
	tiles[row][col].setValue(value);  // Sets tile value using tile method setValue()
}

int Grid::getTileSize() const
{
	return tileSize;
}

void Grid::setTileSize(int newTileSize)
{
	tileSize = newTileSize;
}

void Grid::initGrid(const int& gridSize)
{
	int value = 0;
	for (int row = 0; row < gridSize; ++row)
	{
		for (int col = 0; col < gridSize; ++col)
		{
			setTileValue(row, col, value);  // Initialize each tile to be of value zero
		}
	}
}
