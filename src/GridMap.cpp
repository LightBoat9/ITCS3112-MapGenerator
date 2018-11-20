#include "GridMap.h"

GridMap::GridMap(sf::Vector2f position, sf::Vector2f size, sf::Vector2f space_size) 
	:Grid(position, size, space_size) 
{

}

void GridMap::setGridSize(sf::Vector2<int> grid_size) {
	this->grid_size = grid_size;
}