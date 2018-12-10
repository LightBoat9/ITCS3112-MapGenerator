#ifndef SLIDER_H
#define SLIDER_H

#include <algorithm>

#include "Widget.h"

template <class T>
class Slider : public Widget {
protected:
	sf::RectangleShape bar;
	sf::RectangleShape handle;

	sf::Vector2f bar_size;
	sf::Vector2f handle_size;

	bool dragging;
	T min;
	T max;
public:
	Slider() {};
	Slider(sf::Vector2f position, T min, T max, sf::Vector2f bar_size, sf::Vector2f handle_size) {
		// Initialize values
		this->position = position;
		this->min = min;
		this->max = max;
		this->bar_size = bar_size;
		this->handle_size = handle_size;
		// Bar setup
		this->bar.setSize(bar_size);
		this->bar.setPosition(position);
		this->bar.setFillColor(sf::Color::Blue);
		// Handle Setup
		this->handle.setSize(handle_size);
		this->handle.setPosition(position + sf::Vector2f(0, (bar.getSize().y - handle.getSize().y) / 2.f));
		this->handle.setFillColor(sf::Color::Cyan);
	}

	void setPosition(sf::Vector2f position) {
		this->position = position;
	}

	sf::Vector2f getPosition() {
		return position;
	}

	T getValue() {
		return (T)((((handle.getPosition().x - position.x) / (bar_size.x - handle_size.x)) * (max - min)) + min);
	}

	T getMin() {
		return min;
	}

	void setMin(T min) {
		this->min = min;
	}

	T getMax() {
		return max;
	}

	void setMax(T max) {
		this->max = max;
	}

	void draw(sf::RenderWindow & window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (this->handle.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
				dragging = true;
			}
			else if (!dragging && this->bar.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
				sf::Vector2f pos = handle.getPosition();
				pos.x = std::max(position.x, std::min((float)sf::Mouse::getPosition(window).x - (handle_size.x / 2), position.x + bar_size.x - handle_size.x));
				handle.setPosition(pos);
			}
		}

		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			dragging = false;
		}

		if (dragging) {
			sf::Vector2f pos = handle.getPosition();
			pos.x = std::max(position.x, std::min((float)sf::Mouse::getPosition(window).x - (handle_size.x / 2), position.x + bar_size.x - handle_size.x));
			handle.setPosition(pos);
		}
		window.draw(bar);
		window.draw(handle);
	}
};

typedef Slider<int> Slideri;
typedef Slider<float> Sliderf;

#endif