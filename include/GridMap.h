#ifndef GRID_MAP_H
#define GRID_MAP_H

#include <string>

#include "Grid.h"
#include "GridRoom.h"

#include <SFML/Graphics.hpp>

class GridMap : public Grid 
{
protected:
	int seed;
	int room_attempts = 200;
	int item_attempts = 20;
	std::vector<GridRoom> rooms;
	sf::Vector2i grid_size = sf::Vector2<int>(21, 21);
	sf::Vector2i room_size = sf::Vector2i(3, 7);
	void generateRooms();
	void carveRooms();
	void connectRooms();
	void removeDeadEnds();
	void addItems();
	int makeOdd(int value);
	template<class T> void fill();
public:
	GridMap();
	GridMap(sf::Vector2f position, sf::Vector2<int> size, sf::Vector2f space_size);
	sf::Vector2i randomPoint(sf::Vector2<int> minLimit, sf::Vector2<int> maxLimit);
	sf::Vector2i randomRoomPoint(std::string avoid_type);
	void addObjectRandom(GridObject & object);
	GridRoom randomRoom();
	bool hasRooms();
	bool isFull(std::string avoid_type);
	sf::Vector2<int> randomRoomSize();
	void setSeed(int seed);
	void setRoomAttempts(int room_attempts);
	void setItemAttempts(int item_attempts);
	void setRoomSize(sf::Vector2i room_size);
	sf::Vector2i getRoomSize();
	void clear();
	void generate();
};

#endif