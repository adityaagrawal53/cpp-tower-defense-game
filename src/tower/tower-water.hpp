#ifndef TOWER_PLANT_HPP
#define TOWER_PLANT_HPP

#include <string>
#include "tower.hpp"

class Water : public Tower {
public:
    Water(std::string name = "Water", int damage = 5, int hp = 20, double range = 4.0, int cost = 15, int damageOverTime = 0);

    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("")) {
            std::cout << "Could not load WaterTower sprite" << std::endl;
            return;
        }

        sf::Sprite enemySprite;
        enemySprite.setTexture(texture);
        enemySprite.setOrigin(enemySprite.getGlobalBounds().width, enemySprite.getGlobalBounds().height);
        enemySprite.setPosition(getPosition().x, getPosition().y);
        window.draw(enemySprite);
    }

private:
};

#endif