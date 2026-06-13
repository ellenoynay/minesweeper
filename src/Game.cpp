#include <iostream>
#include "Game.hpp"
#include "Cell.hpp"

Game::Game() : window(sf::VideoMode({480, 640}), "Minesweeper") {
    window.setFramerateLimit(60);
    cells.reserve(ROWS * COLS);
    int rows, cols;
    for (int i = 0; i < NUM_CELLS; i++) {
        rows = i / COLS;
        cols = i % COLS;
        cells.push_back(Cell({(float)cols * CELL_WIDTH + PADDING, (float)rows * CELL_WIDTH + PADDING}));
    }
}

void Game::setup() {
    std::cout << "Number of columns: " << cells.size() / COLS << std::endl;
    std::cout << "Number of rows: " << cells.size() / ROWS << std::endl;
    std::cout << "Number of cells: " << cells.size() << std::endl;
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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        int i = getCellIndex(mousePos);
        if (i != -1)
            cells.at(i).Reveal();
    }    
}

void Game::draw() {
    for (int i = 0; i < NUM_CELLS; i++)
        cells.at(i).Render(window);
}

int Game::getCellIndex(const sf::Vector2f& mousePos) const {
    int col = (int)((mousePos.x - PADDING) / CELL_WIDTH);
    int row = (int)((mousePos.y - PADDING) / CELL_WIDTH);
    if (col < 0 || col >= COLS || row < 0 || row >= ROWS) return -1;
    return row * COLS + col;
}