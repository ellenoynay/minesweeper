#include <iostream>
#include "Game.hpp"
#include "Cell.hpp"

Game::Game() : window(sf::VideoMode({480, 640}), "Minesweeper") {
    window.setFramerateLimit(60);
    // set up grid
    cells.reserve(ROWS * COLS);
    int rows, cols;
    for (int i = 0; i < NUM_CELLS; i++) {
        rows = i / COLS;
        cols = i % COLS;
        cells.push_back(Cell({(float)rows * CELL_WIDTH + PADDING, (float)cols * CELL_WIDTH + PADDING}));
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
    
    
    std::cout << "Number of columns: " << cells.size() / COLS << std::endl;
    std::cout << "Number of rows: " << cells.size() / ROWS << std::endl;
}

void Game::run() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }
        // Anything being changed can go from here [

        update();
        
        window.clear();

        // ] To here (before any renders)
        // Anything being rendered must go here

        draw();

        window.display();
    }
}

void Game::update() {
    // Testing reveal member function
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        for (int i = 0; i < NUM_CELLS; i++)
            cells.at(i).Reveal();
    }    
}

void Game::draw() {
    for (int i = 0; i < NUM_CELLS; i++)
        cells.at(i).Render(window);
}