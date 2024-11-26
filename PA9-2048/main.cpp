/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. Main function
*****************************************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

#include "Tile.hpp"
#include "Grid.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "2048!");

	//sf::Music mus;
	//mus.openFromFile("");//open music file named ""
	//mus.play();//play the music

	int tileSize = window.getSize().x / 5;//scales size of tiles in relation to window size
	const int gridSize = 4;  // Rows and columns
	const sf::Color newColor = sf::Color::Red;
	sf::Font newFont;
	

	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");


	Grid grid(gridSize, gridSize, tileSize, newColor, newFont);  // Creates a 4 X 4 grid

	grid.initGrid(gridSize);  // Initialize grid to 0
	
	
	//Test Squares//////////////
	grid.setTileValue(1, 1, 1);
	grid.setTileValue(1, 2, 1);
	grid.setTileValue(0, 0, 2048);
	grid.setTileValue(3, 3, 4);
	////////////////////////////


	while (window.isOpen())  // Loop while window is open
	{
		sf::Event event;  // Declare an event type
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)  // Check for the window to close
				window.close();  // Close window
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			grid.moveUp(gridSize);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			grid.moveRight(gridSize);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			grid.moveDown(gridSize);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			grid.moveLeft(gridSize);
		}

		window.clear();
		grid.draw(window);  // Draws grid to window
		window.display();
	}

	return 0;
}