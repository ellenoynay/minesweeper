#include <iostream>
#include "Cell.hpp"

Cell::Cell(const sf::Vector2f &pos) : s_(pos), isBomb_(false), isRevealed_(false) {
    std::cout << "Cell constructor called at " << pos.x << ", " << pos.y << ".\n";
}

void Cell::SetColour(sf::Color col) {
    s_.SetColour(col);
}

void Cell::Reveal() {
    if (!isRevealed_) {
        SetColour(sf::Color(127, 127, 127, 255));
        isRevealed_ = true;
        std::cout << "Cell has been revealed.\n";
    }
}

void Cell::Render(sf::RenderWindow &window) const {
    s_.Render(window);
}