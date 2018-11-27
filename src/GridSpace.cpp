#include "GridSpace.h"

#include <iostream>

/*
	Constructor

	@param position the position of this GridSpace
	@param size the width and height of this GridSpace
*/
GridSpace::GridSpace(sf::Vector2f position, sf::Vector2f size) 
{
	this->position = position;
	this->size = size;
}

/*
	Draws the objects on this space to the window

	@param window pointer to the window to draw to 
*/
void GridSpace::draw(sf::RenderWindow & window) 
{
	for (GridObject & o : grid_objects) {
		o.draw(window);
	}
}

/*
	Add a GridObject to this space

	@param object the object to add to this space
*/
void GridSpace::addObject(GridObject & object) {
	object.setPosition(position);
	this->grid_objects.push_back(object);
}

bool GridSpace::hasObject(std::string name) {
	for (GridObject & o : grid_objects) {
		if (o.getName() == name) {
			return true;
		}
	}
	return false;
}

GridObject & GridSpace::removeObject(int index) {
	GridObject & obj = grid_objects[index];
	grid_objects.erase(grid_objects.begin() + index);
	return obj;
}

void GridSpace::clearObjects() {
	while (grid_objects.size() > 0) {
		removeObject(0);
	}
}

bool GridSpace::isEmpty() {
	return grid_objects.size() == 0;
}