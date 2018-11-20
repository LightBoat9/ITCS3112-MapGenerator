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

sf::RenderWindow window(sf::VideoMode(1024, 576), "Map Generator");
GridMap grid = GridMap(sf::Vector2f(64, 32), sf::Vector2f(21, 21), sf::Vector2f(16, 16));

// Vars for map generation speed and timing
double timer = 0.0;
double interval = 1.0 / 50.0;
int speed = 3;
int visible_count = 0;

/* Centers the window based on the users screen size*/
void centerWindow() {
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	sf::Vector2<int> screen_size = sf::Vector2<int>(desktop.right, desktop.bottom);
	window.setPosition(sf::Vector2<int>(screen_size.x / 2 - window.getSize().x / 2, screen_size.y / 2 - window.getSize().y / 2));
}

/* Runs once at program start */
void ready() {
	centerWindow();
}

/* Draws the current grid to the screen */
void drawGrid() {
    /*sf::Texture tex_wall;
    tex_wall.loadFromFile("tiles/wall.png");

    sf::Sprite spr_wall;
    spr_wall.setTexture(tex_wall);

    for (int i = 0; i < visible_count; i++) {
        spr_wall.setPosition(sf::Vector2f(16 + 16 * (i % grid_size.x), 16 + 16 * (i / grid_size.x)));
        window.draw(spr_wall);
    }*/
	grid.draw(window);
}

/* Called once every "game loop" */
void update(double delta) {
	/*
    if (visible_count < grid_size.x * grid_size.y) {
        timer += delta;
        if (timer >= interval) {
            visible_count += speed;
            timer = 0.0;
        }
    }
    else {
        visible_count = grid_size.x * grid_size.y;
    }*/

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
