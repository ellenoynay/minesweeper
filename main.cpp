#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Square.hpp"
#include "Cell.hpp"

// GLOBALS
const int ROWS = 22;
const int COLS = 22;
const int WIDTH = 20;

sf::Vector2f getGridIndex(const sf::Vector2f &mousePos) {
    int row;
    int col;
}


int main() {
    sf::RenderWindow window(sf::VideoMode({480, 640}), "Minesweeper");
    window.setFramerateLimit(60);

    std::vector<std::vector<Cell>> cells;

    // Test Cell
    for (int i = 1; i <= COLS; i++) {
        std::vector<Cell> col;
        for (int j = 1; j <= ROWS; j++) {
            Cell c({(float)i * WIDTH, (float)j * WIDTH});
            col.push_back(c);
        }
        cells.push_back(col);
    }
    
    std::cout << cells.size() << std::endl;
    std::cout << cells[0].size() << std::endl;




    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }
        // Anything being changed can go from here *

        // Testing reveal member function
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            for (int i = 0; i < COLS; i++) {
                for (int j = 0; j < ROWS; j++) {
                    cells[i][j].Reveal();
                }
            }
        }
        
        window.clear();

        // * To here (before any renders)
        // Anything being rendered must go here
        for (int i = 0; i < COLS; i++) {
            for (int j = 0; j < ROWS; j++) {
                cells[i][j].Render(window);
            }
        }

        window.display();
    }

    return 0;
}

// clang++ -std=c++17 Square.cpp Cell.cpp main.cpp -o builds/sfml-app \
//  -I/opt/homebrew/opt/sfml/include \
//  -L/opt/homebrew/opt/sfml/lib \
//  -lsfml-graphics -lsfml-window -lsfml-system