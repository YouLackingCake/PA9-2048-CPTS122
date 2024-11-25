#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

#include "Tile.hpp"
#include "Grid.hpp"
#include "GeneralMethods.hpp"

int main(void)
{
	//sf::Music mus;
	//mus.openFromFile("");//open music file named ""
	//mus.play();//play the music
	srand(time(0));
	int row = 0, col = 0, value = 2;

	const int tileSize = 150;
	const int gridSize = 4;  // Rows and columns
	const sf::Color newColor(208, 214, 219);  // Makes boxes gray (empty spaces)

	sf::Font newFont;
	newFont.loadFromFile("arial.ttf");

	sf::RenderWindow window(sf::VideoMode(800, 800), "2048!");
	Grid grid(gridSize, gridSize, tileSize, newColor, newFont);  // Creates a 4 X 4 grid

	grid.initGrid(gridSize);  // Initialize grid to 0

	// Do twice so two spots on grid are 2 to start
	generateRandomSpot(grid);
	generateRandomSpot(grid);

	while (window.isOpen())  // Loop while window is open
	{
		sf::Event event;  // Declare an event type
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)  // Check for the window to close
				window.close();  // Close window
		}

		window.clear();
		grid.draw(window);  // Draws grid to window
		window.display();
	}

	return 0;
}