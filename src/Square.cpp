#include <iostream>
#include "Square.hpp"

Square::Square(const sf::Vector2f &pos) {
    s.setSize(sf::Vector2f(20, 20));
    s.setPosition(pos);
    s.setFillColor(sf::Color(175, 175, 175, 255));
    s.setOutlineColor(sf::Color::Red);
    s.setOutlineThickness(1.0);
    std::cout << "Square constructor called at " << pos.x << ", " << pos.y << ".\n";
}

sf::Vector2f Square::GetPosition() const {
    return s.getPosition();
}

sf::Vector2f Square::GetHalfSize() const {
    return s.getSize() / 2.0f;
}

void Square::SetColour(sf::Color col) {
    s.setFillColor(col);
}

void Square::Render(sf::RenderWindow &window) const {
    window.draw(s);
}