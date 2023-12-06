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

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        // Handle mouse input for map
        map.handleMouseInput(event);
    }
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

void Game::loadWave(int roundNumber) {
    // Load enemies and setup for the given round
    spawnEnemiesForRound(roundNumber);
}

void Game::spawnEnemiesForRound(int roundNumber) {
    // Clear existing enemies and towers
    enemies.clear();
    towers.clear();

    // Example: Load enemies and towers for each round
    // Adjust the number, type, and difficulty of enemies as needed
    switch (roundNumber) {
        case 1:
            // Load enemies for round 1
            enemies = readEnemiesFromFile("default/enemy1.txt");
            break;

        case 2:
            // Load enemies for round 2
            enemies.push_back(Enemy(/* parameters for enemy 1 */));
            enemies.push_back(Enemy(/* parameters for enemy 2 */));
            break;

        // Add more cases for additional rounds

        default:
            // Handle completion of all rounds (victory)
            // For now, let's close the window
            window.close();
            break;
    }
}



void Game::loadWave(int waveNumber) {
    // Construct filenames for map and enemy configuration
    std::string mapConfigFile = "wave" + std::to_string(waveNumber) + "_map_config.txt";
    std::string enemyConfigFile = "wave" + std::to_string(waveNumber) + "_enemy_config.txt";

    // Load map and enemies for the wave
    loadMap(mapConfigFile);
    loadEnemies(enemyConfigFile);
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
    while (enemyConfigStream >> hp >> speed >> attack >> xp) {
        enemies.push_back(PlantEnemy(this));
    }

    enemyConfigStream.close();
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