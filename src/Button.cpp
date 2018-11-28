#include "Button.h"

Button::Button() {}

Button::Button(sf::Vector2f position, std::string text, sf::Font & font) {
	this->position = position;
	this->text.setFont(font);
	this->text.setCharacterSize(32);
	this->text.setFillColor(sf::Color::White);
	this->background.setFillColor(sf::Color::Blue);
	this->text.setString(text);

	sf::FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.f);
	this->background.setSize(sf::Vector2f(textRect.width + padding, textRect.height + padding));

	this->background.setPosition(position);
	this->text.setPosition(this->background.getPosition() + sf::Vector2f(this->background.getSize().x / 2.f, this->background.getSize().y / 2.f));
}

bool Button::isHovered() {
	return hovered;
}

void Button::draw(sf::RenderWindow & window) {
	hovered = background.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)));
	if (hovered) {
		background.setFillColor(sf::Color::Cyan);
		text.setFillColor(sf::Color::Black);
	}
	else {
		background.setFillColor(sf::Color::Blue);
		text.setFillColor(sf::Color::White);
	}
	window.draw(background);
	window.draw(text);
}

sf::Vector2f Button::getPosition() {
	return position;
}