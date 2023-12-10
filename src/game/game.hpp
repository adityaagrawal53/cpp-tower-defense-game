#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../enemy/enemy.hpp"
#include "../tower/tower.hpp"
#include "../map/map.hpp"
#include <fstream>
#include <queue>

/// Represents the main game class responsible for managing the game state and logic.
class Game {
public:

    /**
     * \brief Constructs a Game instance with the specified initial map.
     * \param initialMap The initial map for the game.
     */
    Game(const GridMap& initialMap);

    /**
     * \brief Creates an enemy based on the specified type.
     * \param type The type of enemy to create.
     * \return A pointer to the created enemy.
     */
    Enemy* createEnemy(const char type);

    /**
     * \brief Initializes the game.
     */
    void initialize();

    /**
     * \brief Runs the main game loop.
     */
    void run();

    /// \brief Gets the collection of towers in the game.
    std::vector<Tower*>& getTowers();


    /// \brief Gets the collection of enemies in the game.
    std::vector<Enemy*>& getEnemies();


    /**
     * \brief Gets the player's current health.
     * \return The player's current health.
     */
    int getPlayerHealth() const;

    /**
     * \brief Sets the player's health to the specified value.
     * \param health The new health value.
     */
    void setPlayerHealth(int health);

    /**
     * \brief Gets the player's current score.
     * \return The player's current score.
     */
    int getPlayerScore() const;
    
    /**
     * \brief Sets the player's score to the specified value.
     * \param score The new score value.
     */
    void setPlayerScore(int score);

    /**
     * \brief Gets the current wave number.
     * \return The current wave number.
     */
    int getCurrentWave() const;

    /**
     * \brief Sets the current wave number to the specified value.
     * \param wave The new wave number.
     */
    void setCurrentWave(int wave);

    /**
     * \brief Gets the player's current money.
     * \return The player's current money.
     */
    int getPlayerMoney() const;

    /**
     * \brief Sets the player's money to the specified value.
     * \param money The new money value.
     */
    void setPlayerMoney(int money);

    /**
     * \brief Gets the current game map.
     * \return The current game map.
     */
    GridMap getMap() const;

    /**
     * \brief Gets the checkpoints from the current game map.
     * \return A queue of checkpoint coordinates.
     */
    std::queue<std::pair<int, int>> getCheckpoints();

    /**
     * \brief Reads and returns a collection of enemies from a file.
     * \param filename The name of the file containing enemy data.
     * \return A vector of Enemy pointers.
     */
    std::vector<Enemy*> readEnemiesFromFile(const std::string& filename);

    /// Contains file paths for background images used in the game.
    std::vector<std::string> backgroundImageFiles = {"map/default/background1.jpg", "map/default/background2.jpg", "map/default/background3.jpg"};

private:
    /// The main window where the game is rendered.
    sf::RenderWindow gamewindow;

    /// The game map representing the layout of the playing field.
    GridMap map;

    /// The clock used for tracking time in the game.
    sf::Clock clock;

    // Game variables

    /// The current health of the player.
    int playerHealth;

    /// The score the player has.
    int playerScore;

    /// The current wave number in the game.
    int currentWave;

    /// The amount of in-game currency available to the player.
    int playerMoney;

    /// The list of all enemies in the game.
    std::vector<Enemy*> enemies;

    /// The list of enemies currently active in the game.
    std::vector<Enemy*> currentEnemies = {};

    /// The list of all towers active in the game.
    std::vector<Tower*> towers;

    /// The clock used to control the run function.
    sf::Clock run_clock;

    /// The clock used to measure the overall game time.
    sf::Clock game_clock;

    /// The clock used to control the update function.
    sf::Clock update_clock;

    // Methods to handle game logic
    
    /**
     * \brief Handles user input during the game.
     */
    void handleInput();

    /**
     * \brief Updates the game logic, including enemy movement, tower attacks, etc.
     */
    void update();

    /**
     * \brief Renders the game elements on the window.
     */
    void render();

    // Helper methods

    /**
     * \brief Loads the game map from a configuration file.
     * \param mapConfigFile The name of the file containing map configuration.
     */
    void loadMap(const std::string& mapConfigFile);

    /**
     * \brief Loads the specified wave of enemies.
     * \param roundNumber The number of the current wave.
     */
    void loadWave(int roundNumber);

    /**
     * \brief Loads enemies for the specified wave.
     * \param roundNumber The number of the current wave.
     */
    void loadEnemies(int roundNumber);

    /**
     * \brief Handles interactions between towers and enemies.
     * Simulates attacks and removes dead enemies and towers.
     */
    void handleTowerEnemyInteractions();
};
