#ifndef GRID_SPACE_H
#define GRID_SPACE_H

#include <SFML/Graphics.hpp>

#include "GridObject.h"

#include <vector>

class GridSpace 
{
protected:
	std::vector<GridObject> grid_objects;
	sf::Vector2f position;
	sf::Vector2f size;
public:
	GridSpace(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow & window);
	void addObject(GridObject object);
};


#endif