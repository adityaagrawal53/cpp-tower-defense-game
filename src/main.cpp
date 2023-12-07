#include <iostream>

#include <list>
#include <iostream>
#include <math.h>           //Trigonometric functions
#include <queue>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#include "menu/menu.cpp"
#include "map/sidemenu.cpp"
#include "map/map.cpp"
#include "game/game.cpp"

#include "enemy/enemy.cpp"
#include "enemy/enemy-plant.cpp"
#include "enemy/enemy-tree.cpp"
#include "enemy/enemy-bomb.cpp"

#include "tower/tower.cpp"
#include "tower/tower-plant.hpp"

int main() {
    const int gridSize = 32;
    const int windowSize = gridSize * 16;

    sf::RenderWindow window(sf::VideoMode(windowSize + 200, windowSize), "Tower Defense Grid"); // Increased window width

    std::vector<std::string> backgroundFiles = {"map/default/background1.jpg", "map/default/background2.jpg", "map/default/background3.jpg"};
    int selectedBackgroundIndex = 1; // Change this index to select a different background

    GridMap grid(gridSize, windowSize, "map/default/map.txt", backgroundFiles, selectedBackgroundIndex);
    grid.loadMap("map/default/map.txt");

    SideMenu sideMenu(200, windowSize, 200);
    sideMenu.setPosition(sf::Vector2f(windowSize, 0)); // Set position next to the map

    while (window.isOpen()) {
        sf::Event event;
        
        window.clear();

        // Draw the grid
        grid.draw(window);

        // Draw the side menu
        sideMenu.draw(window);

        window.display();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                grid.handleMouseInput(event.mouseButton);
                sideMenu.handleMouseInput(event.mouseButton);
            }
        }
    }

    return 0;
}
