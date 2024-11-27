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
	srand(static_cast<unsigned>(time(nullptr)));//seeded random using time
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "2048!");
	window.setKeyRepeatEnabled(false);//makes it so holding a key down only counts as one key press

	//sf::Music mus;
	//mus.openFromFile("");//open music file named ""
	//mus.play();//play the music

	int tileSize = window.getSize().x / 5;//scales size of tiles in relation to window size
	const int gridSize = 4;  // Rows and columns
	const sf::Color newColor = sf::Color::Red;
	sf::Font newFont;

	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	//Make a menu?

	Grid grid(gridSize, gridSize, tileSize, newColor, newFont);  // Creates a 4 X 4 grid

	grid.initGrid(gridSize);  // Initialize grid to 0

	grid.spawnRandomTile();//when game starts, randomly generate 2 tiles
	grid.spawnRandomTile();

	while (window.isOpen())  // Loop while window is open
	{
		sf::Event event;  // Declare an event type
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)  // Check for the window to close
				window.close();  // Close window
		}

		bool madeMove = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//check for up
		{
			madeMove = grid.moveUp(gridSize);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//check for left
		{
			madeMove = grid.moveRight(gridSize);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//check for down
		{
			madeMove = grid.moveDown(gridSize);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))//check for right
		{
			madeMove = grid.moveLeft(gridSize);
		}

		if (madeMove == true)//checks if a valid move was made
		{
			grid.spawnRandomTile();//randomly generate new tiles

			//calculate score, might be good to do this within the move functions?

			//check for game over
				//if game over, end game
				//-> go back to a menu?
		}

		window.clear();//clear the window
		grid.draw(window);  // Draws grid to window
		window.display();//display changes to window
	}

	return 0;
}