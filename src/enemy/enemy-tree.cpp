#include "enemy-tree.hpp"

TreeEnemy::TreeEnemy(std::queue<Checkpoint> checkpoints): Enemy(100, 0.3, 5, 30, checkpoints) { }

void TreeEnemy::die() {
    /*
    PlantEnemy(getCheckpoints());
    PlantEnemy(getCheckpoints());
    PlantEnemy(getCheckpoints());
    */
    dead = true;
}