#ifndef TOWER_WATER_HPP
#define TOWER_WATER_HPP

#include <string>
#include "tower.hpp"

class Water : public Tower {
public:
    //Tower with longer range at the cost of damage and some HP. Slight increase in cost compared to the basic tower
    Water(std::string name = "Water", int damage = 5, int hp = 20, double range = 4.0, int cost = 15, int damageOverTime = 0);


    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("")) {
            std::cout << "Could not load WaterTower sprite" << std::endl;
            return;
        }

        sf::Sprite towerSprite;
        towerSprite.setTexture(texture);
        towerSprite.setOrigin(towerSprite.getGlobalBounds().width, towerSprite.getGlobalBounds().height);
        towerSprite.setPosition(getPosition().x, getPosition().y);
        window.draw(towerSprite);
    }

private:
};

#endif