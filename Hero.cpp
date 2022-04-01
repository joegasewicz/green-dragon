//
// Created by Joe Geezer on 06/03/2022.
//

#include "Hero.h"


Hero::Hero(string name) {
    _name = name;
    curr_x_pos = 30.f;
    curr_y_pos = 30.f;

    if (!texture.loadFromFile("assets/hero-tiles.png"))
    {
        cout << "error loading file" << endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(curr_x_pos, curr_y_pos);
    sprite.setTextureRect(sf::IntRect(0,0, 32, 32));
};

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