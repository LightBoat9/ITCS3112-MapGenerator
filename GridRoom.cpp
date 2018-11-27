#include "GridRoom.h"

GridRoom::GridRoom(sf::Vector2<int> position, sf::Vector2<int> size) 
{
	this->position = position;
	this->size = size;
}

bool GridRoom::overlaps(GridRoom other) 
{
	if (position.x > other.position.x + other.size.x || other.position.x > position.x + size.x) return false;
	if (position.y < other.position.y + other.size.y || other.position.y < position.y + size.y) return false;
	return true;
}