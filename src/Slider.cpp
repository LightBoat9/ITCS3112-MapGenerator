#include "Slider.h"
#include <iostream>

template <class T>
inline Slider<T>::Slider() {}

template <class T>
Slider<T>::Slider(sf::Vector2f position, T min, T max, sf::Vector2f bar_size, sf::Vector2f handle_size) {
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

/*
	Draw this slider to the window
*/
template <class T>
inline void Slider<T>::draw(sf::RenderWindow & window) {
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

template <class T>
inline T Slider<T>::getValue() {
	return ((((handle.getPosition().x - position.x) / (bar_size.x - handle_size.x)) * (max - min)) + min);
}

template <class T>
inline T Slider<T>::getMin() {
	return min;
}

template <class T>
inline T Slider<T>::getMax() {
	return max;
}