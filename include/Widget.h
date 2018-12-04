#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Graphics.hpp>

class Widget {
protected:
	sf::Vector2f position;
public:
	virtual sf::Vector2f getPosition() = 0;
	virtual void setPosition(sf::Vector2f position) = 0;
	virtual void draw(sf::RenderWindow & window) = 0;
};

#endif