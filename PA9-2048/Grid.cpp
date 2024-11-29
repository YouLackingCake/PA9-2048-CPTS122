
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
	const sf::Color& newColor, sf::Font& newFont)
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
	int row = 0;
	bool moved = false;

	for (int row = 0; row < gridSize; row++)  //cycle through each row
	{
		for (int column = 1; column < gridSize; column++) //cycle through each column
		{
			int current = tiles[row][column].getValue();
			int leftColumn = column;

			if (current != 0) //if not 0, choose what action to do
			{
				while (leftColumn > 0 && tiles[row][leftColumn - 1].getValue() == 0) //shift while left is 0
				{
					tiles[row][leftColumn - 1].setValue(tiles[row][leftColumn].getValue());
					tiles[row][leftColumn].setValue(0);
					leftColumn--;

					moved = true;
				}
				if (leftColumn > 0 && tiles[row][leftColumn - 1].getValue() == current) //to merge:
				{
					tiles[row][leftColumn - 1].setValue(current * 2);
					tiles[row][leftColumn].setValue(0);

					moved = true;
				}
			}
		}
	}
	return moved;
}

bool Grid::moveRight(int gridSize)
{
	int row = 0;
	bool moved = false;

	for (int row = 0; row < gridSize; row++)  //cycle through each row
	{
		for (int column = gridSize - 2; column >= 0; column --) //cycle through each column
		{
				int current = tiles[row][column].getValue();
				int rightColumn = column;

				if (current != 0) //if not 0, choose what action to do
				{
					while (rightColumn < gridSize - 1 && tiles[row][rightColumn + 1].getValue() == 0) //shift while right is 0
					{
						tiles[row][rightColumn + 1].setValue(tiles[row][rightColumn].getValue());
						tiles[row][rightColumn].setValue(0);
						rightColumn++;

						moved = true;
					}
					if (rightColumn < gridSize - 1 && tiles[row][rightColumn + 1].getValue() == current) //merge if same value
					{
						tiles[row][rightColumn + 1].setValue(current * 2);
						tiles[row][rightColumn].setValue(0); 

						moved = true;
					}
				}
		}
	}
	return moved;
}

bool Grid::moveUp(int gridSize)
{
	int column = 0;
	bool moved = false;

	while (column < gridSize)  //cycle through each column
	{
		
		for (int row = 1; row < gridSize; row++) //cycle through each row
		{
			int current = tiles[row][column].getValue();

			if (current != 0) //if not 0, choose what action to do
			{
				int upRow = row;

				while (upRow > 0 && tiles[upRow - 1][column].getValue() == 0) //shift while above is 0
				{
					tiles[upRow - 1][column].setValue(tiles[upRow][column].getValue());
					tiles[upRow][column].setValue(0);
					upRow--;

					moved = true;
				}
				if (upRow > 0 && tiles[upRow - 1][column].getValue() == current) //merge if same value
				{
					tiles[upRow - 1][column].setValue(current * 2);
					tiles[upRow][column].setValue(0);

					moved = true;
				}
			}
		}
		column++;
	}
	return moved;
}

bool Grid::moveDown(int gridSize)
{
	int column = 0;
	bool moved = false;

	while (column < gridSize)  //cycle through each column
	{
		for (int row = gridSize -2 ; row  >= 0; row--) //cycle through each row
		{
			int current = tiles[row][column].getValue();

			if (current != 0) //if not 0, choose what action to do
			{
				int downRow = row;

				while (downRow < gridSize - 1 && tiles[downRow + 1][column].getValue() == 0) //shift while below is 0
				{
					tiles[downRow + 1][column].setValue(tiles[downRow][column].getValue());
					tiles[downRow][column].setValue(0);
					downRow++;

					moved = true;
				}
				if (downRow < gridSize - 1 && tiles[downRow + 1][column].getValue() == current) //merge if same value
				{
					tiles[downRow + 1][column].setValue(current * 2);
					tiles[downRow][column].setValue(0);

					moved = true;
				}
			}
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

bool Grid::isGameOver()
{
	for (int row = 0; row < GRID_SIZE; ++row)//traverse the rows
	{
		for (int column = 0; column < GRID_SIZE; ++column)//traverse the columns
		{
			int current = tiles[row][column].getValue();//get the value of the current tile
			if (current == 0) return false;//if any tile is empty, game is not over

			if (row > 0 && current == tiles[row - 1][column].getValue()) return false;//equivilent tile in the same column
			if (row < 3 && current == tiles[row + 1][column].getValue()) return false;

			if (column > 0 && current == tiles[row][column - 1].getValue()) return false;//equivilent tile in the same row
			if (row < 3 && current == tiles[row][column + 1].getValue()) return false;
		}
	}
	return true;//the game is over
}