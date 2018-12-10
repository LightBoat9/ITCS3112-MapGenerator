#include "Grid.h"

/**
	Invalid Constructor
*/
Grid::Grid() {}

/**
	Create a grid at the position relative to the window, with a grid size, and space size

	@param position the upper left origin of this map
	@param size the number of spaces accross this map
	@param space_size the size of the spaces on this map
*/
Grid::Grid(sf::Vector2f position, sf::Vector2i size, sf::Vector2f space_size) 
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

/**
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
/**
	Call the draw function of all GridSpace(s) on this grid

	@param texture pointer to the texture to draw to 
*/
void Grid::draw(sf::RenderTexture & texture)
{
	for (GridSpace g : this->grid_spaces)
	{
		g.draw(texture);
	}
}

/**
	Call the draw function of a specific space on this grid

	@param window pointer to the window to draw to
	@param space_index the index of the space to draw
*/
void Grid::drawSpace(sf::RenderWindow & window, int space_index)
{
	this->grid_spaces[space_index].draw(window);
}

/**
	Set the size of this grid. This is the number of gridspaces in this grid

	@size the number of gridspaces on this grid
*/
void Grid::setSize(sf::Vector2i size) {
	this->size = size;
}

/**
	@return size the size of this grid
*/
sf::Vector2i Grid::getSize() {
	return this->size;
}

/**
	Set the position of this grid relative to the window

	@param position the position relative to the window
*/
void Grid::setPosition(sf::Vector2f position) {
	this->position = position;
}

/**
	@return the position of this grid relative to the window
*/
sf::Vector2f Grid::getPosition() {
	return this->position;
}

/**
	@return the size of this grid's spaces
*/
sf::Vector2f Grid::getSpaceSize() {
	return this->space_size;
}

/**
	Set the size for the spaces on this grid

	@params space_size the size for the spaces on this grid
*/
void Grid::setSpaceSize(sf::Vector2f space_size) {
	this->space_size = space_size;
}

/**
	@return the total size across this grid
*/
sf::Vector2f Grid::getRectSize() {
	return sf::Vector2f(this->size.x * this->space_size.x, this->size.y * this->space_size.y);
}