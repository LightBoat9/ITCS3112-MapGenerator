#ifndef GRID_OBJECT_H
#define GRID_OBJECT_H

#include <SFML/Graphics.hpp>

#include <string>


class GridObject 
{
protected:
	std::string name = "object";
	std::string type = "object";
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position = sf::Vector2f();
public:
	GridObject();
	GridObject(std::string texture_file);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	std::string getName();
	std::string getType();
	void GridObject::draw(sf::RenderWindow & window);
	void GridObject::draw(sf::RenderTexture & texture);
};

class Wall : public GridObject {
public:
	Wall();
};

class Floor : public GridObject {
public:
	Floor();
};

class Shrine : public GridObject {
public:
	Shrine();
};

class Stairs : public GridObject {
public:
	Stairs();
};

class RandomItem : public GridObject {
	char sprites[7][40] = {
		"tiles/potion.png",
		"tiles/axe.png",
		"tiles/bone.png",
		"tiles/book.png",
		"tiles/helmet.png",
		"tiles/shield.png",
		"tiles/helmet.png",
	};
public:
	RandomItem();
	void randomizeItem();
};

class Player : public GridObject {
public:
	Player();
};

#endif