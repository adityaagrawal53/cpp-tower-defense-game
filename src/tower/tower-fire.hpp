#ifndef TOWER_PLANT_HPP
#define TOWER_PLANT_HPP

#include <string>
#include "tower.hpp"

class Fire : public Tower {
public:
    Fire(std::string name = "Fire", int damage = 5, int hp = 25, double range = 2.0, int cost = 25, int damageOverTime = 5);

    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("")) {
            std::cout << "Could not load FireTower sprite" << std::endl;
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