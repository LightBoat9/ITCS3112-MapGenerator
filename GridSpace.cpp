#include "GridSpace.h"

GridSpace::GridSpace(sf::Vector2f position, sf::Vector2f size) {
	this->position = position;
	this->size = size;
}

void GridSpace::draw(sf::RenderWindow & window) {
	sf::Texture tex_wall;
	tex_wall.loadFromFile("tiles/wall.png");

	sf::Sprite spr_wall;
	spr_wall.setTexture(tex_wall);
	spr_wall.setPosition(this->position);

	window.draw(spr_wall);
}
