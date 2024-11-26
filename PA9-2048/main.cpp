#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

#include "Tile.hpp"
#include "Grid.hpp"

int main(void)
{
	//sf::Music mus;
	//mus.openFromFile("");//open music file named ""
	//mus.play();//play the music

	const int tileSize = 150;
	const int gridSize = 4;  // Rows and columns
	const sf::Color newColor = sf::Color::Red;
	sf::Font newFont;
	

	
		
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	sf::RenderWindow window(sf::VideoMode(800, 800), "2048!");
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


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			grid.moveUp(gridSize);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			grid.moveRight(gridSize);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			grid.moveDown(gridSize);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			grid.moveLeft(gridSize);
		}






		window.clear();
		grid.draw(window);  // Draws grid to window
		window.display();
	}

	return 0;
}