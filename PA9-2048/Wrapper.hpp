/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. Header for grid type
*****************************************************************/

#pragma once

#include "Grid.hpp"
#include "GameModeBase.hpp"
#include "ClassicMode.hpp"

enum class GameState { MainMenu, SubMenu, Playing, Exit }; // added submenu

class Wrapper
{
public:
	Wrapper() {}
	void run();

private:
	void handleMainMenu(sf::RenderWindow& window, GameState& gameState);
	void handleSubMenu(sf::RenderWindow& window, GameState& gameState);
	void handlePlaying(sf::RenderWindow& window, GameState& gameState, Grid& grid, const int& gridSize);
};