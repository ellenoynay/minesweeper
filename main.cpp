#include <SFML/Graphics.hpp>
#include <vector>
#include "Square.hpp"
#include "Cell.hpp"

// GLOBALS
const int ROWS = 20;
const int COLS = 20;


int main() {
    sf::RenderWindow window(sf::VideoMode({480, 640}), "Minesweeper");
    window.setFramerateLimit(60);

    std::vector<Cell> cells;

    // Test Cell
    Cell c({240, 320});
    cells.push_back(c);



    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }
        // Anything being changed can go from here *
        
        window.clear();

        // * To here (before any renders)
        // Anything being rendered must go here
        c.Render(window);

        window.display();
    }

    return 0;
}

// clang++ -std=c++17 Square.cpp Cell.cpp main.cpp -o builds/sfml-app \
//  -I/opt/homebrew/opt/sfml/include \
//  -L/opt/homebrew/opt/sfml/lib \
//  -lsfml-graphics -lsfml-window -lsfml-system