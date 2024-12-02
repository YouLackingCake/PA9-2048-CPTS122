/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. .CPP for wrapper type
*****************************************************************/

#include "Wrapper.hpp"

void Wrapper::run()
{
	srand(static_cast<unsigned>(time(nullptr)));//seeded random using time
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "2048!");
	window.setKeyRepeatEnabled(false);//makes it so holding a key down only counts as one key press


	int tileSize = window.getSize().x / 5;//scales size of tiles in relation to window size
	const sf::Color newColor = sf::Color::Red;

	sf::Font newFont;
	newFont.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

	GameState gameState = GameState::MainMenu;  // Start game in main menu
	Grid grid(GRID_SIZE, GRID_SIZE, tileSize, newColor, newFont);  // Creates a 4 X 4 grid

	grid.initGrid(GRID_SIZE);  // Initialize grid to 0
	grid.spawnRandomTile();
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
		case GameState::SubMenu:
			handleSubMenu(window, gameState);
			break;
		case GameState::Playing:
			handlePlaying(window, gameState, grid, GRID_SIZE);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) // added submenu
	{
		gameState = GameState::SubMenu;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		gameState = GameState::Exit;
	}
}

void Wrapper::handleSubMenu(sf::RenderWindow& window, GameState& gameState)
{
	std::unique_ptr<GameMode> gameMode; // pointer to base class for polymorphism stuff
	sf::Text subMenu, select, mode;
	sf::Font font;

	font.loadFromFile("SparkyStonesRegular-BW6ld.ttf");


	subMenu.setFont(font);
	subMenu.setString("Sub-menu");
	subMenu.setCharacterSize(80);
	subMenu.setFillColor(sf::Color(246, 124, 95));
	subMenu.setPosition(window.getSize().x / 5, window.getSize().y / 6);

	select.setFont(font);
	select.setString("Select a game mode:");
	select.setCharacterSize(60);
	select.setFillColor(sf::Color(245, 149, 99));
	select.setPosition(window.getSize().x / 4, window.getSize().y / 3);

	mode.setFont(font);
	mode.setString("1) Classic\n2) Challenge\n3) Timed"); //potential options
	mode.setCharacterSize(50);
	mode.setFillColor(sf::Color(245, 149, 99));
	mode.setPosition(window.getSize().x / 3.5, window.getSize().y / 2.25);

	while (gameState == GameState::SubMenu)
	{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			gameState = GameState::Exit;
			return;
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Num1)
			{
				gameMode = std::make_unique<ClassicMode>(); // sets game to classic mode
				gameState = GameState::Playing;
				return;
			}
			else if (event.key.code == sf::Keyboard::Num2)
			{
				gameMode = std::make_unique<ClassicMode>(); // will set game to challenge mode
				gameState = GameState::Playing;
				return;
			}
			else if (event.key.code == sf::Keyboard::Num3)
			{
				gameMode = std::make_unique<ClassicMode>(); //will set game to timed mode
				gameState = GameState::Playing;
				return;
			}
		}

	}
		window.clear();
		window.draw(subMenu);
		window.draw(select);
		window.draw(mode);
		window.display();
	}

}

void Wrapper::handlePlaying(sf::RenderWindow& window, GameState& gameState, Grid& grid, const int& gridSize)
{
	bool madeMove = false;
	bool gameOver = false;
	static bool keyHandled = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		gameState = GameState::Exit;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !keyHandled)//check for up
	{
		keyHandled = true;
		madeMove = grid.moveUp(gridSize);
		if (madeMove)
		{
			grid.spawnRandomTile();
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !keyHandled)//check for left
	{
		keyHandled = true;
		madeMove = grid.moveLeft(gridSize);
		if (madeMove)
		{
			grid.spawnRandomTile();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !keyHandled)//check for down
	{
		keyHandled = true;
		madeMove = grid.moveDown(gridSize);
		if (madeMove)
		{
			grid.spawnRandomTile();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !keyHandled)//check for right
	{
		keyHandled = true;
		madeMove = grid.moveRight(gridSize);
		if (madeMove)
		{
			grid.spawnRandomTile();
		}
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		keyHandled = false;//check to make sure key isn't being held
	}

	if (grid.isGameOver())
	{
		sf::Text gameOver, pressEnter, showScore;
		sf::Font font;

		font.loadFromFile("SparkyStonesRegular-BW6ld.ttf");

		gameOver.setFont(font);
		gameOver.setString("Game Over");
		gameOver.setCharacterSize(80);
		gameOver.setFillColor(sf::Color(246, 124, 95));
		gameOver.setPosition(window.getSize().x / 2, window.getSize().y / 6);

		showScore.setFont(font);
		showScore.setString("Score: " + to_string(grid.getScore()));
		showScore.setCharacterSize(60);
		showScore.setFillColor(sf::Color(245, 149, 99));
		showScore.setPosition(window.getSize().x / 2, window.getSize().y / 3);

		pressEnter.setFont(font);
		pressEnter.setString("Press 'Enter' to Return to the Menu");
		pressEnter.setCharacterSize(50);
		pressEnter.setFillColor(sf::Color(245, 149, 99));
		pressEnter.setPosition(window.getSize().x / 2, window.getSize().y / 2.25);

		sf::FloatRect textBounds = gameOver.getLocalBounds();
		gameOver.setOrigin(textBounds.width / 2, textBounds.height / 2);

		textBounds = showScore.getLocalBounds();
		showScore.setOrigin(textBounds.width / 2, textBounds.height / 2);

		textBounds = pressEnter.getLocalBounds();
		pressEnter.setOrigin(textBounds.width / 2, textBounds.height / 2);

		window.draw(showScore);
		window.draw(pressEnter);
		window.draw(gameOver);
		window.display();

		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))//wait until enter key is pressed
		{

		}
		gameState = GameState::MainMenu;

		grid.initGrid(GRID_SIZE);//when you return to the menu, initializes board for next game
		grid.spawnRandomTile();
		grid.spawnRandomTile();
	}

	/**************************************************
	* Old code for reference
	* 
	*if (madeMove == true)//checks if a valid move was made
	*{
	*	grid.spawnRandomTile(); //randomly generate new tiles
	*	calculate score, might be good to do this within the move functions?
	*
	*	check for game over
	*		if game over, end game
	*		-> go back to a menu?
	}
	*************************************************/


	grid.draw(window);  // Draws grid to window
}
