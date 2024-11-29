#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>

void generateRandomSpot(Grid& grid)
{
	bool loop = true;
	int value = 2;  // Randomly generated spot value

	while (loop)
	{
		int x = rand() % 4;
		int y = rand() % 4;
		if (grid.getTiles()[x][y].getValue() == 0)  // If grid spot is empty 
		{
			grid.setTileValue(x, y, value);
			loop = false;
		}
	}
}