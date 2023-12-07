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

// Game.cpp

Game::Game(const GridMap& initialMap) : window(sf::VideoMode(800, 600), "Tower Defense Game"), map(initialMap) {
    // Initialize game variables
    playerScore = 0;
    currentWave = 1;
    playerMoney = 1000;
    playerHealth = 1000;

    // Initialize game elements
    loadWave(currentWave);
}

void Game::createEnemy(const std::string& type) {
    if (type == "p") {        // plant type
        this->getEnemies().push_back(PlantEnemy(this));
    } else if (type == "b") { // bomb type
        this->getEnemies().push_back(BombEnemy(this));
    } else if (type == "o") { // boss type
        //will be implemented later 
    } else if (type == "f") { // fire type
        //no
    } else if (type == "g") { // ground type
        //no 
    } else if (type == "m") { // magic type
        //no
    } else if (type == "t") { // tree type
        this->getEnemies().push_back(TreeEnemy(this));
    } else if (type == "w") { // water type
        //no
    }
}

void Game::loadWave(int roundNumber) { 
    loadEnemies(roundNumber);
    //loadTowers(roundNumber);
    //loadMap (??)
}


void Game::run(){
    
    while (window.isOpen()) {
        /*
        //Handling input
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
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