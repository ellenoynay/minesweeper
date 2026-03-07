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