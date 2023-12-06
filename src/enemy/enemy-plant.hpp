#ifndef ENEMY_PLANT_HPP
#define ENEMY_PLANT_HPP

#include "enemy.hpp"

class PlantEnemy : public Enemy {
  public:
    /**
     * \brief Default constructor
    */
    //PlantEnemy(Game* game, std::queue<std::pair<int, int>> checkpoints);
    PlantEnemy(Game* game);
    
    /**
     * \brief Constructor that sets initial position of PlantEnemy to (x, y)
     *        instead of 1st checkpoint.
    */
    //PlantEnemy(Game* game, std::queue<Checkpoint> checkpoints, float x, float y);
    PlantEnemy(Game* game, float x, float y);

    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("")) {
            std::cout << "Could not load PlantEnemy sprite" << std::endl;
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