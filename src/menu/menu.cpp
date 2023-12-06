

#include "menu.hpp"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow& window) : window(window) {
    // Load background image
    if (!backgroundTexture.loadFromFile("menu/pic/menupic.jpg")) {
        std::cout << "Menu pic loading error";
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Load start button image
    if (!startTexture.loadFromFile("menu/pic/start.jpg")) {
        std::cout <<"start pic loading error";
    }

    // load quit button image
    if (!quitTexture.loadFromFile("menu/pic/quit.jpg")){
        std::cout <<"quit pic loading error";
    }
    startButton.setTexture(startTexture);
    startButton.setPosition(window.getSize().x / 2 - startButton.getGlobalBounds().width / 2, 150);

    quitButton.setTexture(quitTexture);
    quitButton.setPosition(window.getSize().x / 2 - quitButton.getGlobalBounds().width /2, 250 );

}

void MainMenu::draw() {
    window.clear();

    // Draw background first
    window.draw(backgroundSprite);

    // Draw buttons on top of the background
    window.draw(startButton);
    window.draw(quitButton);

    window.display();
}

int MainMenu::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (startButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    return 1; // Start button pressed --> open game window in main
                } else if (quitButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    window.close(); 
                }
            }
        }
    }
    return 0; // No button pressed
}