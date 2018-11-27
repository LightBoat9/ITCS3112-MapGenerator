#ifndef GRID_ROOM_H
#define GRID_ROOM_H

#include <SFML/Graphics.hpp>
#include <vector>

class GridRoom
{
protected:
	sf::Vector2<int> position;
	sf::Vector2<int> size;
public:
	GridRoom(sf::Vector2<int> position, sf::Vector2<int> size);
	bool overlaps(GridRoom other);
};

#endif