#include "map.hpp"

GridMap::GridMap(int gridSize, int rows, int cols, const std::vector<std::string>& backgroundImageFiles, const std::string& mapFile, const std::vector<std::string>& towerImageFiles)
    : gridSize(gridSize), rows(rows), cols(cols) {
    
    // Load the background images
    for (const auto& backgroundImageFile : backgroundImageFiles) {
        sf::Texture backgroundTexture;
        if (backgroundTexture.loadFromFile(backgroundImageFile)) {
            backgroundTextures.push_back(backgroundTexture);
        }
    }

    // Load the tower images
    for (const auto& towerImageFile : towerImageFiles) {
        sf::Texture towerTexture;
        if (towerTexture.loadFromFile(towerImageFile)) {
            towerTextures.push_back(towerTexture);
        }
    }

    // Initialize the grid and load the map from file
    grid.resize(rows, std::vector<bool>(cols, false));
    loadMapFromFile(mapFile);
    updateBackgroundImage();
}

void GridMap::loadMapFromFile(const std::string& mapFile) {
    std::ifstream file(mapFile);
    if (!file.is_open()) {
        // Handle file opening error
        return;
    }

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

void GridMap::updateGridImage(int x, int y) {
    // Cycle through tower images
    static size_t currentTowerIndex = 0;
    currentTowerIndex = (currentTowerIndex + 1) % towerTextures.size();

    // Set the current tower image
    towerSprite.setTexture(towerTextures[currentTowerIndex]);
    towerSprite.setScale(static_cast<float>(gridSize) / towerTextures[currentTowerIndex].getSize().x,
                        static_cast<float>(gridSize) / towerTextures[currentTowerIndex].getSize().y);

    // Update the grid value (optional)
    grid[y][x] = !grid[y][x];
}

void GridMap::updateBackgroundImage() {
    // Cycle through background images
    static size_t currentBackgroundIndex = 0;
    currentBackgroundIndex = (currentBackgroundIndex + 1) % backgroundTextures.size();

    // Set the current background image
    backgroundImageSprite.setTexture(backgroundTextures[currentBackgroundIndex]);
    backgroundImageSprite.setScale(static_cast<float>(gridSize * cols) / backgroundTextures[currentBackgroundIndex].getSize().x,
                                   static_cast<float>(gridSize * rows) / backgroundTextures[currentBackgroundIndex].getSize().y);
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

            // Draw the tower image on top of selected grid cells
            if (grid[i][j]) {
                towerSprite.setPosition(j * gridSize, i * gridSize);
                window.draw(towerSprite);
            }
        }
    }
}

void GridMap::handleMouseInput(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        int x = event.mouseButton.x / gridSize;
        int y = event.mouseButton.y / gridSize;
        if (x >= 0 && x < cols && y >= 0 && y < rows && grid[y][x]) {
            updateGridImage(x, y);
        }
    }
}
