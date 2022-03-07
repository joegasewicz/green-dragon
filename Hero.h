//
// Created by Joe Geezer on 06/03/2022.
//

#ifndef GREEN_DRAGON_HERO_H
#define GREEN_DRAGON_HERO_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#define SPRITE_SPEED 1

using namespace std;


class Hero {
public:

    sf::Texture texture;
    sf::Sprite sprite;
    float curr_x_pos;
    float curr_y_pos;

    explicit Hero(string name);

    void input_listener(sf::Event event);

private:
    string _name;
};


#endif //GREEN_DRAGON_HERO_H
