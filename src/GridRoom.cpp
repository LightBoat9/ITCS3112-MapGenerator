#include "GridRoom.h"

GridRoom::GridRoom() {}

GridRoom::GridRoom(sf::Vector2i position, sf::Vector2i size) 
{
	this->position = position;
	this->size = size;
}

bool GridRoom::overlaps(GridRoom other) 
{
	if (position.x > other.position.x + other.size.x || other.position.x > position.x + size.x) return false;
	if (position.y > other.position.y + other.size.y || other.position.y > position.y + size.y) return false;
	return true;
}

sf::Vector2i GridRoom::getPosition() {
	return position;
}

sf::Vector2i GridRoom::getSize() {
	return size;
}

sf::Vector2i GridRoom::randomPoint() {
	return sf::Vector2i(position.x + (rand() % size.x), position.y + (rand() % size.y));
}