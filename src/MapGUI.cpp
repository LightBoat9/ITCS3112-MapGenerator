/*
	Main driver for the MapGenerator project. Displays the map to the screen and allows user input for manipulating the map.
*/
#include "GridMap.h"

#include <SFML/Graphics.hpp>

#include <wtypes.h>
#include <chrono>
#include <ctime>
#include <ratio>
#include <iostream>

sf::RenderWindow window(sf::VideoMode(1280, 720), "Map Generator");  // The window where the UI of the program is drawn
GridMap grid_map = GridMap(sf::Vector2f(256, 16), sf::Vector2<int>(31, 21), sf::Vector2f(32, 32));  // The GridMap for the user to interact with
sf::Font font;
int seed = rand();
bool display = true;
sf::Text text;

/* Centers the window based on the users screen size*/
void centerWindow() 
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	sf::Vector2<int> screen_size = sf::Vector2<int>(desktop.right, desktop.bottom);
	window.setPosition(sf::Vector2<int>(screen_size.x / 2 - window.getSize().x / 2, screen_size.y / 2 - window.getSize().y / 2));
}

/* Runs once at program start */
void ready() 
{
	centerWindow();
	grid_map.setSeed(seed);
	grid_map.generate();
	font.loadFromFile("fonts/Cave-Story.ttf");

	// Font stuff
	text.setFont(font);
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);
}

/* Draws the current grid to the screen */
void drawGrid() 
{
	grid_map.draw(window);
}

void drawUI() {
	text.setPosition(sf::Vector2f(16, 16));
	text.setString("Seed: " + std::to_string(seed));
	window.draw(text);

	text.setPosition(sf::Vector2f(16, 80));
	text.setString("Controls:");
	window.draw(text);


	text.setPosition(sf::Vector2f(16, 112));
	text.setString("Click: Random Seed");
	window.draw(text);
}

/* Called once every "game loop" */
void update() 
{
	drawGrid();
	drawUI();
}

int main()
{
	// Call ready function
    ready();

	// Handle Game Loop
    while (window.isOpen())
    {
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				seed = rand();
				window.clear();
				drawUI();
				window.display();
				grid_map.setSeed(seed);
				grid_map.generate();
				display = true;
			}
        }

		if (display) {
			window.clear();
			update();
			window.display();
			display = false;
		}
    }
    return 0;
}
