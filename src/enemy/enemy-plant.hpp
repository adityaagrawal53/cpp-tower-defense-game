#pragma once

#include "enemy.hpp"

class PlantEnemy : public Enemy {
  public:
    PlantEnemy(Game* game, std::queue<Checkpoint> checkpoints);

    virtual void attack();
};