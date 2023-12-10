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
                std::cout << "x = " << x << " y = " << y << std::endl;
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



std::vector<Enemy*> Game::readEnemiesFromFile(const std::string& filename) {
    //std::vector<Enemy> enemies;

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "closed" << std::endl;
        return enemies;
    }

    char enemyType;
    while (inputFile >> enemyType) {
        //std::cout << "creating enemy: " << enemyType << std::endl;
        enemies.push_back(this->createEnemy(enemyType));
    }

    std::cout << "finished reading" << std::endl;
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
            enemies = readEnemiesFromFile("game/default/enemy1.txt");
            std::cout << "enemy size = " << enemies.size() << std::endl;
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