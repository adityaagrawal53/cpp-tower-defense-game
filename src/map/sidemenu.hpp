#ifndef SIDEMENU_HPP
#define SIDEMENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class SideMenu {
public:
    SideMenu(int windowWidth, int windowHeight, int menuWidth);
    int handleMouseInput(sf::Event::MouseButtonEvent& mouseEvent);
    void draw(sf::RenderWindow& window);
    void setPosition(sf::Vector2f position);


private:
    sf::RectangleShape menuBackground;
    sf::Font font;
    sf::Text towerText;

    sf::Texture buttonTexture;
    sf::Sprite button;
};

#endif // SIDEMENU_HPP
