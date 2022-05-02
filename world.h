//
// Created by Joe Geezer on 01/04/2022.
//

#ifndef GREEN_DRAGON_WORLD_H
#define GREEN_DRAGON_WORLD_H

#include <string>
#include <SFML/Graphics.hpp>


class World {
public:
    int window_width;
    int window_height;
    float x_view_position;
    float y_view_position;

    explicit World(sf::View *view, int window_width, int window_height);

    sf::View *update_view(sf::Event event);

    void set_view_x_and_y(float x, float y);
private:
    sf::View *_view;
};


#endif //GREEN_DRAGON_WORLD_H
