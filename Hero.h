//
// Created by Joe Geezer on 06/03/2022.
//

#ifndef GREEN_DRAGON_HERO_H
#define GREEN_DRAGON_HERO_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#define SPRITE_SPEED 2

using namespace std;


class Hero {
public:

    sf::Texture texture;
    sf::Sprite sprite;
    float curr_x_pos;
    float curr_y_pos;
    int rect_width;
    int rect_height;
    int window_width;
    int window_height;

    explicit Hero(string name, int window_width, int window_height);

    void update(sf::Event event, sf::RenderWindow *window, sf::Clock timer);

    float get_x_position() const;
    float get_y_position() const;

private:
    string _name;
};


#endif //GREEN_DRAGON_HERO_H
