#ifndef TOWER_WATER_HPP
#define TOWER_WATER_HPP

#include <string>
#include "tower.hpp"

class Water : public Tower {
public:
    //Tower with longer range at the cost of damage and some HP. Slight increase in cost compared to the basic tower
    //Water(std::string name = "Water", int damage = 5, int hp = 20, double range = 4.0, int cost = 15, int damageOverTime = 0);
    Water(Game* game): Tower(game, "Water", 5, 200, 4.0, 15, 0, position){};


    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("map/default/Tower_water.png")) {
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