#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.hpp"

class Game {
public:
    static inline constexpr int ROWS = 22;
    static inline constexpr int COLS = 22;
    static inline constexpr int NUM_CELLS = ROWS * COLS;
    static inline constexpr int CELL_WIDTH = 20;
    static inline constexpr int PADDING = 0;

    Game();

    void setup();
    void run();
    void update();
    void draw();
    
private:
   sf::RenderWindow window;
   std::vector<Cell> cells;
};

#endif