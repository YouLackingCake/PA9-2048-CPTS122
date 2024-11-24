#include "Grid.hpp"
//#include "Grid.hpp"

Grid::Grid(const int& rows, const int& cols, const int& newTileSize)
{

}

void Grid::draw(sf::RenderWindow& window)  // Draws the grids
{

}

void Grid::setTileValue(const int& row, const int& col, const int& value)  // Set number shown on tile
{

}

int Grid::getTileSize() const
{
	return tileSize;
}

void Grid::setTileSize(int& newTileSize)
{
	tileSize = newTileSize;
}
