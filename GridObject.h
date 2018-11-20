#ifndef GRID_OBJECT_H
#define GRID_OBJECT_H

#include <SFML/Graphics.hpp>

#include <string>


class GridObject : sf::Sprite {
private:
	std::string name = "object";
public:
	GridObject(const sf::Texture & texture);
};


#endif