#include "Grid.h"

Grid::Grid() {}

/*
	Constructor

	@param position the upper left origin of the grid
	@param size the count of the spaces on the grid horrizontally and vertically
	@param space_size the size of the individual spaces on the grid
*/
Grid::Grid(sf::Vector2f position, sf::Vector2<int> size, sf::Vector2f space_size) 
{
	this->position = position;
	this->size = size;
	this->space_size = space_size;
	for (int y = 0; y < size.y; y++) 
	{
		for (int x = 0; x < size.x; x++) 
		{
			this->grid_spaces.push_back(GridSpace(sf::Vector2f(position.x + x * space_size.x, position.y + y * space_size.y), space_size));
		}
	}
}

/*
	Call the draw function of all GridSpace(s) on this grid

	@param window pointer to the window to draw to 
*/
void Grid::draw(sf::RenderWindow & window) 
{
	for (GridSpace g : this->grid_spaces) 
	{
		g.draw(window);
	}
}

void Grid::draw(sf::RenderTexture & texture)
{
	for (GridSpace g : this->grid_spaces)
	{
		g.draw(texture);
	}
}

/*
	Call the draw function of a specific space on this grid

	@param window pointer to the window to draw to
	@param space_index the index of the space to draw
*/
void Grid::drawSpace(sf::RenderWindow & window, int space_index)
{
	this->grid_spaces[space_index].draw(window);
}

/*
	@returns size the size of this grid
*/
sf::Vector2i Grid::getSize() {
	return this->size;
}

sf::Vector2f Grid::getPosition() {
	return this->position;
}

sf::Vector2f Grid::getRectSize() {
	return sf::Vector2f(this->size.x * this->space_size.x, this->size.y * this->space_size.y);
}