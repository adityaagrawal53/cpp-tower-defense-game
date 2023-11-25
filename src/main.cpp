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

    //TODO: wait in seconds
    Checkpoint checkpoint1 = {300, 200, 300};
    Checkpoint checkpoint2 = {350, 400, 200};
    Checkpoint checkpoint3 = {500, 100, 0};
    Checkpoint checkpoint4 = {600, 300, 0};
    Checkpoint checkpoint5 = {600, 400, 0};
    Checkpoint checkpoint6 = {500, 400, 0};
    Checkpoint checkpoint7 = {300, 500, 0};
    Checkpoint checkpoint8 = {500, 500, 0};
    Checkpoint checkpoint9 = {500, 600, 0};
    Checkpoint checkpoint0 = {600, 300, 0};

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
    cp1.setPosition(checkpoint1.x, checkpoint1.y);

    cp2.setFillColor(sf::Color::Red);
    cp2.setOrigin(15.f, 15.f);
    cp2.setPosition(checkpoint2.x, checkpoint2.y);

    cp3.setFillColor(sf::Color::Red);
    cp3.setOrigin(15.f, 15.f);
    cp3.setPosition(checkpoint3.x, checkpoint3.y);

    cp4.setFillColor(sf::Color::Red);
    cp4.setOrigin(15.f, 15.f);
    cp4.setPosition(checkpoint4.x, checkpoint4.y);

    cp5.setFillColor(sf::Color::Red);
    cp5.setOrigin(15.f, 15.f);
    cp5.setPosition(checkpoint5.x, checkpoint5.y);

    cp6.setFillColor(sf::Color::Red);
    cp6.setOrigin(15.f, 15.f);
    cp6.setPosition(checkpoint6.x, checkpoint6.y);

    cp7.setFillColor(sf::Color::Red);
    cp7.setOrigin(15.f, 15.f);
    cp7.setPosition(checkpoint7.x, checkpoint7.y);

    cp8.setFillColor(sf::Color::Red);
    cp8.setOrigin(15.f, 15.f);
    cp8.setPosition(checkpoint8.x, checkpoint8.y);

    cp9.setFillColor(sf::Color::Red);
    cp9.setOrigin(15.f, 15.f);
    cp9.setPosition(checkpoint9.x, checkpoint9.y);

    cp0.setFillColor(sf::Color::Red);
    cp0.setOrigin(15.f, 15.f);
    cp0.setPosition(checkpoint0.x, checkpoint0.y);

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
            sf::CircleShape shape(35.f);
            shape.setFillColor(sf::Color::Green);
            shape.setOrigin(35.f, 35.f);
            
            shape.setPosition(e->getXPos(), e->getYPos());
            window.draw(shape);

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