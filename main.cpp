#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    int screen_width = 512;
    int screen_height = 256;
    sf::RenderWindow window;
    sf::Texture wizard_texture;
    sf::Texture grass_texture;
    sf::Sprite wizard_sprite;
    sf::VertexArray quad(sf::Quads, 4);
    sf::VertexArray quad2(sf::Quads, 4);



    quad[0].position = sf::Vector2f(0.f, 0.f);
    quad[1].position = sf::Vector2f(32.f, 0.f);
    quad[2].position = sf::Vector2f(32.f, 32.f);
    quad[3].position = sf::Vector2f(0.f, 32.f);

    quad[0].texCoords = sf::Vector2f(32.f, 0.f);
    quad[1].texCoords = sf::Vector2f(64.f, 0.f);
    quad[2].texCoords = sf::Vector2f(64.f, 32.f);
    quad[3].texCoords = sf::Vector2f(32.f, 32.f);

    // ===============================================

    quad2[0].position = sf::Vector2f(32.f, 0.f);
    quad2[1].position = sf::Vector2f(64.f, 0.f);
    quad2[2].position = sf::Vector2f(64.f, 32.f);
    quad2[3].position = sf::Vector2f(32.f, 32.f);

    quad2[0].texCoords = sf::Vector2f(64.f, 0.f);
    quad2[1].texCoords = sf::Vector2f(96.f, 0.f);
    quad2[2].texCoords = sf::Vector2f(96.f, 32.f);
    quad2[3].texCoords = sf::Vector2f(64.f, 32.f);




    if (!grass_texture.loadFromFile("assets/tilemap-32px-128px.png")) {
        std::cout << "error lading file" << std::endl;
    }

    if (!wizard_texture.loadFromFile("assets/wizard-32px.png")) {
        std::cout << "error loading file" << std::endl;
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
        window.draw(wizard_sprite);

        window.draw(quad, &grass_texture);
        window.draw(quad2, &grass_texture);

        // end the current frame
        window.display();
    }
    return 0;
}
