// Game.h

#include "game.hpp"

// Game.cpp


Game::Game(const GridMap& initialMap) : window(sf::VideoMode(800, 600), "Tower Defense Game"), map(initialMap) {
    // Initialize game variables
    playerScore = 0;
    currentWave = 1;
    playerMoney = 1000;

    // Initialize game elements
    loadWave(currentWave);
}

void Game::loadWave(int roundNumber) { 
    loadEnemies(roundNumber);
    //loadTowers(roundNumber);
    //loadMap (??)
}


void Game::run(){
    
    while (window.isOpen()) {
        handleInput();
        if (run_clock.getElapsedTime().asSeconds() >= 1.0) {
            update();
            render();

            run_clock.restart();
        }
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

    update_clock.restart();
}

void Game::render() {
    window.clear();

    // Render game elements
    map.draw(window);

    // Render enemies
    for (auto& enemy : enemies) {
        // Example: Render enemy sprite at enemy.getXPos(), enemy.getYPos()
        enemy.draw(window);
    }

    // Render towers
    for (auto& tower : towers) {
        // Example: Render tower sprite at tower.getXPos(), tower.getYPos()
        tower.draw(window);
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

std::queue<std::pair<int,int>> Game::getCheckpoints() { 
    return this->getMap().checkpoints;
}