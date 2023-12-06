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

    map.loadBackgrounds(backgroundImageFiles);
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