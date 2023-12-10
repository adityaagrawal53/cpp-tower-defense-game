#include "sidemenu.hpp"

SideMenu::SideMenu(int windowWidth, int windowHeight, int menuWidth) {

    menuBackground.setSize(sf::Vector2f(menuWidth, windowHeight));
    menuBackground.setFillColor(sf::Color(200, 200, 200));
    menuBackground.setPosition(windowWidth - menuWidth, 0);

    font.loadFromFile("arial.ttf"); 
    towerText.setFont(font);
    towerText.setCharacterSize(20);
    towerText.setFillColor(sf::Color::Black);

    button.setTexture(buttonTexture);

}

void SideMenu::handleMouseInput(sf::Event::MouseButtonEvent& mouseEvent) {
    // Handle mouse input for tower selection
    if (mouseEvent.button == sf::Mouse::Left) {
        // Check if the mouse click is within the side menu
        if (mouseEvent.x > menuBackground.getPosition().x && mouseEvent.y < menuBackground.getSize().y) {
            // Calculate the tower index based on mouse position or any other method
        
        }
    }
}

void SideMenu::draw(sf::RenderWindow& window) {
    window.draw(menuBackground);

    // Draw tower names or icons
    // Adjust position and layout based on your design
    towerText.setPosition(menuBackground.getPosition().x + 10, menuBackground.getPosition().y + 10); // Adjusted position
    window.draw(towerText);
}

//set the side menu to the right of the map
void SideMenu::setPosition(sf::Vector2f position) {
    menuBackground.setPosition(position);
}


