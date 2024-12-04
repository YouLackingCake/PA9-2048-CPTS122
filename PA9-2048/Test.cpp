/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. Header for wrapper type
*****************************************************************/

#include "Test.hpp"

void Test::runTests()
{
	testGridInitialization();
	cout << endl;
	testMoves();
	cout << endl;
	testGameOver();
	cout << endl;
	testRandomSpawnEmptyGrid();
	cout << endl;
	testRandomSpawnFullGrid();
}

void Test::testGridInitialization()
{
	bool initialized = true;
	int tileSize = 100, score = 0;
	sf::Color newColor;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	ClassicScoring clscScoring;

	Grid testGrid(GRID_SIZE, GRID_SIZE, tileSize, newColor, newFont, &clscScoring);
	testGrid.initGrid(GRID_SIZE);

	for (int row = 0; row < GRID_SIZE; ++row)
	{
		for (int col = 0; col < GRID_SIZE; ++col)
		{
			if (testGrid.getTiles()[row][col].getValue() != 0)  // If tile is not initialized to zero test failed
			{
				initialized = false;
				cout << "Tile at " << row << "," << col << " was not correctly initialized." << endl;
			}
		}
	}

	if (!initialized)
	{
		cout << "Initialized test failed. Not all tile values set to 0." << endl;
	}
	else
	{
		cout << "Initialized test passed. All tile values correctly set to 0." << endl;
	}

}

void Test::testRandomSpawnEmptyGrid()
{
	bool randomSpawn = false;
	int tileSize = 100, score = 0;
	sf::Color newColor;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	ClassicScoring clscScoring;

	Grid testGrid(GRID_SIZE, GRID_SIZE, tileSize, newColor, newFont, &clscScoring);
	testGrid.initGrid(GRID_SIZE);

	testGrid.spawnRandomTile();

	for (int row = 0; row < GRID_SIZE; ++row)
	{
		for (int column = 0; column < GRID_SIZE; ++column)
		{
			if (testGrid.getTiles()[row][column].getValue() != 0)  // TIle was spawned
			{
				randomSpawn = true;
				break;
			}
		}
	}

	if (randomSpawn)
	{
		cout << "Random spawn on empty grid test passed" << endl;
	}
	else
	{
		cout << "No tile was spawned, test failed" << endl;
	}
}

void Test::testRandomSpawnFullGrid()
{
	bool randomSpawn = false;
	int tileSize = 100, score = 0, value = 0;
	sf::Color newColor;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	ClassicScoring clscScoring;

	Grid testGrid(GRID_SIZE, GRID_SIZE, tileSize, newColor, newFont, &clscScoring);
	testGrid.initGrid(GRID_SIZE);

	for (int i = 0; i < GRID_SIZE; ++i)  // Set each tile to different value so filled
	{
		++value;
		for (int j = 0; j < GRID_SIZE; ++j)
		{
			testGrid.setTileValue(i, j, value);
			++value;
		}
	}

	randomSpawn = testGrid.spawnRandomTile();

	if (!randomSpawn)
	{
		cout << "Random spawn on full grid test passed" << endl;
	}
	else
	{
		cout << "Tile spawned, test failed" << endl;
	}

}

void Test::testMoves()
{
	testLeftMove();
	cout << endl;
	testRightMove();
	cout << endl;
	testUpMove();
	cout << endl;
	testDownMove();
}

void Test::testLeftMove()
{
	int tileSize = 100, score = 0;
	sf::Color newColor;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	ClassicScoring clscScoring;

	Grid testGrid(GRID_SIZE, GRID_SIZE, tileSize, newColor, newFont, &clscScoring);
	testGrid.initGrid(GRID_SIZE);

	testGrid.setTileValue(0, 0, 2);  // Sets row 0 col 0 to have a value of 2 to test merge
	testGrid.setTileValue(0, 1, 2);  // Sets row 0 col 1 to have a value of 2 to test merge
	testGrid.setTileValue(1, 1, 2);  // Sets row 1 and col 1 to have value of 2 to test swap since tile to left is still 0
	cout << "BEFORE MOVING LEFT: (0,0) value is 2, (0,1) value is 2, (1,0) value is 0, (1,1) value is 2" << endl;

	testGrid.moveLeft(GRID_SIZE);
	cout << "AFTER MOVING LEFT: (0,0) value is " << testGrid.getTiles()[0][0].getValue() <<
		", (0,1) value is " << testGrid.getTiles()[0][1].getValue() << ", (1,0) value is " << testGrid.getTiles()[1][0].getValue() <<
		", (1,1) value is " << testGrid.getTiles()[1][1].getValue() << endl;

	if (testGrid.getTiles()[0][0].getValue() == 4 && testGrid.getTiles()[1][0].getValue() == 2)  // Correct values if move left worked
	{
		cout << "Merging left test passed" << endl;
		if (testGrid.getScore() == 4)
		{
			cout << "Score successfully updated" << endl;
		}
	}
	else
	{
		cout << "Merging left test failed" << endl;
	}
}

void Test::testRightMove()
{
	int tileSize = 100, score = 0;
	sf::Color newColor;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	ClassicScoring clscScoring;

	Grid testGrid(GRID_SIZE, GRID_SIZE, tileSize, newColor, newFont, &clscScoring);
	testGrid.initGrid(GRID_SIZE);

	testGrid.setTileValue(0, 3, 2);  // Sets row 0 col 0 to have a value of 2 to test merge
	testGrid.setTileValue(0, 2, 2);  // Sets row 0 col 1 to have a value of 2 to test merge
	testGrid.setTileValue(1, 2, 2);  // Sets row 1 and col 1 to have value of 2 to test swap since tile to right is still 0
	cout << "BEFORE MOVING RIGHT: (0,2) value is 2, (0,3) value is 2, (1,2) value is 2, (1,3) value is 0" << endl;

	testGrid.moveRight(GRID_SIZE);
	cout << "AFTER MOVING RIGHT: (0,2) value is " << testGrid.getTiles()[0][2].getValue() <<
		", (0,3) value is " << testGrid.getTiles()[0][3].getValue() << ", (1,2) value is " << testGrid.getTiles()[1][2].getValue() <<
		", (1,3) value is " << testGrid.getTiles()[1][3].getValue() << endl;

	if (testGrid.getTiles()[0][3].getValue() == 4 && testGrid.getTiles()[1][3].getValue() == 2)  // Correct values if move right worked
	{
		cout << "Merging right test passed" << endl;
		if (testGrid.getScore() == 4)
		{
			cout << "Score successfully updated" << endl;
		}
	}
	else
	{
		cout << "Merging right test failed" << endl;
	}
}

void Test::testUpMove()
{
	int tileSize = 100, score = 0;
	sf::Color newColor;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	ClassicScoring clscScoring;

	Grid testGrid(GRID_SIZE, GRID_SIZE, tileSize, newColor, newFont, &clscScoring);
	testGrid.initGrid(GRID_SIZE);

	testGrid.setTileValue(0, 0, 2);  // Sets row 0 col 0 to have a value of 2 to test merge
	testGrid.setTileValue(1, 0, 2);  // Sets row 0 col 1 to have a value of 2 to test merge
	testGrid.setTileValue(1, 1, 2);  // Sets row 1 and col 1 to have value of 2 to test swap since tile above is still 0
	cout << "BEFORE MOVING UP: (0,0) value is 2, (1,0) value is 2, (1,1) value is 2, (0,1) value is 0" << endl;

	testGrid.moveUp(GRID_SIZE);
	cout << "AFTER MOVING UP: (0,0) value is " << testGrid.getTiles()[0][0].getValue() <<
		", (1,0) value is " << testGrid.getTiles()[1][0].getValue() << ", (1,1) value is " << testGrid.getTiles()[1][1].getValue() <<
		", (0,1) value is " << testGrid.getTiles()[0][1].getValue() << endl;

	if (testGrid.getTiles()[0][0].getValue() == 4 && testGrid.getTiles()[0][1].getValue() == 2)  // Correct values if move up worked
	{
		cout << "Merging up test passed" << endl;
		if (testGrid.getScore() == 4)
		{
			cout << "Score successfully updated" << endl;
		}
	}
	else
	{
		cout << "Merging up test failed" << endl;
	}
}

void Test::testDownMove()
{
	int tileSize = 100, score = 0;
	sf::Color newColor;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	ClassicScoring clscScoring;

	Grid testGrid(GRID_SIZE, GRID_SIZE, tileSize, newColor, newFont, &clscScoring);
	testGrid.initGrid(GRID_SIZE);

	testGrid.setTileValue(2, 0, 2);  // Sets row 0 col 0 to have a value of 2 to test merge
	testGrid.setTileValue(3, 0, 2);  // Sets row 0 col 1 to have a value of 2 to test merge
	testGrid.setTileValue(2, 1, 2);  // Sets row 1 and col 1 to have value of 2 to test swap since tile below is still 0
	cout << "BEFORE MOVING DOWN: (2,0) value is 2, (3,0) value is 2, (2,1) value is 2, (3,1) value is 0" << endl;

	testGrid.moveDown(GRID_SIZE);
	cout << "AFTER MOVING DOWN: (2,0) value is " << testGrid.getTiles()[2][0].getValue() <<
		", (3,0) value is " << testGrid.getTiles()[3][0].getValue() << ", (2,1) value is " << testGrid.getTiles()[2][1].getValue() <<
		", (3,1) value is " << testGrid.getTiles()[3][1].getValue() << endl;

	if (testGrid.getTiles()[3][0].getValue() == 4 && testGrid.getTiles()[3][1].getValue() == 2)  // Correct values if move down worked
	{
		cout << "Merging down test passed" << endl;
		if (testGrid.getScore() == 4)
		{
			cout << "Score successfully updated" << endl;
		}
	}
	else
	{
		cout << "Merging down test failed" << endl;
	}
}

void Test::testGameOver()
{
	bool gameOver = true;
	int tileSize = 100, score = 0, value = 0 ;
	sf::Color newColor;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	ClassicScoring clscScoring;

	Grid testGrid(GRID_SIZE, GRID_SIZE, tileSize, newColor, newFont, &clscScoring);
	testGrid.initGrid(GRID_SIZE);

	for (int i = 0; i < GRID_SIZE; ++i)  // Set each tile to different value to simulate game ending
	{
		++value;
		for (int j = 0; j < GRID_SIZE; ++j)
		{
			testGrid.setTileValue(i, j, value);
			++value;
		}
	}

	gameOver = testGrid.isGameOver();

	if (gameOver)
	{
		cout << "Game over test passed" << endl;
	}
	else
	{
		cout << "Game over test failed" << endl;
	}
}
