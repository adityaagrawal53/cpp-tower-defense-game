// Game.h

#include "game.hpp"
#include "game_loading_functions.cpp"

#include "../enemy/enemy-bomb.hpp"
#include "../enemy/enemy-boss.cpp"
#include "../enemy/enemy-plant.hpp"
#include "../enemy/enemy-tree.hpp"
#include "../enemy/enemy-bomb.hpp"
#include <iostream>

// Game.cpp

Game::Game(const GridMap& initialMap) : gamewindow(sf::VideoMode(800, 600), "Tower Defense Game"), map(initialMap) {
    // Initialize game variables
    //gamewindow = sf::Window(sf::VideoMode(712, 512), "Tower Defense Game");
    playerScore = 0;
    currentWave = 1;
    playerMoney = 1000;
    playerHealth = 1000;
    // Initialize game elements
    loadWave(currentWave);
    run();
}

Enemy* Game::createEnemy(const char type) {
    if (type == 'p') {        
        // plant type
        return new PlantEnemy(this);
    } else if (type == 'b') { 
        // bomb type
        return new BombEnemy(this);
    } else if (type == 'o') { 
        // boss type
        return new BossEnemy(this);
    } else if (type == 't') { 
        // tree type
        return new TreeEnemy(this);
    }
}

void Game::loadWave(int roundNumber) { 
    loadEnemies(roundNumber);
}


void Game::run(){
    
    auto enemyCount = enemies.size();
    std::cout << enemyCount << std::endl;
    int i = 0;

    while (gamewindow.isOpen()) {
        
        //Spawns enemies once a second
        if (run_clock.getElapsedTime().asSeconds() >= 1.0) {
            if(i < enemyCount) {
                currentEnemies.push_back(enemies[i]);
                i++;
            }
            run_clock.restart();
        }
        update();
        render();
    }
}

std::vector<Tower*>& Game::getTowers() {
    return towers;
}

std::vector<Enemy*>& Game::getEnemies() {
    return enemies;
}

void Game::handleTowerEnemyInteractions() {
    //Attacks once every second
    if (run_clock.getElapsedTime().asSeconds() >= 1.0) {
        for (auto enemy : currentEnemies) {
            enemy->attack();
        }

        // Render towers
        for (auto tower : towers) {
            tower->attack();
        }
        run_clock.restart();
    }

    //Remove all enemies that are dead or reached the end
    if(!currentEnemies.empty()) {
        std::cout << currentEnemies.size() << std::endl;
        std::cout << "removing enemy" << std::endl;
        for(auto e = currentEnemies.begin(); e != currentEnemies.end();) {
            if((*e)->isDead()) {
                e = currentEnemies.erase(e);
            } else if((*e)->reachedDestination()) {
                //Enemy reached the end, lose 1 LP
                e = currentEnemies.erase(e);
                playerHealth -= 1;
            }
            ++e;
        }
    }

    // Remove all towers that are dead
    towers.erase(std::remove_if(towers.begin(), towers.end(),
                                 [](const Tower* tower) { return tower->getHealth() <= 0; }),
                  towers.end());
}

void Game::update() {
    // Update game logic, enemy movement, tower attacks, etc.

    // Update enemy positions
    for (auto& enemy : currentEnemies) {
        enemy->move();
    }

    handleTowerEnemyInteractions();

    // Check if the round is completed
    if (enemies.empty()) {
        currentWave++;
        std::cout << "all enemies destroyed. moving to wave " << currentWave << std::endl;
        loadWave(currentWave);
    }

    // Check if the player has lost
    if (playerHealth <= 0) {
        // Handle game over (display message, reset game, etc.)
        // For now, let's just close the window
        gamewindow.close();
    }

    update_clock.restart();
}

void Game::render() {
    gamewindow.clear();

    // Render game elements
    map.draw(gamewindow);

    // Render enemies
    for (auto& enemy : currentEnemies) {
        // Example: Render enemy sprite at enemy.getXPos(), enemy.getYPos()
        enemy->draw(gamewindow);
    }

    // Render towers
    for (auto& tower : towers) {
        // Example: Render tower sprite at tower.getXPos(), tower.getYPos()
        tower->draw(gamewindow);
    }

    // Render UI elements (score, health, etc.)
    // Example: Render player score and health at the top of the window

    gamewindow.display();
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