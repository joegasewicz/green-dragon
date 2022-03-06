#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window;
    sf::Texture wizard_texture;
    sf::Texture grass_texture;
    sf::Sprite wizard_sprite;
    sf::VertexArray quad(sf::Quads, 4);


    quad[0].position = sf::Vector2f(10.f, 10.f);
    quad[1].position = sf::Vector2f(110.f, 10.f);
    quad[2].position = sf::Vector2f(110.f, 110.f);
    quad[3].position = sf::Vector2f(10.f, 110.f);

    quad[0].texCoords = sf::Vector2f(0.f, 0.f);
    quad[1].texCoords = sf::Vector2f(25.f, 0.f);
    quad[2].texCoords = sf::Vector2f(25.f, 50.f);
    quad[3].texCoords = sf::Vector2f(0.f, 50.f);

    if (!grass_texture.loadFromFile("assets/grass-tile-128px.png")) {
        std::cout << "error lading file" << std::endl;
    }

    if (!wizard_texture.loadFromFile("assets/wizard-32px.png")) {
        std::cout << "error loading file" << std::endl;
    }
    wizard_sprite.setTexture(wizard_texture);
    wizard_sprite.setScale(2.f, 2.f);

    window.create(sf::VideoMode(800 * 2, 600 * 2), "Green Dragon");

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here
        window.draw(wizard_sprite);
        window.draw(quad, &grass_texture);
        // end the current frame
        window.display();
    }
    return 0;
}
