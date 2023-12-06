#ifndef TOWER_PLANT_HPP
#define TOWER_PLANT_HPP

#include <string>
#include "tower.hpp"

class Plant : public Tower {
public:
    Plant(std::string name = "Plant", int damage = 10, int hp = 25, double range = 2.0, int cost = 10, int damageOverTime = 0);

    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("")) {
            std::cout << "Could not load PlantTower sprite" << std::endl;
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
