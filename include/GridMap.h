#ifndef GRID_MAP_H
#define GRID_MAP_H

#include "Grid.h"

#include <SFML/Graphics.hpp>

class GridMap : public Grid {
private:
	sf::Vector2<int> grid_size = sf::Vector2<int>(21, 21);
public:
	GridMap(sf::Vector2f position, sf::Vector2f size, sf::Vector2f space_size);
	void setGridSize(sf::Vector2<int> grid_size);
};

#endif