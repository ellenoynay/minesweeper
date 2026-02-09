#include <iostream>
#include "Cell.hpp"

Cell::Cell(const sf::Vector2f &pos) : s_(pos) {
    std::cout << "Cell constructor called at " << pos.x << ", " << pos.y << ".\n";
}

void Cell::SetColour(sf::Color col) {
    s_.SetColour(col);
}

void Cell::Render(sf::RenderWindow &window) const {
    s_.Render(window);
}