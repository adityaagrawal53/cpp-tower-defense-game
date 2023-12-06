#include "enemy-fire.hpp"

FireEnemy::FireEnemy(Game* game): Enemy(game, 100, 0.3, 5, 30, 1.0) { }

void FireEnemy::damageOverTime(Tower* tower) {
    // Repeat over time period
    tower->damageTower(5);
}