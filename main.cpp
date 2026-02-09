#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "SFML");
    window.setFramerateLimit(60);


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

        window.display();
    }

    return 0;
}

// clang++ -std=c++17 main.cpp -o sfml-app \
//  -I/opt/homebrew/opt/sfml/include \
//  -L/opt/homebrew/opt/sfml/lib \
//  -lsfml-graphics -lsfml-window -lsfml-system