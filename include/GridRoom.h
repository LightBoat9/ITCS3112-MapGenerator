#ifndef GRID_ROOM_H
#define GRID_ROOM_H

#include <SFML/Graphics.hpp>
#include <vector>

class GridRoom
{
protected:
	sf::Vector2i position;
	sf::Vector2i size;
public:
	GridRoom();
	GridRoom(sf::Vector2<int> position, sf::Vector2<int> size);
	sf::Vector2i randomPoint();
	sf::Vector2i getPosition();
	sf::Vector2i getSize();
	bool overlaps(GridRoom other);
};

#endif