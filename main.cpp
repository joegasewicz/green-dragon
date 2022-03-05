#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window;
    sf::Texture wizard_texture;
    sf::Sprite wizard_sprite;

    if (!wizard_texture.loadFromFile("assets/wizard-32px.png"))
    {
        std::cout << "error loading file!" << std::endl;
    }
    wizard_sprite.setTexture(wizard_texture);
    wizard_sprite.setScale(2.f, 2.f);

    window.create(sf::VideoMode(800 * 2, 600 * 2), "Green Dragon");

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here
        // window.draw()
        window.draw(wizard_sprite);
        // end the current frame
        window.display();
    }
    return 0;
}
