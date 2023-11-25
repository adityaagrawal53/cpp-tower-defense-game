#include "enemy-fire.hpp"

FireEnemy::FireEnemy(Game* game, std::queue<Checkpoint> checkpoints): Enemy(game, 100, 0.3, 5, 30, checkpoints) { }

void FireEnemy::damageOverTime(Tower* tower) {
    // Repeat over time period
    tower->damageTower(5);
}