#include <list>
#include <iostream>
#include <math.h>           //Trigonometric functions
#include <queue>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "enemy/enemy.cpp"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    //Centers window
    auto desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i(desktop.width/2 - window.getSize().x/2, desktop.height/2 - window.getSize().y/2));

    std::vector<std::string> backgroundFiles = {"map/default/background1.jpg", "map/default/background2.jpg", "map/default/background3.jpg"};
    int selectedBackgroundIndex = 1; // Change this index to select a different background

    GridMap grid(gridSize, windowSize, "map/default/map.txt", backgroundFiles, selectedBackgroundIndex);

    grid.loadMap("map/default/map.txt");

    Game game;

    // Add Checkpoints to the list
    std::queue<Checkpoint> checkpoints;
    
    checkpoints.push(checkpoint1);
    checkpoints.push(checkpoint2);
    checkpoints.push(checkpoint3);
    checkpoints.push(checkpoint4);
    checkpoints.push(checkpoint5);
    checkpoints.push(checkpoint6);
    checkpoints.push(checkpoint7);
    checkpoints.push(checkpoint8);
    checkpoints.push(checkpoint9);
    checkpoints.push(checkpoint0);

    // List of enemies
    std::list<Enemy*> enemies;
    
    Enemy* test = new Enemy(30, 0.3f, 5, 5, checkpoints);
    Enemy* test2 = new Enemy(20, 0.5f, 5, 5, checkpoints);

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
            sf::Sprite enemySprite(enemyTexture);
            enemySprite.setOrigin(35.f, 35.f);

            enemySprite.setPosition(e->getXPos(), e->getYPos());
            window.draw(enemySprite);

            e->move();
        }

        window.draw(cp1);
        window.draw(cp2);
        window.draw(cp3);
        window.draw(cp4);
        window.draw(cp5);
        window.draw(cp6);
        window.draw(cp7);
        window.draw(cp8);
        window.draw(cp9);
        window.draw(cp0);
        
        // Update the window
        window.display();
    }
 
    return EXIT_SUCCESS;
}