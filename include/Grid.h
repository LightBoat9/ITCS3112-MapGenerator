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
	sf::Vector2i size;
	sf::Vector2f space_size;
public:
	Grid();
	Grid(sf::Vector2f position, sf::Vector2<int> size, sf::Vector2f space_size);
	void draw(sf::RenderWindow & window);
	void draw(sf::RenderTexture & texture);
	void drawSpace(sf::RenderWindow & window, int space_index);
	void setSize(sf::Vector2i size);
	sf::Vector2i getSize();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getRectSize();
	sf::Vector2f getSpaceSize();
	void setSpaceSize(sf::Vector2f space_size);
};


#endif