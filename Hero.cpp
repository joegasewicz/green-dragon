//
// Created by Joe Geezer on 06/03/2022.
//

#include "Hero.h"


Hero::Hero(string name) {
    _name = name;
    curr_x_pos = 30.f;
    curr_y_pos = 30.f;

    if (!texture.loadFromFile("assets/wizard-32px.png")) {
        cout << "error loading file" << endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(curr_x_pos, curr_y_pos);
};

void Hero::update(sf::Event event, sf::RenderWindow *window, sf::Clock timer) {
    double delta_time = timer.getElapsedTime().asSeconds();
    float delta = timer.restart().asSeconds();
    float speed = 5.f;
    if (sf::Keyboard::Up == event.key.code)
    {
        sprite.move(0.f, -speed);
    }
    if (sf::Keyboard::Down == event.key.code)
    {
        sprite.move(0.f, speed);
    }
    if (sf::Keyboard::Left == event.key.code)
    {
        sprite.move(-speed, 0.f);
    }
    if (sf::Keyboard::Right == event.key.code)
    {
        sprite.move(speed, 0.f);
    }

};