#include "menu.hpp"

MainMenu::MainMenu(sf::RenderWindow& window) : window(window) {
    if (!backgroundTexture.loadFromFile("menu/pic/menupic.jpg")) {
        // Handle texture loading error for background
    }

    if (!startTexture.loadFromFile("menu/pic/start.png")) {
        // Handle texture loading error for start button
    }

    if (!quitTexture.loadFromFile("menu/pic/quit.png")) {
        // Handle texture loading error for quit button
    }

    background.setTexture(backgroundTexture);
    startButton.setTexture(startTexture);
    startButton.setPosition(window.getSize().x / 2 - startButton.getGlobalBounds().width / 2, 150);

    quitButton.setTexture(quitTexture);
    quitButton.setPosition(window.getSize().x / 2 - quitButton.getGlobalBounds().width / 2, 250);

    // Set initial scaling factors
    startButtonScale = 0.5f; 
    quitButtonScale = 0.5f;  

    startButton.setScale(startButtonScale, startButtonScale);
    quitButton.setScale(quitButtonScale, quitButtonScale);
}

void MainMenu::draw() {
    window.clear();

    // Draw background first
    window.draw(background);

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
                    return 1; // Start button pressed
                } else if (quitButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    return 2; // Quit button pressed
                }
            }
        }
    }
    return 0; // No button pressed
}
