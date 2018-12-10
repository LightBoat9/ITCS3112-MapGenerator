/*
	Main driver for the MapGenerator project. Displays the map to the screen and allows user input for manipulating the map.
*/
#include "GridMap.h"
#include "Button.h"
#include "Slider.h"

#include <SFML/Graphics.hpp>

#include <wtypes.h>
#include <iostream>

// The window where the UI of the program is drawn
sf::RenderWindow window(sf::VideoMode(1280, 720), "Map Generator", sf::Style::Close);

// The GridMap for the user to interact with, and properties
GridMap grid_map = GridMap(sf::Vector2f(266, 24), sf::Vector2<int>(31, 21), sf::Vector2f(32, 32));
sf::RenderTexture gridTexture;
bool redraw_grid = true;

// Widgets
Button randomize;
Button generate;
Slideri room_attempts;
Slideri room_min;
Slideri room_max;
Slideri item_attempts;
Slideri enemy_attempts;

// Text stuff
sf::Font font;
sf::Text text;

/* Centers the window based on the users screen size */
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

	// Text - Font setup
	font.loadFromFile("fonts/Cave-Story.ttf");
	text.setFont(font);
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);

	// Initialize the grid texture to the size of the window
	gridTexture.create(window.getSize().x, window.getSize().y);

	// Button setup
	randomize = Button(sf::Vector2f(16, 64), "Randomize", font);
	generate = Button(randomize.getPosition() + sf::Vector2f(0, 48), "Generate", font);
	room_attempts = Slideri(generate.getPosition() + sf::Vector2f(0, 80), 0, 100, sf::Vector2f(15 * 16, 16), sf::Vector2f(24, 24));
	room_min = Slideri(room_attempts.getPosition() + sf::Vector2f(0, 80), 3, 7, sf::Vector2f(15 * 16, 16), sf::Vector2f(24, 24));
	room_max = Slideri(room_min.getPosition() + sf::Vector2f(0, 80), 7, 11, sf::Vector2f(15 * 16, 16), sf::Vector2f(24, 24));
	item_attempts = Slideri(room_max.getPosition() + sf::Vector2f(0, 80), 0, 20, sf::Vector2f(15 * 16, 16), sf::Vector2f(24, 24));
	enemy_attempts = Slideri(item_attempts.getPosition() + sf::Vector2f(0, 80), 0, 20, sf::Vector2f(15 * 16, 16), sf::Vector2f(24, 24));

	// Set first seed
	grid_map.setRoomAttempts(room_attempts.getValue());
	grid_map.setItemAttempts(item_attempts.getValue());
	grid_map.setEnemyAttempts(enemy_attempts.getValue());
	grid_map.generate();
}

/* Redraw the current GridMap to the gridTexture */
void drawGrid() 
{
	gridTexture.clear();
	grid_map.draw(gridTexture);
}

/* Draw the UI elements that must be updated every game loop */
void drawUI() {
	// Show seed
	text.setPosition(sf::Vector2f(16, 16));
	text.setString("Seed: " + std::to_string(grid_map.getSeed()));
	window.draw(text);

	// Show room attempts and slider
	text.setPosition(generate.getPosition() + sf::Vector2f(0, 36));
	grid_map.setRoomAttempts(room_attempts.getValue());
	text.setString("Room Attempts: " + std::to_string(room_attempts.getValue()));
	window.draw(text);

	// Show room size and sliders
	int odd_min = room_min.getValue() % 2 == 0 ? room_min.getValue() + 1 : room_min.getValue();
	int odd_max = room_max.getValue() % 2 == 0 ? room_max.getValue() + 1 : room_max.getValue();
	grid_map.setRoomSize(sf::Vector2i(odd_min, odd_max));

	// Room size text
	text.setPosition(room_attempts.getPosition() + sf::Vector2f(0, 36));
	text.setString("Room Min Size: " + std::to_string(odd_min));
	window.draw(text);
	text.setPosition(room_min.getPosition() + sf::Vector2f(0, 36));
	text.setString("Room Max Size: " + std::to_string(odd_max));
	window.draw(text);

	// Show item attempts and slider
	text.setPosition(room_max.getPosition() + sf::Vector2f(0, 36));
	grid_map.setItemAttempts(item_attempts.getValue());
	text.setString("Item Count: " + std::to_string(item_attempts.getValue()));
	window.draw(text);

	// Show enemy attempts and slider
	text.setPosition(item_attempts.getPosition() + sf::Vector2f(0, 36));
	grid_map.setEnemyAttempts(enemy_attempts.getValue());
	text.setString("Enemy Count: " + std::to_string(enemy_attempts.getValue()));
	window.draw(text);

	// Draw all widgets
	randomize.draw(window);
	generate.draw(window);
	room_attempts.draw(window);
	room_min.draw(window);
	room_max.draw(window);
	item_attempts.draw(window);
	enemy_attempts.draw(window);
}

/* Called once every game loop */
void update() 
{
	// Only redraw when a new map is generated
	if (redraw_grid) {
		drawGrid();
		redraw_grid = false;
	}

	// Draw the grid from its current texture
	sf::Sprite grid;
	gridTexture.display();
	grid.setTexture(gridTexture.getTexture());
	window.draw(grid);
	
	// Draw the ui elements every update
	drawUI();
}

int main()
{
	// Call ready function
    ready();

	// Handle Game Loop
    while (window.isOpen())
    {
		// Input
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Exit Condition
			if (event.type == sf::Event::Closed)
				window.close();

			// Mouse pressed button events
			if (event.type == sf::Event::MouseButtonPressed) {
				// Randomizes the seed
				if (randomize.isHovered()) {
					int seed = rand();
					grid_map.setSeed(seed);
				}
				// Generates a new map from the current seed and inputs
				else if (generate.isHovered()) {
					window.clear();
					drawUI();
					window.display();
					grid_map.setSeed(grid_map.getSeed());
					grid_map.generate();
					redraw_grid = true;
				}
			}
        }

		// Clear - redraw - display
		window.clear();
		update();
		window.display();
    }
    return 0;
}
