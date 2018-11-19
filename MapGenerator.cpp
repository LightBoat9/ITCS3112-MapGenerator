#include "MapGenerator.h"

MapGenerator::MapGenerator() {}

MapGenerator::MapGenerator(sf::Vector2<int> grid_size) {
	this->grid_size = grid_size;
}

void MapGenerator::setGridSize(sf::Vector2<int> grid_size) {
	this->grid_size = grid_size;
}