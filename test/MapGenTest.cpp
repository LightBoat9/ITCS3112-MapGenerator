/*
	Unit testing for the Map Generator classes
	@author Luke Sloop
*/

#include "Button.h"
#include "Slider.h"
#include "GridMap.h"

#include "SFML/Graphics.hpp"
#include <iostream>

int ButtonConstructor(Button bt) {
	// Test the values set up in ButtonTest
	if (bt.getPosition().x != 20) return 1;
	if (bt.getPosition().y != 25) return 1;
	if (bt.getText() != "TestButton") return 1;
	return 0;
}

int ButtonPosition(Button bt) {
	// Change the position
	bt.setPosition(sf::Vector2f(50, 55));

	// Test the new position
	if (bt.getPosition().x != 50) return 1;
	if (bt.getPosition().y != 55) return 1;

	return 0;
}

int ButtonPadding(Button bt) {
	// Test Default Padding
	if (bt.getPadding() != 16) return 1;

	// Change the padding
	bt.setPadding(50);

	// Test the new padding
	if (bt.getPadding() != 50) return 1;

	return 0;
}

void ButtonTest() {
	// Create a button for testing
	sf::Font font;
	font.loadFromFile("fonts/Cave-Story.ttf");

	Button bt = Button(sf::Vector2f(20, 25), "TestButton", font);

	if (ButtonConstructor(bt) == 0) std::cout << "TestConstructor succeded" << std::endl;
	else std::cout << "TestConstructor failed" << std::endl;

	if (ButtonPosition(bt) == 0) std::cout << "TesetPosition succeded" << std::endl;
	else std::cout << "TestPosition failed" << std::endl;

	if (ButtonPadding(bt) == 0) std::cout << "TestPadding succeded" << std::endl;
	else std::cout << "TestPadding failed" << std::endl;

	std::cout << "ButtonTest completed" << std::endl << std::endl;
}

int SliderConstructor(Slideri sd) {
	// Test default values of constructor
	if (sd.getPosition().x != 30) return 1;
	if (sd.getPosition().y != 35) return 1;
	if (sd.getMin() != 5) return 1;
	if (sd.getMax() != 10) return 1;
	return 0;
}

int SliderPosition(Slideri sd) {
	// Test position after changed
	sd.setPosition(sf::Vector2f(10, 5));

	if (sd.getPosition().x != 10) return 1;
	if (sd.getPosition().y != 5) return 1;
	return 0;
}

int SliderMinMax(Slideri sd) {
	// Test setting min and max
	sd.setMin(20);
	sd.setMax(30);

	if (sd.getMin() != 20) return 1;
	if (sd.getMax() != 30) return 1;
	return 0;
}

void SliderTest() {
	Slideri sd = Slideri(sf::Vector2f(30, 35), 5, 10, sf::Vector2f(10, 20), sf::Vector2f(30, 20));

	if (SliderConstructor(sd) == 0) std::cout << "SliderConstructor succeded" << std::endl;
	else std::cout << "SliderConstructor failed" << std::endl;

	if (SliderPosition(sd) == 0) std::cout << "SliderPosition succeded" << std::endl;
	else std::cout << "SliderPosition failed" << std::endl;

	std::cout << "SliderTest completed" << std::endl << std::endl;
}

int GridConstructor(Grid gr) {
	// Test values setup in gridtest
	if (gr.getPosition().x != 10) return 1;
	if (gr.getPosition().y != 15) return 1;
	if (gr.getSize().x != 20) return 1;
	if (gr.getSize().y != 30) return 1;
	if (gr.getSpaceSize().x != 10) return 1;
	if (gr.getSpaceSize().y != 20) return 1;
	return 0;
}

int GridPosition(Grid gr) {
	// Test setting the grid position
	gr.setPosition(sf::Vector2f(50, 60));

	if (gr.getPosition().x != 50) return 1;
	if (gr.getPosition().y != 60) return 1;
	return 0;
}

int GridSize(Grid gr) {
	// Test setting the grid size
	gr.setSize(sf::Vector2i(20, 50));

	if (gr.getSize().x != 20) return 1;
	if (gr.getSize().y != 50) return 1;
	return 0;
}

int GridSpaceSize(Grid gr) {
	// Test setting the grid space size
	gr.setSpaceSize(sf::Vector2f(20, 40));

	if (gr.getSpaceSize().x != 20) return 1;
	if (gr.getSpaceSize().y != 40) return 1;
	return 0;
}

void GridTest() {
	Grid gr = Grid(sf::Vector2f(10, 15), sf::Vector2i(20, 30), sf::Vector2f(10, 20));

	if (GridConstructor(gr) == 0) std::cout << "GridConstructor succeded" << std::endl;
	else std::cout << "GridConstructor failed" << std::endl;

	if (GridPosition(gr) == 0) std::cout << "GridPosition succeded" << std::endl;
	else std::cout << "GridPosition failed" << std::endl;

	if (GridSize(gr) == 0) std::cout << "GridSize succeded" << std::endl;
	else std::cout << "GridSize failed" << std::endl;

	if (GridSpaceSize(gr) == 0) std::cout << "GridSpaceSize succeded" << std::endl;
	else std::cout << "GridSpaceSize failed" << std::endl;

	std::cout << "GridTest completed" << std::endl << std::endl;
}

int GridMapConstructor(GridMap gm) {
	// Test the values set in GridMapTest
	if (gm.getPosition().x != 50) return 1;
	if (gm.getPosition().y != 20) return 1;
	if (gm.getSize().x != 5) return 1;
	if (gm.getSize().y != 10) return 1;
	if (gm.getSpaceSize().x != 50) return 1;
	if (gm.getSpaceSize().y != 60) return 1;
	return 0;
}

int GridMapPosition(GridMap gm) {
	// Test setting the gridmap position
	gm.setPosition(sf::Vector2f(50, 60));

	if (gm.getPosition().x != 50) return 1;
	if (gm.getPosition().y != 60) return 1;
	return 0;
}

int GridMapSize(GridMap gm) {
	// Test setting the gridmap position
	gm.setSize(sf::Vector2i(15, 20));

	if (gm.getSize().x != 15) return 1;
	if (gm.getSize().y != 20) return 1;
	return 0;
}

int GridMapSpaceSize(GridMap gm) {
	// Test setting the gridmap space size
	gm.setSpaceSize(sf::Vector2f(30, 50));

	if (gm.getSpaceSize().x != 30) return 1;
	if (gm.getSpaceSize().y != 50) return 1;
	return 0;
}

int GridMapSeed(GridMap gm) {
	// Test setting the gridmap seed
	gm.setSeed(100);

	if (gm.getSeed() != 100) return 1;
	return 0;
}

int GridMapRoomSize(GridMap gm) {
	// Test setting the gridmap room size
	gm.setRoomSize(sf::Vector2i(15, 20));

	if (gm.getRoomSize().x != 15) return 1;
	if (gm.getRoomSize().y != 20) return 1;
	return 0;
}

int GridMapEnemyAttempts(GridMap gm) {
	// Test seeting the enemy attempts
	gm.setEnemyAttempts(15);

	if (gm.getEnemyAttempts() != 15) return 1;
	return 0;
}

int GridMapItemAttempts(GridMap gm) {
	// Test setting the item attempts
	gm.setItemAttempts(30);

	if (gm.getitemAttempts() != 30) return 1;
	return 0;
}

int GridMapRoomAttempts(GridMap gm) {
	// Test setting the room attempts
	gm.setRoomAttempts(25);

	if (gm.getRoomAttempts() != 25) return 1;
	return 0;
}

void GridMapTest() {
	GridMap gm = GridMap(sf::Vector2f(50, 20), sf::Vector2<int>(5, 10), sf::Vector2f(50, 60));

	if (GridMapConstructor(gm) == 0) std::cout << "GridMapConstructor succeded" << std::endl;
	else std::cout << "GridMapConstructor failed" << std::endl;

	if (GridMapPosition(gm) == 0) std::cout << "GridMapPosition succeded" << std::endl;
	else std::cout << "GridMapPosition failed" << std::endl;

	if (GridMapSize(gm) == 0) std::cout << "GridMapSize succeded" << std::endl;
	else std::cout << "GridMapSize failed" << std::endl;

	if (GridMapSpaceSize(gm) == 0) std::cout << "GridMapSpaceSize succeded" << std::endl;
	else std::cout << "GridMapSpaceSize failed" << std::endl << std::endl;

	if (GridMapSeed(gm) == 0) std::cout << "GridMapSeed succeded" << std::endl;
	else std::cout << "GridMapSeed failed" << std::endl << std::endl;

	if (GridMapRoomSize(gm) == 0) std::cout << "GridMapRoomSize succeded" << std::endl;
	else std::cout << "GridMapRoomSize failed" << std::endl << std::endl;

	if (GridMapEnemyAttempts(gm) == 0) std::cout << "GridMapEnemyAttempts succeded" << std::endl;
	else std::cout << "GridMapEnemyAttempts failed" << std::endl << std::endl;

	if (GridMapItemAttempts(gm) == 0) std::cout << "GridMapItemAttempts succeded" << std::endl;
	else std::cout << "GridMapItemAttempts failed" << std::endl << std::endl;

	if (GridMapRoomAttempts(gm) == 0) std::cout << "GridMapRoomAttempts succeded" << std::endl;
	else std::cout << "GridMapRoomAttempts failed" << std::endl << std::endl;

	std::cout << "GridMapTest completed" << std::endl << std::endl;
}

int GridObjectPosition(GridObject go) {
	// Test setting the gridobjects position
	go.setPosition(sf::Vector2f(50, 35));

	if (go.getPosition().x != 50) return 1;
	if (go.getPosition().y != 35) return 1;
	return 0;
}

void GridObjectTest() {
	GridObject go = GridObject();

	if (GridObjectPosition(go) == 0) std::cout << "GridObjectPosition succeded" << std::endl;
	else std::cout << "GridObjectPosition failed" << std::endl << std::endl;

	std::cout << "GridObjectTest completed" << std::endl << std::endl;
}

int main() {
	ButtonTest();
	SliderTest();
	GridTest();
	GridMapTest();
	GridObjectTest();
	
	return 0;
}