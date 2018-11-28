#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button 
{
protected:
	sf::RectangleShape background;
	sf::Font font;
	sf::Text text;
	sf::Vector2f position;
	int padding = 16;
	bool hovered = false;
public:
	Button();
	Button(sf::Vector2f position, std::string text, sf::Font & font);
	void update();
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow & window);
	bool isHovered();
};

#endif