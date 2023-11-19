#pragma once

#include "enemy.hpp"
#include "enemy-plant.hpp"

class TreeEnemy : public Enemy {
  public:
    TreeEnemy(std::queue<Checkpoint> checkpoints);

    /**
     * \brief When killed, create 3 PlantEnemy enemies.
    */
    virtual void die();
};