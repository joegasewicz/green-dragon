//
// Created by Joe Geezer on 01/04/2022.
//

#include "world.h"

World::World(sf::View *view, int window_width, int window_height)
{
    _view = view;
    view->setCenter(sf::Vector2f(x_view_position, y_view_position));
    view->setSize(sf::Vector2f((float)window_width, (float)window_height));
    view->setViewport(sf::FloatRect(1.f, 1.f, 1.f, 1.f));
}

void World::set_view_x_and_y(float x, float y)
{
    x_view_position += x;
    y_view_position += y;
};

sf::View *World::update_view(sf::Event event)
{
    float speed = 5.f;
    if (sf::Keyboard::Up == event.key.code)
    {
        set_view_x_and_y(0.f, -speed);
    }
    if (sf::Keyboard::Down == event.key.code)
    {
        set_view_x_and_y(0.f, speed);
    }
    if (sf::Keyboard::Left == event.key.code)
    {
        set_view_x_and_y(-speed, 0.f);
    }
    if (sf::Keyboard::Right == event.key.code)
    {
        set_view_x_and_y(speed, 0.f);
    }
    _view->setCenter(sf::Vector2f(x_view_position, y_view_position));
    return _view;
};