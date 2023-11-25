#include "enemy-tree.hpp"

PlantEnemy::PlantEnemy(Game* game, std::queue<Checkpoint> checkpoints): Enemy(game, 30, 0.5, 1, 10, checkpoints) { }