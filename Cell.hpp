#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include "Square.hpp"

class Cell {
public:
    Cell(const sf::Vector2f &pos);

    void SetColour(sf::Color col);
    void Render(sf::RenderWindow &window) const;
private:
    Square s_;
    bool isBomb_ = true;
    bool isRevealed_ = false;
};

#endif