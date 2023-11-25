// Game.h

#include "game.hpp"

// Game.cpp


Game::Game() : window(sf::VideoMode(800, 600), "Tower Defense Game"), map(50, 10, 10, "background_image.jpg", "map.txt") {
    // Initialize game variables
    playerHealth = 100;
    playerScore = 0;
    currentWave = 1;

    // Initialize game elements
    initialize();
}

void Game::initialize() {
    // Load the first round
    loadRound(currentWave);
}

void Game::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
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

        // Check for collisions with towers
        for (auto& tower : towers) {
            if (tower.inRange(enemy)) {
                // Example: If the tower is in range, decrease enemy health
                enemy.takeDamage(tower.getDamage());
            }
        }

        // Check for collisions with the end of the path
        if (map.isEnemyAtEnd(enemy)) {
            // Example: If enemy reaches the end, decrease player health
            playerHealth -= enemy.getAttack();
        }
    }

    // Check if the round is completed
    if (enemies.empty()) {
        currentWave++;
        loadRound(currentWave);
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

void Game::loadRound(int roundNumber) {
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
            enemies.push_back(Enemy(/* parameters for enemy 1 */));
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


Game::Game() : window(sf::VideoMode(800, 600), "Tower Defense Game"), clock(), playerHealth(100), playerScore(0), currentWave(1) {
    // Initialize game elements
    initialize();
}

void Game::initialize() {
    // Load the first wave
    loadWave(currentWave);
}

void Game::loadWave(int waveNumber) {
    // Construct filenames for map and enemy configuration
    std::string mapConfigFile = "wave" + std::to_string(waveNumber) + "_map_config.txt";
    std::string enemyConfigFile = "wave" + std::to_string(waveNumber) + "_enemy_config.txt";

    // Load map and enemies for the wave
    loadMap(mapConfigFile);
    loadEnemies(enemyConfigFile);
}

void Game::loadMap(const std::string& mapConfigFile) {
    std::ifstream mapConfigStream(mapConfigFile);
    if (!mapConfigStream.is_open()) {
        // Handle file opening error
        return;
    }

    // Read map configuration
    int gridSize, rows, cols;
    std::string backgroundImageFile, mapLayoutFile;
    mapConfigStream >> gridSize >> rows >> cols >> backgroundImageFile >> mapLayoutFile;
    mapConfigStream.close();

    // Load the background image
    if (backgroundImageTexture.loadFromFile(backgroundImageFile)) {
        backgroundImageSprite.setTexture(backgroundImageTexture);
    }

    // Initialize the grid and load the map from file
    map = GridMap(gridSize, rows, cols, backgroundImageFile, mapLayoutFile);
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
        enemies.push_back(Enemy(hp, speed, attack, xp, /* additional parameters if needed */));
    }

    enemyConfigStream.close();
}