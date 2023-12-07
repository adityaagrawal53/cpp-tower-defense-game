// Game.h

#include "game.hpp"
#include "game_loading_functions.cpp"

#include "../enemy/enemy-bomb.hpp"
#include "../enemy/enemy-fire.hpp"
#include "../enemy/enemy-boss.hpp"
//#include "../enemy/enemy-ground.cpp"
//#include "../enemy/enemy-magic.cpp"
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
    std::cout << "we here" << std::endl; 
    // Initialize game elements
    std::cout << "we here!!!" << std::endl;
    loadWave(currentWave);
    std::cout << "Loaded wave successfullyasdfs" << std::endl;  
    run();
}

Enemy Game::createEnemy(const char type) {
    if (type == 'p') {        // plant type
        std::cout << "plant" << std::endl;
        return PlantEnemy(this);
    } else if (type == 'b') { // bomb type
        return BombEnemy(this);
    } else if (type == 'o') { // boss type
        //will be implemented later 
    } else if (type == 'f') { // fire type
        //no
    } else if (type == 'g') { // ground type
        //no 
    } else if (type == 'm') { // magic type
        //no
    } else if (type == 't') { // tree type
        std::cout << 'tree' << std::endl;
        return TreeEnemy(this);
    } else if (type == 'w') { // water type
        //no
    }
}

void Game::loadWave(int roundNumber) { 
    std::cout << "Loaded wave successfully1" << std::endl; 
    //loadMap("map/default/map2.txt");
    std::cout << "Loaded wave successfully2" << std::endl; 
    loadEnemies(roundNumber);
    //loadTowers(roundNumber);
    //loadMap (??)
}


void Game::run(){
    
    while (gamewindow.isOpen()) {
        /*
        //Handling input
        sf::Event event;
        
        while (gamewindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gamewindow.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                // Call handleMouseInput for the GridMap instance
                grid.handleMouseInput(event.mouseButton);

                // You can also call handleMouseInput for the SideMenu instance if needed
                sideMenu.handleMouseInput(event.mouseButton);
            }
        }
        map.handleMouseInput(sf::Event::MouseButtonEvent& mouseEvent);
        */
        //Updating and rendering map
        if (run_clock.getElapsedTime().asSeconds() >= 1.0) {
            update();
            render();
            std::cout << "Running successfully!";

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

void Game::handleTowerEnemyInteractions() {
    for (auto& enemy : enemies) {
        // Example: Render enemy sprite at enemy.getXPos(), enemy.getYPos()
        enemy.attack();
    }

    // Render towers
    for (auto& tower : towers) {
        tower.attack();
    }

    // Remove all enemies and towers that are dead
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
                                 [](const Enemy& enemy) { return enemy.isDead(); }),
                  enemies.end());

    towers.erase(std::remove_if(towers.begin(), towers.end(),
                                 [](const Tower& tower) { return tower.getHealth() <= 0; }),
                  towers.end());
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
    for (auto& enemy : enemies) {
        // Example: Render enemy sprite at enemy.getXPos(), enemy.getYPos()
        enemy.draw(gamewindow);
    }

    // Render towers
    for (auto& tower : towers) {
        // Example: Render tower sprite at tower.getXPos(), tower.getYPos()
        tower.draw(gamewindow);
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