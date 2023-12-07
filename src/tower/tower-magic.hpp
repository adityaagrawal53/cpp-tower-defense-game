#ifndef TOWER_MAGIC_HPP
#define TOWER_MAGIC_HPP

#include <string>
#include "tower.hpp"

class Magic : public Tower {
public:
    Magic(std::string name = "Magic", int damage = 10, int hp = 50, double range = 3.0, int cost = 50, int damageOverTime = 0);

    void attack() override {

        std::vector<Enemy> enemiesInRange = getEnemiesInRange();

        // Apply damage to all enemies in range
        for (auto& enemy : enemiesInRange) {
            enemy.setHP(enemy.getHP() - getDamage());
        }
    }

    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("")) {
            std::cout << "Could not load MagicTower sprite" << std::endl;
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