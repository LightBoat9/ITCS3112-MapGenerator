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

sf::RenderWindow window(sf::VideoMode(1024, 576), "Map Generator");  // The window where the UI of the program is drawn
GridMap grid_map = GridMap(sf::Vector2f(200, 32), sf::Vector2<int>(15, 15), sf::Vector2f(32, 32));  // The GridMap for the user to interact with

// Vars for map generation speed and timing
double timer = 0.0;
double interval = 1.0 / 50.0;
int speed = 1;
int visible_count = 0;

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
}

/* Draws the current grid to the screen */
void drawGrid() 
{
	grid_map.draw(window);
}

/* Called once every "game loop" */
void update(double delta) 
{
    drawGrid();
}

int main()
{
    ready();
	std::chrono::high_resolution_clock::time_point last_time = std::chrono::high_resolution_clock::now();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		window.clear();

        std::chrono::high_resolution_clock::time_point current_time = std::chrono::high_resolution_clock::now();
        update(std::chrono::duration_cast<std::chrono::duration<double>>(current_time - last_time).count());
        last_time = current_time;

        window.display();
    }
    return 0;
}
