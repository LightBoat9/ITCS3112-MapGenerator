#include "Button.h"
#include "gtest/gtest.h"
#include "SFML/Graphics.hpp"

TEST(Button, Constructor) {
	sf::Font font;
	font.loadFromFile("fonts/Cave-Story.ttf");

	Button b = Button(sf::Vector2f(10, 15), "TestString", font);

	// Ensure the position is correctly set
	EXPECT_EQ(b.getPosition().x, 10);
	EXPECT_EQ(b.getPosition().y, 15);


}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}