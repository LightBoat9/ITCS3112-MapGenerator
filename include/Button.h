#ifndef BUTTON_H
#define BUTTON_H

#include <string>

#include "Widget.h"

class Button : public Widget {
protected:
	sf::RectangleShape background;
	sf::Font font;
	sf::Text text;
	int text_size = 32;
	int padding = 16;
	bool hovered = false;
	void update();
public:
	Button();
	Button(sf::Vector2f position, std::string text, sf::Font & font);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);
	bool isHovered();
	int getPadding();
	void setPadding(int padding);
	std::string getText();
	void draw(sf::RenderWindow & window);
};

#endif