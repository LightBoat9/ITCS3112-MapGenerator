#include "GridObject.h"

#include <SFML/Graphics.hpp>

#include <iostream>


/*
	Constructor

	@param texture_file the path to the file to use as this objects texture
*/
GridObject::GridObject(std::string texture_file)
{
	texture.loadFromFile(texture_file);
}

/*
	Set the position of this object

	@param position the position to set this object to 
*/
void GridObject::setPosition(sf::Vector2f position)
{
	this->position = position;
}

/*
	@return the position of this object
*/
sf::Vector2f GridObject::getPosition() {
	return position;
}

/*
	Draw this objects texture to the window

	@param window pointer to the window to draw to
*/
void GridObject::draw(sf::RenderWindow & window)
{
	sf::Vector2i mp = sf::Mouse::getPosition(window);

	if (mp.x >= position.x && mp.y >= position.y && mp.x < position.x + texture.getSize().x && mp.y < position.y + texture.getSize().y) {
		sprite.setColor(sf::Color::Red);
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
	window.draw(sprite);
}

Wall::Wall() : GridObject("tiles/wall.png") {};

Floor::Floor() : GridObject("tiles/floor.png") {};