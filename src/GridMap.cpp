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
		s.addObject(Wall());
	}
	std::srand(5);
	int r = std::rand() % size.x;
	for (int i = 0; i < grid_spaces.size(); i++) {
		if (i % size.x == r) {
			grid_spaces[i].removeObject(0);
			grid_spaces[i].addObject(Floor());
		}
	}
}