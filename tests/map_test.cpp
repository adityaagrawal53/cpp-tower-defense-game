#include <SFML/Graphics.hpp>
#include "map/map.cpp"
#include "map/sidemenu.hpp"

int main() {
    const int gridSize = 32;
    const int windowSize = gridSize * 16;

    sf::RenderWindow window(sf::VideoMode(windowSize + 200, windowSize), "Tower Defense Grid"); // Increased window width

    std::vector<std::string> backgroundFiles = {"map/default/background1.jpg", "map/default/background2.png", "map/default/background3.jpg"};
    int selectedBackgroundIndex = 1; // Change this index to select a different background

    GridMap grid(gridSize, windowSize, "map/default/map.txt", backgroundFiles, selectedBackgroundIndex);
    grid.loadMap("map/default/map.txt");

    

    SideMenu sideMenu(200, windowSize, 200);
    sideMenu.setPosition(sf::Vector2f(windowSize, 0)); // Set position next to the map
    sideMenu.buttonTexture.loadFromFile("map/default/sidemenu.png");
    
    sideMenu.button.setScale(0.5f, 0.5f);

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
