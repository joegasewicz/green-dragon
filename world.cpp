//
// Created by Joe Geezer on 01/04/2022.
//

#include "world.h"

World::World(sf::View *view, int window_width, int window_height)
{
    _view = view;
    _window_width = window_width;
    _window_height = window_height;
    x_view_position = (float)_window_width/2;
    y_view_position = (float)_window_height/2;
    view->setCenter(sf::Vector2f((float)_window_width/2, (float)_window_height/2));
    view->setSize(sf::Vector2f((float)_window_width, (float)_window_height));
    view->setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    update_view_position();
}

void World::set_view_x_and_y(float x, float y)
{
    // TODO rename method
    x_view_position += x;
    y_view_position += y;
    std::cout << "x_view_position: " << x_view_position << std::endl;
    std::cout << "y_view_position: " << y_view_position << std::endl;
    update_view_position();
};

void World::update_view_position()
{
    _view->setCenter(sf::Vector2f(x_view_position, y_view_position));
}

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
    return _view;
};
