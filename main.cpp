#include <iostream>
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Hero.h"
#include "world.h"

#define WORLD_ROW_TOTAL 9
#define WORLD_COLUMN_TOTAL 16

const int screen_width = 512;
const int screen_height = 256;

int main() {
    sf::RenderWindow window;
    sf::Clock timer;
    sf::View view_one;
    TileMap map;
    Hero hero = Hero{"Thor", screen_width, screen_height};
    World world = World{&view_one, screen_width, screen_height};
    const int level[] =
    {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 1, 1, 1, 1, 5, 5, 5, 1, 1, 1, 1,1, 1, 1, 1,
      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 7, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    };
    // Tile maps
    if (!map.load("assets/tilemap-32px-256px.png",
                  sf::Vector2u(32, 32), level, WORLD_COLUMN_TOTAL, WORLD_ROW_TOTAL))
    {
        std::cout << "error loading level" << std::endl;
        return -1;
    }
    // Window
    window.create(sf::VideoMode(screen_width, screen_height), "Green Dragon");
    window.setSize(sf::Vector2u(screen_width*3, screen_height*3));
    // Game loop
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        // Clear window
        window.clear(sf::Color::Black);

        // View
        sf::View *current_view = world.update_view(event);
        window.setView(*current_view);
        // Hero
        hero.update(event, &window, timer);
        // Draw to window
        window.draw(map);
        window.draw(hero.sprite);
        // end the current frame
        window.display();
    }
    return 0;
}
