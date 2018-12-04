#include "GridMap.h"
#include <iostream>
#include <queue>

GridMap::GridMap() {}

/*
	Constructor

	@param position the upper left origin of this map
	@param size the number of spaces accross this map
	@param space_size the size of the spaces on this map
*/
GridMap::GridMap(sf::Vector2f position, sf::Vector2<int> size, sf::Vector2f space_size) : Grid(position, size, space_size)
{}

/*
	Return a random point inside the grid, if limit is passed it returns a point inside a subgrid

	@param limit optional reduction of the grid size

	@return a random point on this GridMap
*/
sf::Vector2<int> GridMap::randomPoint(sf::Vector2<int> minLimit = sf::Vector2<int>(0, 0), sf::Vector2<int> maxLimit = sf::Vector2<int>(0, 0)) {
	return sf::Vector2<int>(minLimit.x + rand() % ((size.x - maxLimit.x + 1) - minLimit.x), minLimit.y + rand() % ((size.y - maxLimit.y + 1) - minLimit.y));
}

int GridMap::makeOdd(int value) {
	if (value % 2 == 1) return value;
	if (value > 0) {
		return value - 1;
	}
	else {
		return value + 1;
	}
}

sf::Vector2<int> GridMap::randomRoomSize() {
	return sf::Vector2<int>(makeOdd(room_size.x + rand() % ((room_size.y + 1) - room_size.x)), makeOdd(room_size.x + rand() % ((room_size.y + 1) - room_size.x)));
}

void GridMap::generateRooms() {
	rooms = std::vector<GridRoom>();
	// Attempt to create valid rooms n number of times (room_attempts)
	for (int i = 0; i < room_attempts; i++) {
		sf::Vector2<int> r_size = randomRoomSize();
		sf::Vector2<int> r_pos = randomPoint(sf::Vector2<int>(1, 1), r_size + sf::Vector2<int>(1, 1)); // Get a random position but limit the bottom right of the room to 1 away from the grid edge
		r_pos = sf::Vector2<int>(makeOdd(r_pos.x), makeOdd(r_pos.y));
		GridRoom test_room = GridRoom(r_pos, r_size);
		bool valid = true;
		// Make sure it does not overlap existing rooms
		for (GridRoom r : rooms) {
			if (test_room.overlaps(r)) {
				valid = false;
				break;
			}
		}
		// If its valid add it to the list
		if (valid) {
			rooms.push_back(test_room);
		}
	}
}

void GridMap::carveRooms() {
	for (GridRoom & r : rooms) {
		sf::Vector2<int> p = r.getPosition();
		for (int y = 0; y < r.getSize().y; y++) {
			for (int x = 0; x < r.getSize().x; x++) {
				grid_spaces[p.x + x + (p.y + y) * size.x].clearObjects();
				grid_spaces[p.x + x + (p.y + y) * size.x].addObject(Floor());
			}
		}
	}
}

void GridMap::connectRooms() {
	GridRoom last_room;
	if (rooms.size() > 0) {
		last_room = rooms[0];
		for (int r = 1; (unsigned int)r < rooms.size(); r++) {
			GridRoom goal_room = rooms[r];
			int x_dist = last_room.getPosition().x - goal_room.getPosition().x;
			int y_dist = last_room.getPosition().y - goal_room.getPosition().y;

			sf::Vector2<int> point = sf::Vector2<int>(last_room.getPosition().x + (x_dist < 0 ? last_room.getSize().x : -1), last_room.getPosition().y + rand() % last_room.getSize().y);
			sf::Vector2<int> goal_point = sf::Vector2<int>(goal_room.getPosition().x + rand() % goal_room.getSize().x, goal_room.getPosition().y + (y_dist > 0 ? goal_room.getSize().y : -1));

			grid_spaces[point.x + point.y * size.x].clearObjects();
			grid_spaces[point.x + point.y * size.x].addObject(Floor());

			while (point != goal_point) {
				if (point.x > goal_point.x || point.x < goal_point.x) point.x += (goal_point.x - point.x > 0) - (goal_point.x - point.x < 0);
				else if (point.y < goal_point.y) point.y += 1;
				else if (point.y > goal_point.y) point.y -= 1;

				grid_spaces[point.x + point.y * size.x].clearObjects();
				grid_spaces[point.x + point.y * size.x].addObject(Floor());
			}

			last_room = goal_room;
		}
	}
}

void GridMap::removeDeadEnds() {
	for (int y = 0; y < size.y; y++) {
		for (int x = 0; x < size.x; x++) {
			int count = 0;
			if (x - 1 > 0 && grid_spaces[(x - 1) + y * size.x].hasObject("floor")) count += 1;
			if (y - 1 > 0 && grid_spaces[x + (y - 1) * size.x].hasObject("floor")) count += 1;
			if (x + 1 < size.x && grid_spaces[(x + 1) + y * size.x].hasObject("floor")) count += 1;
			if (y + 1 < size.y && grid_spaces[x + (y + 1) * size.x].hasObject("floor")) count += 1;
			if (count <= 1) {
				grid_spaces[x + y * size.x].clearObjects();
				grid_spaces[x + y * size.x].addObject(Wall());
			}
		}
	}
}

template <class T>
void GridMap::fill() {
	for (GridSpace & s : grid_spaces) {
		s.addObject(T());
	}
}

void GridMap::addItems() {
	if (hasRooms()) {
		for (int i = 0; i < item_attempts; i++) {
			RandomItem g = RandomItem();
			g.randomizeItem();
			addObjectRandom(g);
		}
	}
}

void GridMap::clear() {
	for (GridSpace & s : grid_spaces) {
		s.clearObjects();
	}
}

void GridMap::setSeed(int seed) {
	srand(seed);
}

GridRoom GridMap::randomRoom() {
	return rooms[rand() % rooms.size()];
}

bool GridMap::hasRooms() {
	return rooms.size() > 0;
}

bool GridMap::isFull(std::string avoid_type) {
	for (int r = 0; r < rooms.size(); r++) {
		GridRoom room = rooms[r];
		for (int i = 0; i < room.getSize().x * room.getSize().y; i++) {
			sf::Vector2i p = room.getPosition() + sf::Vector2i(i % room.getSize().x, i / room.getSize().x);
			if (!grid_spaces[p.x + p.y * size.x].hasObjectType(avoid_type)) {
				return false;
			}
		}
	}
	return true;
}

void GridMap::setRoomAttempts(int room_attempts) {
	this->room_attempts = room_attempts;
}

void GridMap::setItemAttempts(int item_attempts) {
	this->item_attempts = item_attempts;
}

void GridMap::setRoomSize(sf::Vector2i room_size) {
	this->room_size = room_size;
}

sf::Vector2i GridMap::getRoomSize() {
	return room_size;
}

sf::Vector2i GridMap::randomRoomPoint(std::string avoid_type="") {
	sf::Vector2i p = randomRoom().randomPoint();
	while (grid_spaces[p.x + p.y * size.x].hasObjectType(avoid_type)) {
		p = randomRoom().randomPoint();
	}
	return p;
}

void GridMap::addObjectRandom(GridObject & object) {
	if (hasRooms() && !isFull("object")) {
		sf::Vector2i p = randomRoomPoint("object");
		grid_spaces[p.x + p.y * size.x].addObject(object);
	}
}

void GridMap::generate() {
	clear();
	fill<Wall>();
	generateRooms();
	carveRooms();
	connectRooms();
	removeDeadEnds();
	// Add the player
	addObjectRandom(Player());
	// Add the stairs
	addObjectRandom(Stairs());
	// Add the shrine
	addObjectRandom(Shrine());
	// Add the random items
	addItems();
}