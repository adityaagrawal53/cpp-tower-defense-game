#ifndef ENEMY_FIRE_HPP
#define ENEMY_FIRE_HPP

#include "enemy.hpp"

class FireEnemy : public Enemy {
  public:
    FireEnemy(Game* game, std::queue<Checkpoint> checkpoints);

    /**
     * \brief Deal damage over time
    */
    void damageOverTime(Tower* tower);
};

#endif