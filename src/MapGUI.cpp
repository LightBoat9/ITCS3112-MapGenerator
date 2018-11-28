/*
	Main driver for the MapGenerator project. Displays the map to the screen and allows user input for manipulating the map.
*/
#include "GridMap.h"
#include "Button.h"

#include <SFML/Graphics.hpp>

#include <wtypes.h>
#include <chrono>
#include <ctime>
#include <ratio>
#include <iostream>

sf::RenderWindow window(sf::VideoMode(1280, 720), "Map Generator", sf::Style::Close);  // The window where the UI of the program is drawn
GridMap grid_map = GridMap(sf::Vector2f(266, 24), sf::Vector2<int>(31, 21), sf::Vector2f(32, 32));  // The GridMap for the user to interact with
sf::Font font;
int seed = time(NULL) % RAND_MAX;

Button randomize;
Button generate;

sf::Text text;

bool redraw = true;
sf::RenderTexture gridTexture;

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
	
	// Set first seed
	grid_map.setSeed(seed);
	grid_map.generate();

	// Text / Font setup
	font.loadFromFile("fonts/Cave-Story.ttf");
	text.setFont(font);
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);

	gridTexture.create(window.getSize().x, window.getSize().y);

	randomize = Button(sf::Vector2f(16, 64), "Randomize", font);
	generate = Button(randomize.getPosition() + sf::Vector2f(0, 48), "Generate", font);
}

/* Draws the current grid to the screen */
void drawGrid() 
{
	gridTexture.clear();
	grid_map.draw(gridTexture);
}

void drawUI() {
	text.setPosition(sf::Vector2f(16, 16));
	text.setString("Seed: " + std::to_string(seed));
	window.draw(text);

	randomize.draw(window);
	generate.draw(window);
}

/* Called once every "game loop" */
void update() 
{
	if (redraw) {
		drawGrid();
		redraw = false;
	}

	sf::Sprite grid;
	grid.setTexture(gridTexture.getTexture());
	grid.setPosition(sf::Vector2f(0, 0));
	window.draw(grid);
	
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

			if (event.type == sf::Event::MouseButtonPressed) {
				if (randomize.isHovered()) {
					seed = rand();
					grid_map.setSeed(seed);
				}
				else if (generate.isHovered()) {
					window.clear();
					drawUI();
					window.display();
					grid_map.setSeed(seed);
					grid_map.generate();
					redraw = true;
				}
			}
        }

		window.clear();
		update();
		window.display();
    }
    return 0;
}
