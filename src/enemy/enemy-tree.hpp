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
};

#endif