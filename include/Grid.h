#ifndef GRID_H
#define GRID_H

#include "GridSpace.h"

#include <SFML/Graphics.hpp>

#include <vector>

class Grid
{
protected:
	std::vector<GridSpace> grid_spaces;
	sf::Vector2f position;
	sf::Vector2<int> size;
	sf::Vector2f space_size;
public:
	Grid(sf::Vector2f position, sf::Vector2<int> size, sf::Vector2f space_size);
	void draw(sf::RenderWindow & window);
	void drawSpace(sf::RenderWindow & window, int space_index);
	sf::Vector2<int> getSize();
};


#endif