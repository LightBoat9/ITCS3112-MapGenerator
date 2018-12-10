#include "GridObject.h"

#include <SFML/Graphics.hpp>

#include <iostream>

GridObject::GridObject() {}

/**
	Constructor

	@param texture_file the path to the file to use as this objects texture
*/
GridObject::GridObject(std::string texture_file)
{
	texture.loadFromFile(texture_file);
}

/**
	Set the position of this object

	@param position the position to set this object to 
*/
void GridObject::setPosition(sf::Vector2f position)
{
	this->position = position;
}

/**
	@return the position of this object
*/
sf::Vector2f GridObject::getPosition() {
	return position;
}

/**
	@return the name of this gridobject
*/
std::string GridObject::getName() {
	return name;
}

/**
	@return the type of this gridobject
*/
std::string GridObject::getType() {
	return type;
}

/**
	Draw this objects texture to the window

	@param window pointer to the window to draw to
*/
void GridObject::draw(sf::RenderWindow & window)
{
	sprite.setTexture(texture);
	sprite.setPosition(position);
	window.draw(sprite);
}

/**
	Draw this objects texture to the rendertexture

	@param texture pointer to the texture to draw to
*/
void GridObject::draw(sf::RenderTexture & texture)
{
	sprite.setTexture(this->texture);
	sprite.setPosition(sf::Vector2f(position));
	texture.draw(sprite);
}


// Subclass objects

Wall::Wall() : GridObject("tiles/wall.png") {
	name = "wall";
	type = "wall";
};

Floor::Floor() : GridObject("tiles/floor.png") {
	name = "floor";
	type = "floor";
};

RandomItem::RandomItem() : GridObject("tiles/potion.png") {
	name = "item";
}

void RandomItem::randomizeItem() {
	std::string s = sprites[rand() % sizeof(sprites)/sizeof(*sprites)];
	texture.loadFromFile(s);
}

RandomEnemy::RandomEnemy() : GridObject("tiles/ghost.png") {
	name = "enemy";
}

void RandomEnemy::randomizeEnemy() {
	std::string s = sprites[rand() % sizeof(sprites) / sizeof(*sprites)];
	texture.loadFromFile(s);
}

Player::Player() : GridObject("tiles/player.png") {
	name = "player";
}

Shrine::Shrine() : GridObject("tiles/shrine.png") {
	name = "shrine";
}

Stairs::Stairs() : GridObject("tiles/stairs.png") {
	name = "stairs";
}
