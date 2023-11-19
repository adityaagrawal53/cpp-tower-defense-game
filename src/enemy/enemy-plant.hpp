#pragma once

#include "enemy.hpp"

class PlantEnemy : public Enemy {
  public:
    PlantEnemy(std::queue<Checkpoint> checkpoints);
};