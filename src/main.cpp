#include <iostream>

#include <list>
#include <iostream>
#include <math.h>           //Trigonometric functions
#include <queue>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#include "menu/menu.cpp"
#include "map/map.cpp"
#include "game/game.cpp"

#include "enemy/enemy.cpp"
#include "enemy/enemy-bomb.cpp"
#include "enemy/enemy-plant.cpp"
#include "enemy/enemy-tree.cpp"

#include "tower/tower.cpp"

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
            std::cout << "Start button pressed!\n" << std::endl;
            std::vector<std::string> backgroundFiles = {"map/default/background1.jpg", "map/default/background2.jpg", "map/default/background3.jpg"};
            int selectedBackgroundIndex = 1; // Change this index to select a different background

            const int gridSize = 32;
            const int windowSize = gridSize * 16;

            GridMap grid(gridSize, windowSize, "map/default/map.txt", backgroundFiles, selectedBackgroundIndex);

            grid.loadMap("map/default/map.txt");
            std::cout << "does this work?" << std::endl;
            Game game(grid);
        } else if (result == 2) {
            // Quit button pressed
            window.close();
        }
    }

    return 0;
}
