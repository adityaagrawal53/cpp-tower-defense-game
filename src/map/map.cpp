#include "map.hpp"

GridMap::GridMap(int gridSize, int rows, int cols, const std::string& backgroundImageFile, const std::string& mapFile)
    : gridSize(gridSize), rows(rows), cols(cols) {
    
    // Load the background image
    if (backgroundImageTexture.loadFromFile(backgroundImageFile)) {
        backgroundImageSprite.setTexture(backgroundImageTexture);
    }

    // Initialize the grid and load the map from file
    grid.resize(rows, std::vector<bool>(cols, false));
    loadMapFromFile(mapFile);
}

void GridMap::loadMapFromFile(const std::string& mapFile) {
    std::ifstream file(mapFile);
    if (!file.is_open()) {
        // Handle file opening error
        return;
    }

//read through the text file line by line
//assuming the file has just 1s and 0s
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            if (file >> value) {
                grid[i][j] = (value == 1);
            } else {
                // Handle reading error
                return;
            }
        }
    }

    file.close();
}

void GridMap::draw(sf::RenderWindow& window) {
    // Draw the background image
    window.draw(backgroundImageSprite);

    // Draw the grid on top of the background
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sf::RectangleShape cell(sf::Vector2f(gridSize, gridSize));
            cell.setPosition(j * gridSize, i * gridSize);
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::Black);
            cell.setFillColor(grid[i][j] ? sf::Color::Green : sf::Color::White);
            window.draw(cell);
        }
    }
}

void GridMap::handleMouseInput(sf::Event& event) {
    //mouse can only interact with grids with value 1 (tower placing)
    if (event.type == sf::Event::MouseButtonPressed) {
        int x = event.mouseButton.x / gridSize;
        int y = event.mouseButton.y / gridSize;
        if (x >= 0 && x < cols && y >= 0 && y < rows && grid[y][x]) {
            grid[y][x] = !grid[y][x];
        }
    }
}