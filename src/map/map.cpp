#include "map.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

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

    std::string line;
    bool readingCheckpoints = false; 

    while (std::getline(file, line)) {
        if (line.empty()) { 
            continue;
        }


        if (line.find("[CHECKPOINTS]") != std::string::npos){ 
            readingCheckpoints = true;
            continue;   
        }

        if (readingCheckpoints) { 
            std::istringstream isstring(line);
            int x, y;
            char comma;
            while (isstring >> x >> comma >> y) {
                checkpoints.push(std::make_pair(x, y));
            }

        }
        else{
            std::vector<int> row;
            std::istringstream isstring(line);

            std::string value;
            while (isstring >> value) {
                try {
                    int intValue = std::stoi(value);
                    row.push_back(intValue);
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error converting string to integer: " << value << std::endl;
                    return;
                }
            }

            mapData.push_back(row);
        }
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
            // Check if the value is 1 before updating
            if (mapData[rowIndex][columnIndex] == 1 || mapData[rowIndex][columnIndex] == 0) {
                // Change the value to represent a different image index
                // For example, set it to 2 for the third image in backgroundImageTextures
                mapData[rowIndex][columnIndex] = 2;
                sf::Sprite cellS(backgroundImageTextures[mapData[rowIndex][columnIndex]]);
                cellS.setPosition(rowIndex*gridSize, columnIndex*gridSize);
                sf::RenderWindow window;
                window.draw(cellS);
            }
        }
    }
}

void GridMap::setPosition(sf::Vector2f position) {
    backgroundImage.setPosition(position);
}
