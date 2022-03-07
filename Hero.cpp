//
// Created by Joe Geezer on 06/03/2022.
//

#include "Hero.h"


Hero::Hero(string name)
{
    _name = name;
    curr_x_pos = 30.f;
    curr_y_pos = 30.f;

    if (!texture.loadFromFile("assets/wizard-32px.png"))
    {
        cout << "error loading file" << endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(curr_x_pos, curr_y_pos);
};

void Hero::input_listener(sf::Event event)
{

    bool upFlag = false;
    bool downFlag = false;
    bool leftFlag = false;
    bool rightFlag = false;

    switch (event.key.code)
    {
        case sf::Keyboard::Up :     upFlag = true; break;
        case sf::Keyboard::Down:    downFlag = true; break;
        case sf::Keyboard::Left:    leftFlag = true; break;
        case sf::Keyboard::Right:   rightFlag = true; break;
        default : break;
    }

    if (leftFlag) curr_x_pos -= SPRITE_SPEED;
    if (rightFlag) curr_x_pos += SPRITE_SPEED;
    if (upFlag) curr_y_pos -= SPRITE_SPEED;
    if (downFlag) curr_y_pos += SPRITE_SPEED;

    sprite.setPosition(curr_x_pos, curr_y_pos);
};