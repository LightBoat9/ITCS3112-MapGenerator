#ifndef GRID_SPACE_H
#define GRID_SPACE_H

#include <SFML/Graphics.hpp>

#include "GridObject.h"

#include <list>

class GridSpace {
private:
	std::list<GridObject> objects;
	sf::Vector2f position;
	sf::Vector2f size;
public:
	GridSpace(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow & window);
};


#endif