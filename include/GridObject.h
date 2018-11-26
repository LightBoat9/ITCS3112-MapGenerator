#ifndef GRID_OBJECT_H
#define GRID_OBJECT_H

#include <SFML/Graphics.hpp>

#include <string>


class GridObject 
{
private:
	std::string name = "object";
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position = sf::Vector2f();
public:
	GridObject(std::string texture_file);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void GridObject::draw(sf::RenderWindow & window);
};

class Wall : public GridObject
{
public:
	Wall();
};

class Floor : public GridObject
{
public:
	Floor();
};

#endif