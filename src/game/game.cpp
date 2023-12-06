// Game.h

#include "game.hpp"

// Game.cpp


Game::Game(const GridMap& initialMap) : window(sf::VideoMode(800, 600), "Tower Defense Game"), map(initialMap) {
    // Initialize game variables
    playerScore = 0;
    currentWave = 1;
    playerMoney = 1000;

    // Initialize game elements
    initialize();
}

void Game::initialize() {
    // Load the first round
    loadWave(currentWave);
}

void Game::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
}

std::vector<Tower>& Game::getTowers() {
    return towers;
}

std::vector<Enemy>& Game::getEnemies() {
    return enemies;
}



void Game::update() {
    // Update game logic, enemy movement, tower attacks, etc.

    // Example: Update enemy positions
    for (auto& enemy : enemies) {
        enemy.move();
    }

    handleTowerEnemyInteractions();

    // Check if the round is completed
    if (enemies.empty()) {
        currentWave++;
        loadWave(currentWave);
    }

    // Check if the player has lost
    if (playerHealth <= 0) {
        // Handle game over (display message, reset game, etc.)
        // For now, let's just close the window
        window.close();
    }
}

void Game::render() {
    window.clear();

    // Render game elements
    map.draw(window);

    // Render enemies
    for (const auto& enemy : enemies) {
        // Example: Render enemy sprite at enemy.getXPos(), enemy.getYPos()
    }

    // Render towers
    for (const auto& tower : towers) {
        // Example: Render tower sprite at tower.getXPos(), tower.getYPos()
    }

    // Render UI elements (score, health, etc.)
    // Example: Render player score and health at the top of the window

    window.display();
}


int Game::getPlayerHealth() const {
    return playerHealth;
}

void Game::setPlayerHealth(int health) {
    playerHealth = health;
}

int Game::getPlayerScore() const {
    return playerScore;
}

void Game::setPlayerScore(int score) {
    playerScore = score;
}

int Game::getCurrentWave() const {
    return currentWave;
}

void Game::setCurrentWave(int wave) {
    currentWave = wave;
}

int Game::getPlayerMoney() const {
    return playerMoney;
}

void Game::setPlayerMoney(int money) {
    playerMoney = money;
}

GridMap Game::getMap() const { 
    return map;
}

void Game::loadEnemies(const std::string& enemyConfigFile) {
    std::ifstream enemyConfigStream(enemyConfigFile);
    if (!enemyConfigStream.is_open()) {
        // Handle file opening error
        return;
    }

    // Clear existing enemies
    enemies.clear();

    // Read enemy configurations
    int hp, attack, xp;
    float speed;
    double coin;
    while (enemyConfigStream >> hp >> speed >> attack >> xp) {
        // Create an enemy and add it to the vector
        enemies.push_back(Enemy(this, hp, speed, attack, xp, coin));
    }

    enemyConfigStream.close();
}

std::queue<std::pair<int,int>> Game::getCheckpoints() { 
    return this->getMap().checkpoints;
}