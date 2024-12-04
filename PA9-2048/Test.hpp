/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. Header for test type
*****************************************************************/

#pragma once

#include "Wrapper.hpp"

class Test
{
public:
	void runTests();

private:
	void testGridInitialization();
	void testRandomSpawnEmptyGrid();
	void testRandomSpawnFullGrid();
	void testMoves();
	void testLeftMove();
	void testRightMove();
	void testUpMove();
	void testDownMove();
	void testGameOver();
};