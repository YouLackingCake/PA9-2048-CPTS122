/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. .CPP for grid type
*****************************************************************/

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

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	sf::Text scoreText;
	scoreText.setFont(newFont);
	scoreText.setString("Score: " + to_string(score));
	scoreText.setCharacterSize(40);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(10, 10);
	window.draw(scoreText);
}

// Set number shown on tile
void Grid::setTileValue(int row, int col, int value)
{
	tiles[row][col].setValue(value);  // Sets tile value using tile method setValue()
}

vector<vector<Tile>> Grid::getTiles() const
{
	return tiles;
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

bool Grid::moveLeft(int gridSize)
{
	int row = 0, column = 0;
	bool moved = false;
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
					moved = true;
				}
				else if (current == left) //merge if same value
				{
					tiles[row][column].setValue(0);
					tiles[row][column + 1].setValue(current + left);
					moved = true;
				}
			}
			column++;
		}	
		row++;
	}
	return moved;
}

bool Grid::moveRight(int gridSize)
{
	int row = 0, column = gridSize - 1;
	bool moved = false;
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
					moved = true;
				}
				else if (current == right) //merge if same value
				{
					tiles[row][column].setValue(0);
					tiles[row][column - 1].setValue(current + right);
					moved = true;
				}
			}
			column--;
		}
		row++;
	}
	return moved;
}

bool Grid::moveUp(int gridSize)
{
	int column = 0, row = gridSize - 1;
	bool moved = false;
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
					moved = true;
				}
				else if (current == up) //merge if same value
				{
					tiles[row - 1][column].setValue(0);
					tiles[row - 1][column].setValue(current + up);
					moved = true;
				}
			}
			row--;
		}
		column++;
	}
	return moved;
}

bool Grid::moveDown(int gridSize)
{
	int column = 0, row = 0;
	bool moved = false;
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
					moved = true;
				}
				else if (current == up) //merge if same value
				{
					tiles[row + 1][column].setValue(0);
					tiles[row + 1][column].setValue(current + up);
					moved = true;
				}
			}
			row++;
		}
		column++;
	}
	return moved;
}

void Grid::spawnRandomTile()
{
	vector<pair<int, int>> emptyTiles;//vactor to fill with empty tile coordinates

	for (int row = 0; row < tiles.size(); row++)//traverse rows
	{
		for (int column = 0; column < tiles[row].size(); column++)//traverse columns
		{
			if (tiles[row][column].getValue() == 0)
			{
				emptyTiles.emplace_back(row, column);//fills the vector with all empty tiles for a given turn
			}
		}
	}

	if (!emptyTiles.empty())//checks which tiles are empty
	{
		int randomIndex = rand() % emptyTiles.size();//find a randon number within the size of the empty tiles vector
		int selectedRow = emptyTiles[randomIndex].first;//select a row based on the random index
		int selectedCol = emptyTiles[randomIndex].second;

		int value = (rand() % 10 < 9) ? 2 : 4;//2 is much more likely than 4 to spawn, change "10 < 9" to change the spawn ratio
		setTileValue(selectedRow, selectedCol, value);
	}
}