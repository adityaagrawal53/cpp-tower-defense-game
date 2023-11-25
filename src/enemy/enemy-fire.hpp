#pragma once

#include "enemy.hpp"

class FireEnemy : public Enemy {
  public:
    FireEnemy(Game* game, std::queue<Checkpoint> checkpoints);

    /**
     * \brief Deal damage over time
    */
    void damageOverTime(Tower* tower);
};