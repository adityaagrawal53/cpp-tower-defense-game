#include <SFML/Graphics.hpp>
#include "menu.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Main Menu");

    MainMenu mainMenu(window);

    while (window.isOpen()) {
        int result = 0;

        // Main menu loop
        while (result == 0) {
            mainMenu.draw();
            result = mainMenu.handleInput();
        }

        // Process button press result
        if (result == 1) {
            // Start button pressed
            // Add code to start the game or transition to the next screen
            // For testing purposes, let's print a message
            std::cout << "Start button pressed!\n";
        } else if (result == 2) {
            // Quit button pressed
            window.close();
        }
    }

    return 0;
}
