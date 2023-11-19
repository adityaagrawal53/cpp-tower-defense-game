#include "enemy-tree.hpp"

PlantEnemy::PlantEnemy(std::queue<Checkpoint> checkpoints): Enemy(30, 0.5, 1, 10, checkpoints) { }