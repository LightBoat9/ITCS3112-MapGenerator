#ifndef GRID_H
#define GRID_H

#include "GridSpace.h"

#include <SFML/Graphics.hpp>

#include <list>

class Grid {
private:
	std::list<GridSpace> grid_spaces;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f space_size;
public:
	Grid(sf::Vector2f position, sf::Vector2f size, sf::Vector2f space_size);
	void draw(sf::RenderWindow & window);
};


#endif