#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../enemy/enemy.hpp"
#include "../tower/tower.hpp"
#include "../map/map.hpp"
#include <fstream>
#include <queue>

class Game {
public:
    Game(const GridMap& initialMap);

    // Game initialization
    void initialize();

    // Main game loop
    void run();

    std::vector<Tower>& getTowers();
    std::vector<Enemy>& getEnemies();

    int getPlayerHealth() const;
    void setPlayerHealth(int health);

    int getPlayerScore() const;
    void setPlayerScore(int score);

    int getCurrentWave() const;
    void setCurrentWave(int wave);

    int getPlayerMoney() const;
    void setPlayerMoney(int money);

    GridMap getMap() const;
    std::queue<std::pair<int, int>> getCheckpoints();

    std::vector<Enemy> readEnemiesFromFile(const std::string& filename);

    std::vector<std::string>& backgroundImageFiles;

private:
    sf::RenderWindow window;
    GridMap map;

    sf::Clock clock;

    // Game variables
    int playerHealth;
    int playerScore;
    int currentWave;
    int playerMoney;
    std::vector<Enemy> enemies;
    std::vector<Tower> towers;
    sf::Clock run_clock;
    sf::Clock game_clock;
    sf::Clock update_clock;

    // Methods to handle game logic
    void handleInput();
    void update();
    void render();

    // Helper methods
    void loadMap(const std::string& mapConfigFile);

    void loadEnemies(int roundNumber);
    void handleTowerEnemyInteractions();
};
