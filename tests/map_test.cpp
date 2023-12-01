#include <SFML/Graphics.hpp>
#include "map/map.cpp"

int main() {
    const int gridSize = 32;
    const int windowSize = gridSize * 16;

    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Tower Defense Grid");

    std::vector<std::string> backgroundFiles = {"map/default/background1.jpg", "map/default/background2.jpg", "map/default/background3.jpg"};
    int selectedBackgroundIndex = 1; // Change this index to select a different background

    GridMap grid(gridSize, windowSize, "map/default/map.txt", backgroundFiles, selectedBackgroundIndex);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                grid.handleMouseInput(event.mouseButton);
            }
        }

        window.clear();

        // Draw the grid
        grid.draw(window);

        window.display();
    }

    return 0;
}
