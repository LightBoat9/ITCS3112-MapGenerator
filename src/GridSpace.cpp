#include "GridSpace.h"

#include <iostream>

GridSpace::GridSpace() {}

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
	Draw the objects on this space to the texture

	@param the texture to draw onto
*/
void GridSpace::draw(sf::RenderTexture & texture)
{
	for (GridObject & o : grid_objects) {
		o.draw(texture);
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

/*
	@param name the name of the object to check for

	@return true if this space has an object with the name
*/
bool GridSpace::hasObject(std::string name) {
	for (GridObject & o : grid_objects) {
		if (o.getName() == name) {
			return true;
		}
	}
	return false;
}

/*
	@param type the string type of the object to check for

	@return true if this space has an object of the type
*/
bool GridSpace::hasObjectType(std::string type) {
	for (GridObject & o : grid_objects) {
		if (o.getType() == type) {
			return true;
		}
	}
	return false;
}

/*
	Remove and return the object at the index on this gridspace

	@return the object removed
*/
GridObject & GridSpace::removeObject(int index) {
	GridObject & obj = grid_objects[index];
	grid_objects.erase(grid_objects.begin() + index);
	return obj;
}

/*
	Remove all objects from this gridspace
*/
void GridSpace::clearObjects() {
	while (grid_objects.size() > 0) {
		removeObject(0);
	}
}

/*
	@return true if this space contains no objects
*/
bool GridSpace::isEmpty() {
	return grid_objects.size() == 0;
}