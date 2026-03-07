#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Square.hpp"
#include "Cell.hpp"

int main() {
    Game game;

    game.setup();
    game.run();

    return 0;
}

// clang++ -std=c++17 Square.cpp Cell.cpp main.cpp -o builds/sfml-app \
//  -I/opt/homebrew/opt/sfml/include \
//  -L/opt/homebrew/opt/sfml/lib \
//  -lsfml-graphics -lsfml-window -lsfml-system