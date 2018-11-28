#ifndef GRID_MAP_H
#define GRID_MAP_H

#include "Grid.h"
#include "GridRoom.h"

#include <SFML/Graphics.hpp>

class GridMap : public Grid 
{
protected:
	int seed;
	int room_attempts = 200;
	int room_min_size = 3;
	int room_max_size = 7;
	std::vector<GridRoom> rooms;
	sf::Vector2<int> grid_size = sf::Vector2<int>(21, 21);
	void generateRooms();
	void carveRooms();
	void connectRooms();
	void removeDeadEnds();
	int makeOdd(int value);
	template<class T> void fill();
public:
	GridMap(sf::Vector2f position, sf::Vector2<int> size, sf::Vector2f space_size);
	sf::Vector2<int> randomPoint(sf::Vector2<int> minLimit, sf::Vector2<int> maxLimit);
	sf::Vector2<int> randomRoomSize();
	void setSeed(int seed);
	void clear();
	void generate();
	void generate(int step);
};

#endif