#include <list>
#include <iostream>
#include <math.h>           //Trigonometric functions
#include <queue>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "enemy/enemy.cpp"
#include "game/game.cpp"
#include "tower/tower.cpp"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    //Centers window
    auto desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i(desktop.width/2 - window.getSize().x/2, desktop.height/2 - window.getSize().y/2));

    std::vector<std::string> backgroundFiles = {"map/default/background1.jpg", "map/default/background2.jpg", "map/default/background3.jpg"};
    int selectedBackgroundIndex = 1; // Change this index to select a different background

    const int gridSize = 32;
    const int windowSize = gridSize * 16;
    GridMap grid(gridSize, windowSize, "map/default/map.txt", backgroundFiles, selectedBackgroundIndex);

    grid.loadMap("map/default/map.txt");

    Game game(grid);

    /*//TODO: wait in seconds
    std::pair<int, int> checkpoint1 = {300, 200};
    std::pair<int, int> checkpoint2 = {350, 400};
    std::pair<int, int> checkpoint3 = {500, 100};
    std::pair<int, int> checkpoint4 = {600, 300};
    std::pair<int, int> checkpoint5 = {600, 400};
    std::pair<int, int> checkpoint6 = {500, 400};
    std::pair<int, int> checkpoint7 = {300, 500};
    std::pair<int, int> checkpoint8 = {500, 500};
    std::pair<int, int> checkpoint9 = {500, 600};
    std::pair<int, int> checkpoint0 = {600, 300};

    sf::CircleShape cp1(15.f);
    sf::CircleShape cp2(15.f);
    sf::CircleShape cp3(15.f);
    sf::CircleShape cp4(15.f);
    sf::CircleShape cp5(15.f);
    sf::CircleShape cp6(15.f);
    sf::CircleShape cp7(15.f);
    sf::CircleShape cp8(15.f);
    sf::CircleShape cp9(15.f);
    sf::CircleShape cp0(15.f);

    cp1.setFillColor(sf::Color::Red);
    cp1.setOrigin(15.f, 15.f);
    cp1.setPosition(checkpoint1.first, checkpoint1.second);

    cp2.setFillColor(sf::Color::Red);
    cp2.setOrigin(15.f, 15.f);
    cp2.setPosition(checkpoint2.first, checkpoint2.second);

    cp3.setFillColor(sf::Color::Red);
    cp3.setOrigin(15.f, 15.f);
    cp3.setPosition(checkpoint3.first, checkpoint3.second);

    cp4.setFillColor(sf::Color::Red);
    cp4.setOrigin(15.f, 15.f);
    cp4.setPosition(checkpoint4.first, checkpoint4.second);

    cp5.setFillColor(sf::Color::Red);
    cp5.setOrigin(15.f, 15.f);
    cp5.setPosition(checkpoint5.first, checkpoint5.second);

    cp6.setFillColor(sf::Color::Red);
    cp6.setOrigin(15.f, 15.f);
    cp6.setPosition(checkpoint6.first, checkpoint6.second);

    cp7.setFillColor(sf::Color::Red);
    cp7.setOrigin(15.f, 15.f);
    cp7.setPosition(checkpoint7.first, checkpoint7.second);

    cp8.setFillColor(sf::Color::Red);
    cp8.setOrigin(15.f, 15.f);
    cp8.setPosition(checkpoint8.first, checkpoint8.second);

    cp9.setFillColor(sf::Color::Red);
    cp9.setOrigin(15.f, 15.f);
    cp9.setPosition(checkpoint9.first, checkpoint9.second);

    cp0.setFillColor(sf::Color::Red);
    cp0.setOrigin(15.f, 15.f);
    cp0.setPosition(checkpoint0.first, checkpoint0.second);

    // Add Checkpoints to the list
    std::queue<std::pair<int, int>> checkpoints;
    
    checkpoints.push(checkpoint1);
    checkpoints.push(checkpoint2);
    checkpoints.push(checkpoint3);
    checkpoints.push(checkpoint4);
    checkpoints.push(checkpoint5);
    checkpoints.push(checkpoint6);
    checkpoints.push(checkpoint7);
    checkpoints.push(checkpoint8);
    checkpoints.push(checkpoint9);
    checkpoints.push(checkpoint0);*/

    // List of enemies
    std::list<Enemy*> enemies;

    Enemy* test = new Enemy(&game, 30, 0.3f, 5, 5, 5.0);
    Enemy* test2 = new Enemy(&game, 20, 0.5f, 5, 5, 5.0);

    enemies.push_back(test);
    enemies.push_back(test2);

    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("angry_man.png")) {
        std::cerr << "Failed to load enemy texture!" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;

        //Mouse position
        sf::Vector2i position = sf::Mouse::getPosition();
        //std::cout << "Mouse position: x = " << position.x  << " y == " << position.y << std::endl;
        std::cout << "enemy HP: " << test->getHP() << std::endl;

        while (window.pollEvent(event)) {
            // Close window: exit
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Click to damage
            if(event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    std::cout << "Damage" << std::endl;
                    for(auto e : enemies) {
                        e->setHP(e->getHP() - 3);
                    }
                }
            }
        }
 
        // Clear screen
        window.clear();
 
        // Draw the sprite
        // Remove dead enemies(0 HP or less)
        enemies.remove_if([](Enemy* e) { return e->getHP() <= 0; });
        
        // 
        for(auto e : enemies) {
            sf::Texture enemyTexture;
            if (!enemyTexture.loadFromFile("/images/angry_man.png")) {
                std::cerr << "Failed to load enemy texture!" << std::endl;
                return EXIT_FAILURE;
            }
            sf::Sprite enemySprite(enemyTexture);
            enemySprite.setOrigin(35.f, 35.f);

            enemySprite.setPosition(e->getXPos(), e->getYPos());
            window.draw(enemySprite);

            e->move();
        }
        
        // Update the window
        window.display();
    }
 
    return EXIT_SUCCESS;
}