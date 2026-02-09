#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>

class Square {
    sf::RectangleShape s;

public:
    Square(const sf::Vector2f &pos);

    sf::Vector2f GetPosition() const;
    sf::Vector2f GetHalfSize() const;

    void SetColour(sf::Color col);

    void Render(sf::RenderWindow &window) const;
};

#endif