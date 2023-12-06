#include <list>
#include <iostream>
#include <math.h>           //Trigonometric functions
#include <queue>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "enemy/enemy.cpp"
#include "game/game.cpp"
#include "tower/tower.cpp"

int main() {
    const int gridSize = 32;
    const int windowSize = gridSize * 16;

    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Tower Defense Grid");

    std::vector<std::string> backgroundFiles = {"map/default/background1.jpg", "map/default/background2.jpg", "map/default/background3.jpg"};
    int selectedBackgroundIndex = 1; // Change this index to select a different background

    GridMap grid(gridSize, windowSize, "map/default/map.txt", backgroundFiles, selectedBackgroundIndex);

    grid.loadMap("map/default/map.txt");

    // Assuming you have a Game instance named 'gameInstance'
    Game* gamePtr = &Game(grid);

    // Replace "enemy_data.txt" with the actual filename you want to test
    std::vector<Enemy> enemies = readEnemiesFromFile(gamePtr, "tests/enemies.txt");

    // Print information about each enemy
    for (const auto& enemy : enemies) {
        std::cout << "Enemy Type: ";

        // Use dynamic_cast to check the actual type of the enemy
        if (const PlantEnemy* plantEnemy = dynamic_cast<const PlantEnemy*>(&enemy)) {
            std::cout << "PlantEnemy";
            // Access specific attributes or methods of PlantEnemy
        } else if (const BombEnemy* bombEnemy = dynamic_cast<const BombEnemy*>(&enemy)) {
            std::cout << "BombEnemy";
            // Access specific attributes or methods of BombEnemy
        } else if (const TreeEnemy* treeEnemy = dynamic_cast<const TreeEnemy*>(&enemy)) {
            std::cout << "TreeEnemy";
            // Access specific attributes or methods of TreeEnemy
        } else {
            std::cout << "Unknown Enemy Type";
        }

        std::cout << std::endl;
    }

    return 0;
}