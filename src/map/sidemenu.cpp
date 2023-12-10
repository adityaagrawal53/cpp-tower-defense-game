#include "sidemenu.hpp"

SideMenu::SideMenu(int windowWidth, int windowHeight, int menuWidth) {

    menuBackground.setSize(sf::Vector2f(menuWidth, windowHeight));
    menuBackground.setFillColor(sf::Color(161, 102, 47));
    menuBackground.setPosition(windowWidth - menuWidth, 0);

    font.loadFromFile("arial.ttf"); 
    towerText.setFont(font);
    towerText.setCharacterSize(20);
    towerText.setFillColor(sf::Color::Black);

    // Load button texture
    if (!buttonTexture.loadFromFile("map/default/sidemenu.png")) {
        // Handle texture loading error
        std::cout <<"Error button texture loading";
    }

    button.setTexture(buttonTexture);
    button.setPosition(
        menuBackground.getPosition().x + 10,  // Adjust the X position as needed
        menuBackground.getPosition().y + 50   // Adjust the Y position as needed
    );    
}

int SideMenu::handleMouseInput(sf::Event::MouseButtonEvent& mouseEvent) {
    // Handle mouse input for tower selection
    if (mouseEvent.button == sf::Mouse::Left) {
        // Check if the mouse click is within the side menu
        if (mouseEvent.x > menuBackground.getPosition().x && mouseEvent.y < menuBackground.getSize().y) {
            // Check if the mouse click is within the button
            sf::FloatRect buttonBounds = button.getGlobalBounds();
            if (buttonBounds.contains(mouseEvent.x, mouseEvent.y)) {
                // Mouse click occurred within the button
                std::cout << "Button Clicked!" << std::endl;
                return 1;
            } 
        }
    } 
}

void SideMenu::draw(sf::RenderWindow& window) {
    window.draw(menuBackground);

    // Draw tower names or icons
    // Adjust position and layout based on your design
    towerText.setPosition(menuBackground.getPosition().x + 10, menuBackground.getPosition().y + 10); // Adjusted position
    window.draw(towerText);

    // Draw button at a specific position
    button.setPosition(menuBackground.getPosition().x + 10, menuBackground.getPosition().y + 50);
    window.draw(button);
}

//set the side menu to the right of the map
void SideMenu::setPosition(sf::Vector2f position) {
    menuBackground.setPosition(position);
}


