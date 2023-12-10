#include "game.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

void Game::loadMap(const std::string& mapFile) {
    std::ifstream file(mapFile);

    if (!file.is_open()) {
        // Display an error message if the map file cannot be opened.
        std::cerr << "Error opening map file: " << mapFile << std::endl;
        return;
    }

    std::string line;
    bool readingCheckpoints = false; 

    while (std::getline(file, line)) {
        if (line.empty()) { 
            // Skip empty lines in the map file.
            continue;
        }


        if (line.find("[CHECKPOINTS]") != std::string::npos){ 
            // Start reading checkpoints when the [CHECKPOINTS] section is encountered.
            readingCheckpoints = true;
            continue;   
        }

        if (readingCheckpoints) { 
            // Parse checkpoint coordinates and add them to the map class.
            std::istringstream isstring(line);
            int x, y;
            char comma;
            while (isstring >> x >> comma >> y) {
                map.checkpoints.push(std::make_pair(x*32, y*32));
            }

        }
        else{
            // Parse map data and add it to the map.
            std::vector<int> row;
            std::istringstream isstring(line);

            std::string value;
            while (isstring >> value) {
                try {
                    int intValue = std::stoi(value);
                    row.push_back(intValue);
                } catch (const std::invalid_argument& e) {
                    // Display an error message if conversion fails.
                    std::cerr << "Error converting string to integer: " << value << std::endl;
                    return;
                }
            }

            map.mapData.push_back(row);
        }
    }
    file.close();

    // Load background images for the map.
    map.loadBackgrounds(backgroundImageFiles);
}



std::vector<Enemy*> Game::readEnemiesFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        // Return an empty vector if the enemy file cannot be opened.
        return enemies;
    }

    char enemyType;
    while (inputFile >> enemyType) {
        // Create enemies based on the specified type.
        enemies.push_back(this->createEnemy(enemyType));
    }

    inputFile.close();
    return enemies;
}

void Game::loadEnemies(int roundNumber) {
    // Clear existing enemies and towers
    enemies.clear();
    towers.clear();

    // Load enemies and towers for each round
    switch (roundNumber) {
        case 1:
            // Load enemies for round 1
            enemies = readEnemiesFromFile("game/default/enemy1.txt");
            break;

        case 2:
            // Load enemies for round 2
            enemies = readEnemiesFromFile("game/default/enemy1.txt");
            break;

        // Add more cases for additional rounds

        default:
            // Handle completion of all rounds (victory)
            // For now, let's close the window
            gamewindow.close();
            break;
    }
}