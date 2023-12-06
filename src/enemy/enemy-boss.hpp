#ifndef ENEMY_BOSS_HPP
#define ENEMY_BOSS_HPP

#include "enemy.hpp"

class BossEnemy : public Enemy {
  public:
    BossEnemy(Game* game);

    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("")) {
            std::cout << "Could not load BossEnemy sprite" << std::endl;
            return;
        }

        sf::Sprite enemySprite;
        enemySprite.setTexture(texture);
        enemySprite.setOrigin(enemySprite.getGlobalBounds().width, enemySprite.getGlobalBounds().height);
        enemySprite.setPosition(xPos_, yPos_);
        window.draw(enemySprite);
    }
};

#endif