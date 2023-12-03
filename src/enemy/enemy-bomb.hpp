#ifndef ENEMY_BOMB_HPP
#define ENEMY_BOMB_HPP

#include "enemy.hpp"

class BombEnemy : public Enemy {
  public:
    BombEnemy(Game* game, std::queue<Checkpoint> checkpoints);

    /**
     * \brief When attacking a Tower, also damage nearby Towers
    */
    virtual void attack();
};

#endif