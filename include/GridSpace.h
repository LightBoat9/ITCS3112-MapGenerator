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
	GridSpace();
	GridSpace(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow & window);
	void draw(sf::RenderTexture & texture);
	void addObject(GridObject & object);
	bool hasObject(std::string name);
	bool hasObjectType(std::string type);
	bool isEmpty();
	GridObject & removeObject(int index);
	void clearObjects();
};


#endif