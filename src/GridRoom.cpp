#include "GridRoom.h"

/**
	Invalid constructor
*/
GridRoom::GridRoom() {}

/**
	Construct a new GridRoom with upper left at position and a grid size of size

	@param position the upper left of this room relative to the grid
	@param size the size of gridspaces this room contains
*/
GridRoom::GridRoom(sf::Vector2i position, sf::Vector2i size) 
{
	this->position = position;
	this->size = size;
}

/**
	Return true if this GridRoom overlaps the other GridRoom

	@param other the other GridRoom to check for overlap
	@return true if this GridRoom overlaps the other GridRoom
*/
bool GridRoom::overlaps(GridRoom other) 
{
	if (position.x > other.position.x + other.size.x || other.position.x > position.x + size.x) return false;
	if (position.y > other.position.y + other.size.y || other.position.y > position.y + size.y) return false;
	return true;
}

/**
	@return the position of this room on a grid
*/
sf::Vector2i GridRoom::getPosition() {
	return position;
}

/**
	@return the size of this room, number of spaces this room contains
*/
sf::Vector2i GridRoom::getSize() {
	return size;
}

/**
	@return a random point inside this room relative to its position
*/
sf::Vector2i GridRoom::randomPoint() {
	return sf::Vector2i(position.x + (rand() % size.x), position.y + (rand() % size.y));
}
