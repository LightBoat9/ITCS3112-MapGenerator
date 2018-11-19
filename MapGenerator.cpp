#include <SFML/Graphics.hpp>

#include <chrono>
#include <ctime>
#include <ratio>
#include <iostream>

using namespace std;

sf::Vector2<int> grid_size = sf::Vector2<int>(21, 21);  // Replace with grid's size later
sf::RenderWindow window(sf::VideoMode(1024, 576), "Map Generator");

// Testing variables
double timer = 0.0;
double interval = 1.0 / (grid_size.x * grid_size.y);
int speed = 3.0;
int visible_count = 0;

/* Runs once at program start */
void ready() {
    window.setPosition(sf::Vector2<int>(0, 0));
}

void draw_grid() {
    sf::Texture tex_wall;
    tex_wall.loadFromFile("tiles/wall.png");

    sf::Sprite spr_wall;
    spr_wall.setTexture(tex_wall);

    for (int i = 0; i < visible_count; i++) {
        spr_wall.setPosition(sf::Vector2f(16 + 16 * (i % grid_size.x), 16 + 16 * (i / grid_size.x)));
        window.draw(spr_wall);
    }
}

/* Called every game loop */
void update(double delta) {
    if (visible_count < grid_size.x * grid_size.y) {
        timer += delta;
        if (timer >= interval) {
            visible_count += speed;
            timer = 0.0;
        }
    }
    else {
        visible_count = grid_size.x * grid_size.y;
    }

    draw_grid();
}

int main()
{
    ready();
    chrono::high_resolution_clock::time_point last_time = chrono::high_resolution_clock::now();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        chrono::high_resolution_clock::time_point current_time = chrono::high_resolution_clock::now();
        update(chrono::duration_cast<chrono::duration<double>>(current_time - last_time).count());
        last_time = current_time;

        window.display();
    }
    return 0;
}
