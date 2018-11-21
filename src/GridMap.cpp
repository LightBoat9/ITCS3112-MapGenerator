#include "GridMap.h"

/*
	Constructor

	@param position the upper left origin of this map
	@param size the number of spaces accross this map
	@param space_size the size of the spaces on this map
*/
GridMap::GridMap(sf::Vector2f position, sf::Vector2<int> size, sf::Vector2f space_size) : Grid(position, size, space_size)
{
	for (GridSpace & s : grid_spaces) {
		s.addObject(GridObject("tiles/wall.png"));
	}
}