/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. Header for grid type
*****************************************************************/

#include "Wrapper.hpp"

void Wrapper::run()
{
	srand(static_cast<unsigned>(time(nullptr)));//seeded random using time
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "2048!");
	window.setKeyRepeatEnabled(false);//makes it so holding a key down only counts as one key press


	int tileSize = window.getSize().x / 5;//scales size of tiles in relation to window size
	const int gridSize = 4;  // Rows and columns
	const sf::Color newColor = sf::Color::Red;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	GameState gameState = GameState::MainMenu;  // Start game in main menu
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

		window.clear();//clear the window

		// Draw statements inside
		switch (gameState)
		{
		case GameState::MainMenu:
			handleMainMenu(window, gameState);
			break;
		case GameState::Playing:
			handlePlaying(window, gameState, grid, gridSize);
			break;
		case GameState::Exit:
			window.close();
			break;
		}

		window.display();//display changes to window
	}
}

void Wrapper::handleMainMenu(sf::RenderWindow& window, GameState& gameState)
{
	sf::Font font;
	sf::Text title, play, rules, exit;

	font.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	if (title.getString().isEmpty())  // If the string is empty
	{
		title.setFont(font);
		title.setString("2048 Main Menu");
		title.setCharacterSize(100);
		title.setFillColor(sf::Color(246, 124, 95));
		title.setPosition(window.getSize().x / 5.75, window.getSize().y / 10);

		rules.setFont(font);
		rules.setString("Use WASD or the arrow keys to merge tiles of the same number.\n\t\t\t\t\t\t\t  Try to create the 2048 tile!");
		rules.setCharacterSize(30);
		rules.setFillColor(sf::Color(245, 149, 99));
		rules.setPosition(window.getSize().x / 12, window.getSize().y - window.getSize().y / 2.5);

		play.setFont(font);
		play.setString("Press [P] to Play");
		play.setCharacterSize(50);
		play.setFillColor(sf::Color(245, 149, 99));
		play.setPosition(window.getSize().x / 3, window.getSize().y / 3);

		exit.setFont(font);
		exit.setString("Press [E] to Exit");
		exit.setCharacterSize(50);
		exit.setFillColor(sf::Color(245, 149, 99));
		exit.setPosition(window.getSize().x / 3, window.getSize().y / 2.45);
	}

	window.draw(title);
	window.draw(rules);
	window.draw(play);
	window.draw(exit);

	// Changes state of game based on key pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		gameState = GameState::Playing;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		gameState = GameState::Exit;
	}
}

void Wrapper::handlePlaying(sf::RenderWindow& window, GameState& gameState, Grid& grid, const int& gridSize)
{
	bool madeMove = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		gameState = GameState::Exit;
	}
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
		//grid.spawnRandomTile();//randomly generate new tiles

		//calculate score, might be good to do this within the move functions?

		//check for game over
			//if game over, end game
			//-> go back to a menu?
	}

	grid.draw(window);  // Draws grid to window
}