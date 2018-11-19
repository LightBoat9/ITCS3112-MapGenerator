#ifndef MAP_GENERATOR_H
#define MAP_GENERATOR_H

#include <SFML/Graphics.hpp>

class MapGenerator {
private:
	sf::Vector2<int> grid_size = sf::Vector2<int>(21, 21);

public:
	MapGenerator();
	MapGenerator(sf::Vector2<int> grid_size);
	void setGridSize(sf::Vector2<int> grid_size);
};

#endif