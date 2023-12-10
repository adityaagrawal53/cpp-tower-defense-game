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
    sf::Texture buttonTexture;
    sf::Sprite button;


private:
    sf::RectangleShape menuBackground;
    sf::Font font;
    sf::Text towerText;


};

#endif // SIDEMENU_HPP
