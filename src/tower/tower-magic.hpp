#ifndef TOWER_MAGIC_HPP
#define TOWER_MAGIC_HPP

#include <string>
#include "tower.hpp"

//The tower that applies moderate damage to all enemies present within its range. Slight increase in range and double the HP compared to the basic tower but with much higher cost.
class Magic : public Tower {
public:
    //Magic(std::string name = "Magic", int damage = 10, int hp = 50, double range = 3.0, int cost = 50, int damageOverTime = 0);
    Magic(Game* game): Tower(game, "Magic", 10, 50, 3.0, 50, 0, position){};


    //This tower does not use the attack method specified in the base Tower class because it deals damage to all enemies within range, thus an override is used for a new attack method.
    void attack() override {

        std::vector<Enemy*> enemiesInRange = getEnemiesInRange();

        // Apply damage to all enemies in range
        for (auto& enemyPtr : enemiesInRange) {
            enemyPtr->setHP(enemyPtr->getHP() - getDamage());
        }
    }

    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("map/default/Tower_magic.png")) {
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