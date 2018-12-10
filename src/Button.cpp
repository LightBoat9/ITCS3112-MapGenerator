#include "Button.h"

/*
	Invalid Default Constructor
*/
Button::Button() {}

/*
	Constructor

	@param position The position relative to the window of the button
	@param text the string inside the button
	@font the font the string uses
*/
Button::Button(sf::Vector2f position, std::string text, sf::Font & font) {
	this->position = position;
	this->text.setFont(font);
	this->text.setString(text);
	update();
}

void Button::update() {
	this->text.setCharacterSize(text_size);
	this->text.setFillColor(sf::Color::White);
	this->background.setFillColor(sf::Color::Blue);

	sf::FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.f);
	this->background.setSize(sf::Vector2f(textRect.width + padding, textRect.height + padding));

	this->background.setPosition(position);
	this->text.setPosition(this->background.getPosition() + sf::Vector2f(this->background.getSize().x / 2.f, this->background.getSize().y / 2.f));
}

/*
	@return hovered true if the mouse is inside this button
*/
bool Button::isHovered() {
	return hovered;
}

/*
	Set the position of this button, the position is relative to the window

	@param position the new position relative to the window for the button
*/
void Button::setPosition(sf::Vector2f position) {
	this->position = position;
	update();
}

/*
	@return position the position of this button relative to the window
*/
sf::Vector2f Button::getPosition() {
	return position;
}

/*
	@return padding the extra space added to all sides of the button
*/
int Button::getPadding() {
	return padding;
}

/*
	@return the text displayed on this button
*/
std::string Button::getText() {
	return text.getString();
}


/*
	Set the padding of the button, the extra space added to all sides of the button
	
	@param padding the new padding
*/
void Button::setPadding(int padding) {
	this->padding = padding;
	update();
}

/*
	Draw this button to the window and set hovered
*/
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