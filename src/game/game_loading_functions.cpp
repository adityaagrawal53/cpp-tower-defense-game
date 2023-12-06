#include "game.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

void Game::loadMap(const std::string& mapFile) {
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
                map.checkpoints.push(std::make_pair(x, y));
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

            map.mapData.push_back(row);
        }
    }
    file.close();
}



std::vector<Enemy> Game::readEnemiesFromFile(const std::string& filename) {
    std::vector<Enemy> enemies;

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        return enemies;
    }

    std::string line;
    while (std::getline(inputFile, line)) { 
        enemies.emplace_back(this, line);
    }

    inputFile.close();
    return enemies;
}

void Game::loadEnemies(int roundNumber) {
    // Clear existing enemies and towers
    enemies.clear();
    towers.clear();

    // Example: Load enemies and towers for each round
    // Adjust the number, type, and difficulty of enemies as needed
    switch (roundNumber) {
        case 1:
            // Load enemies for round 1
            enemies = readEnemiesFromFile("default/enemy1.txt");
            break;

        case 2:
            // Load enemies for round 2
            enemies = readEnemiesFromFile("default/enemy2.txt");
            break;

        // Add more cases for additional rounds

        default:
            // Handle completion of all rounds (victory)
            // For now, let's close the window
            window.close();
            break;
    }
}
