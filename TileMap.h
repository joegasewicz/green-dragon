//
// Created by Joe Geezer on 05/03/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef GREEN_DRAGON_TILEMAP_H
#define GREEN_DRAGON_TILEMAP_H

class TileMap :  public sf::Drawable, public sf::Transformable
{
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply transforms
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};


#endif //GREEN_DRAGON_TILEMAP_H
