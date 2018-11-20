#include "Grid.h"

Grid::Grid(sf::Vector2f position, sf::Vector2f size, sf::Vector2f space_size) {
	this->position = position;
	this->size = size;
	this->space_size = space_size;
	for (int y = 0; y < size.y; y++) {
		for (int x = 0; x < size.x; x++) {
			this->grid_spaces.push_back(GridSpace(sf::Vector2f(position.x + x * space_size.x, position.y + y * space_size.y), space_size));
		}
	}
}

void Grid::draw(sf::RenderWindow & window) {
	for (GridSpace g : this->grid_spaces) {
		g.draw(window);
	}
}
