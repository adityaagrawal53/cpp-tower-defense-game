#ifndef ENEMY_TREE_HPP
#define ENEMY_TREE_HPP

#include "enemy.hpp"
#include "enemy-plant.hpp"

class TreeEnemy : public Enemy {
  public:
    TreeEnemy(Game* game);

    /**
     * \brief When killed, create 3 PlantEnemy enemies.
    */
    virtual void die();

    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("images/angry-man.png")) {
            std::cout << "Could not load TreeEnemy sprite" << std::endl;
            return;
        }

        //sf::CircleShape enemySprite(15.f);
        //enemySprite.setFillColor(sf::Color::Green);
        sf::Sprite enemySprite;
        enemySprite.setTexture(texture);
        enemySprite.setScale(0.2, 0.2);
        enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
        enemySprite.setPosition(xPos_, yPos_);
        window.draw(enemySprite);
    }
};

#endif