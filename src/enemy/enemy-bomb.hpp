#ifndef ENEMY_BOMB_HPP
#define ENEMY_BOMB_HPP

#include "enemy.hpp"

class BombEnemy : public Enemy {
  public:
    BombEnemy(Game* game);

    /**
     * \brief When attacking a Tower, also damage nearby Towers
    */
    virtual void attack();

    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("")) {
            std::cout << "Could not load BombEnemy sprite" << std::endl;
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