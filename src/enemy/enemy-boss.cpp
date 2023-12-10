#include "enemy-boss.hpp"

BossEnemy::BossEnemy(Game* game): Enemy(game, 1000, 1, 10, 100, 0.5) { }

void BossEnemy::attack() {
    //Executes when there is a tower in range
    if(!getTowersInRange().empty()) {
        Tower* tar = getTowersInRange().front();
        tar->setHealth(0);
    }
}