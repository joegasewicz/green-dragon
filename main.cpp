#include <iostream>
#include <SFML/Graphics.hpp>
#include "TileMap.h"


int main() {
    int screen_width = 512;
    int screen_height = 256;
    sf::RenderWindow window;
    sf::Texture wizard_texture;
    sf::Sprite wizard_sprite;
    TileMap map;

    const int level[] =
    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1,
      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    };


    if (!wizard_texture.loadFromFile("assets/wizard-32px.png")) {
        std::cout << "error loading file" << std::endl;
    }
    if (!map.load("assets/tilemap-32px-256px.png", sf::Vector2u(32, 32), level, 16, 8))
    {
        std::cout << "error loading level" << std::endl;
        return -1;
    }
    wizard_sprite.setTexture(wizard_texture);
//    wizard_sprite.setScale(2.f, 2.f);

    window.create(sf::VideoMode(screen_width, screen_height), "Green Dragon");
    window.setSize(sf::Vector2u(screen_width*3, screen_height*3));

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here
        window.draw(map);
        window.draw(wizard_sprite);

        // end the current frame
        window.display();
    }
    return 0;
}
