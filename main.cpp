#include <iostream>
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Hero.h"
#include "world.h"


int main() {
    int screen_width = 512;
    int screen_height = 256;
    sf::RenderWindow window;
    sf::Clock timer;
    sf::View view_one;

    TileMap map;
    Hero hero = Hero{"Thor"};
    World world = World{&view_one, screen_width, screen_height};


    const int level[] =
    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 1, 1, 1, 1, 5, 5, 5, 1, 1, 1, 1,1, 1, 1, 1,
      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 7, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    };


    if (!map.load("assets/tilemap-32px-256px.png", sf::Vector2u(32, 32), level, 16, 8))
    {
        std::cout << "error loading level" << std::endl;
        return -1;
    }

    window.create(sf::VideoMode(screen_width, screen_height), "Green Dragon");
    window.setSize(sf::Vector2u(screen_width*3, screen_height*3));
    // Setup view
//    view_one.setViewport(sf::FloatRect(0.25f, 0.25f, 0.5f, 0.5f));
//    window.setView(view_one);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        // Clear window
        window.clear(sf::Color::Black);

        // Hero
        hero.update(event, &window, timer);

        // View
        sf::View *current_view = world.update_view(event);
        window.setView(*current_view);

        // Draw to window
        window.draw(map);
        window.draw(hero.sprite);

        // end the current frame
        window.display();
    }
    return 0;
}
