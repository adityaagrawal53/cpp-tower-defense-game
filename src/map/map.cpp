#include "map.hpp"
#include <fstream>
#include <iostream>

GridMap::GridMap(int gridSize, int windowSize, const std::string& mapFile, const std::vector<std::string>& backgroundImageFiles, int selectedBackgroundIndex)
    : gridSize(gridSize), windowSize(windowSize) {
    loadMap(mapFile);
    loadBackgrounds(backgroundImageFiles);

    if (selectedBackgroundIndex >= 0 && selectedBackgroundIndex < backgroundImageTextures.size()) {
        backgroundImage.setTexture(backgroundImageTextures[selectedBackgroundIndex]);
    } else {
        std::cerr << "Invalid selected background index. Defaulting to the first background." << std::endl;
        backgroundImage.setTexture(backgroundImageTextures[0]);
    }
}

void GridMap::loadMap(const std::string& mapFile) {
    std::ifstream file(mapFile);

    if (!file.is_open()) {
        std::cerr << "Error opening map file: " << mapFile << std::endl;
        return;
    }

    int value;
    while (file >> value) {
        std::vector<int> row;
        for (int i = 0; i < windowSize / gridSize; ++i) {
            row.push_back(value);
            if (!(file >> value)) {
                std::cerr << "Error reading map file: " << mapFile << std::endl;
                return;
            }
        }
        mapData.push_back(row);
    }

    file.close();
}

void GridMap::loadBackgrounds(const std::vector<std::string>& backgroundImageFiles) {
    for (const auto& file : backgroundImageFiles) {
        sf::Texture texture;
        if (texture.loadFromFile(file)) {
            backgroundImageTextures.push_back(texture);
        } else {
            std::cerr << "Error loading background image: " << file << std::endl;
        }
    }
}

void GridMap::draw(sf::RenderWindow& window) {
    // Draw the background
    window.draw(backgroundImage);

    // Draw the grid cells
    for (int i = 0; i < mapData.size(); ++i) {
        for (int j = 0; j < mapData[i].size(); ++j) {
            int imageIndex = mapData[i][j];
            if (imageIndex >= 0 && imageIndex < backgroundImageTextures.size()) {
                sf::Sprite cellSprite(backgroundImageTextures[imageIndex]);
                cellSprite.setPosition(j * gridSize, i * gridSize);
                window.draw(cellSprite);
            }
        }
    }
}

void GridMap::handleMouseInput(sf::Event::MouseButtonEvent& mouseEvent) {
    if (mouseEvent.button == sf::Mouse::Left) {
        int columnIndex = mouseEvent.x / gridSize;
        int rowIndex = mouseEvent.y / gridSize;

        // Check if the indices are within the valid range
        if (rowIndex >= 0 && rowIndex < mapData.size() && columnIndex >= 0 && columnIndex < mapData[0].size()) {
            // Change the value to represent a different image index
            // For example, set it to 2 for the third image in backgroundImageTextures
            mapData[rowIndex][columnIndex] = 2;
        }
    }
}