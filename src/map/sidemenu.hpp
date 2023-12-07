#ifndef SIDEMENU_HPP
#define SIDEMENU_HPP

#include <SFML/Graphics.hpp>

class SideMenu {
public:
    SideMenu(int windowWidth, int windowHeight, int menuWidth);
    void handleMouseInput(sf::Event::MouseButtonEvent& mouseEvent);
    void draw(sf::RenderWindow& window);
    void setPosition(sf::Vector2f position);
    int getSelectedTower() const;

private:
    sf::RectangleShape menuBackground;
    sf::Font font;
    sf::Text towerText;
    int selectedTower;
};

#endif // SIDEMENU_HPP
