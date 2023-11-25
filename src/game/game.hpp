// Game.h
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../enemy/enemy.hpp"
#include "../tower/tower.hpp"
#include "../map/map.hpp"

#include <fstream>

class Game {
public:
    Game();

    // Game initialization
    void initialize();

    // Main game loop
    void run();

    const std::vector<Tower>& getTowers() const;
    const std::vector<Enemy>& getEnemies() const;

    int getPlayerHealth() const;
    void setPlayerHealth(int health);

    int getPlayerScore() const;
    void setPlayerScore(int score);

    int getCurrentWave() const;
    void setCurrentWave(int wave);

    int getPlayerMoney() const;
    void setPlayerMoney(int money);

private:
    sf::RenderWindow window;
    GridMap map;
    std::vector<Enemy> enemies;
    std::vector<Tower> towers;
    sf::Clock clock;

    // Game variables
    int playerHealth;
    int playerScore;
    int currentWave;
    int playerMoney;

    


    // Methods to handle game logic
    void handleInput();
    void update();
    void render();

    // Helper methods
    void loadWave(int waveNumber);
    void loadMap(const std::string& mapConfigFile);
    void loadEnemies(const std::string& enemyConfigFile);

    void handleTowerEnemyInteractions();
};
