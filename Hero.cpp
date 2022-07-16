//
// Created by Joe Geezer on 06/03/2022.
//

#include "Hero.h"


Hero::Hero(string name, int _window_width, int _window_height) {
    _name = name;
    window_width = _window_width;
    window_height = _window_height;
    rect_width = 32.f;
    rect_height = 32.f;
    curr_x_pos = get_x_position();
    curr_y_pos = get_y_position();

    if (!texture.loadFromFile("assets/hero-tiles.png"))
    {
        cout << "error loading file" << endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(curr_x_pos, curr_y_pos);
    sprite.setTextureRect(sf::IntRect(0,0, rect_width, rect_height));
};

// TODO remove window & timer args
void Hero::update(sf::Event event, sf::RenderWindow *window, sf::Clock timer) {
    float speed = 5.f;
    if (sf::Keyboard::Up == event.key.code)
    {
        sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        sprite.move(0.f, -speed);
    }
    if (sf::Keyboard::Down == event.key.code)
    {
        sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
        sprite.move(0.f, speed);
    }
    if (sf::Keyboard::Left == event.key.code)
    {
        sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
        sprite.move(-speed, 0.f);
    }
    if (sf::Keyboard::Right == event.key.code)
    {
        sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
        sprite.move(speed, 0.f);
    }

};

float Hero::get_x_position() const
{
    int rect = rect_height / 2;
    int x_pos = window_width / 2 - rect;
    return (float)x_pos;
}

float Hero::get_y_position() const
{
    int rect = rect_height / 2;
    int y_pos = window_height / 2 - rect;
    return (float)y_pos;
}
