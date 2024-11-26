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

void Grid::moveLeft(int gridSize)
{
	int row = 0, column = 0;
	while (row < gridSize)  //cycle through each row
	{
		column = 0;

		while (column < gridSize - 1) //cycle through each column
		{
			int current = tiles[row][column].getValue();
			int left = tiles[row][column + 1].getValue();

			if (current != 0) //if not 0, choose what action to do
			{
				if (left == 0) //if tile to left is 0, swap places
				{
					tiles[row][column].setValue(left);
					tiles[row][column + 1].setValue(current);
				}
				else if (current == left) //merge if same value
				{
					tiles[row][column].setValue(0);
					tiles[row][column + 1].setValue(current + left);
				}
			}
			column++;
		}	
		row++;
	}

}

void Grid::moveRight(int gridSize)
{
	int row = 0, column = gridSize - 1;
	while (row  < gridSize)  //cycle through each row
	{
		column = gridSize - 1;

		while (column > 0) //cycle through each column
		{
			int current = tiles[row][column].getValue();
			int right = tiles[row][column - 1].getValue();

			if (current != 0) //if not 0, choose what action to do
			{
				if (right == 0) //if tile to right is 0, swap places
				{
					tiles[row][column].setValue(right);
					tiles[row][column - 1].setValue(current);
				}
				else if (current == right) //merge if same value
				{
					tiles[row][column].setValue(0);
					tiles[row][column - 1].setValue(current + right);
				}
			}
			column--;
		}
		row++;
	}
}

void Grid::moveUp(int gridSize)
{
	int column = 0, row = gridSize - 1;
	while (column < gridSize)  //cycle through each column
	{
		row = gridSize - 1;

		while (row > 0) //cycle through each row
		{
			int current = tiles[row][column].getValue();
			int up = tiles[row - 1][column].getValue();

			if (current != 0) //if not 0, choose what action to do
			{
				if (up == 0) //if tile above is 0, swap places
				{
					tiles[row][column].setValue(up);
					tiles[row - 1][column].setValue(current);
				}
				else if (current == up) //merge if same value
				{
					tiles[row - 1][column].setValue(0);
					tiles[row - 1][column].setValue(current + up);
				}
			}
			row--;
		}
		column++;
	}
}

void Grid::moveDown(int gridSize)
{
	int column = 0, row = 0;
	while (column < gridSize)  //cycle through each column
	{
		row = 0;

		while (row < gridSize - 1) //cycle through each row
		{
			int current = tiles[row][column].getValue();
			int up = tiles[row + 1][column].getValue();

			if (current != 0) //if not 0, choose what action to do
			{
				if (up == 0) //if tile below is 0, swap places
				{
					tiles[row][column].setValue(up);
					tiles[row + 1][column].setValue(current);
				}
				else if (current == up) //merge if same value
				{
					tiles[row + 1][column].setValue(0);
					tiles[row + 1][column].setValue(current + up);
				}
			}
			row++;
		}
		column++;
	}

}
