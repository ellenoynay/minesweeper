#include <iostream>
#include "Game.hpp"
#include "Cell.hpp"

Game::Game() : window(sf::VideoMode({480, 640}), "Minesweeper") {
    window.setFramerateLimit(60);
    // set up grid
    for (int i = 1; i <= COLS; i++) {
        std::vector<Cell> col;
        for (int j = 1; j <= ROWS; j++) {
            Cell c({(float)i * CELL_WIDTH, (float)j * CELL_WIDTH});
            col.push_back(c);
        }
        cells.push_back(col);
    }
}

void Game::setup() {
    // GLOBALS
    // const int ROWS = 22;
    // const int COLS = 22;
    // const int WIDTH = 20;

    // sf::Vector2f getGridIndex(const sf::Vector2f &mousePos) {
    //     int row;
    //     int col;
    // }

    // Vector of cells is within header

    // Test Cell (in constructor)
    
    
    std::cout << cells.size() << std::endl;
    std::cout << cells[0].size() << std::endl;
}

void Game::run() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }
        // Anything being changed can go from here *

        update();
        
        window.clear();

        // * To here (before any renders)
        // Anything being rendered must go here

        draw();

        window.display();
    }
}

void Game::update() {
    // Testing reveal member function
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        for (int i = 0; i < COLS; i++) {
            for (int j = 0; j < ROWS; j++) {
                cells[i][j].Reveal();
            }
        }
    }    
}

void Game::draw() {
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            cells[i][j].Render(window);
        }
    }
}