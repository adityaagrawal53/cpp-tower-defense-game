#include "enemy-tree.hpp"

TreeEnemy::TreeEnemy(Game* game, std::queue<Checkpoint> checkpoints): Enemy(game, 100, 0.3, 5, 30, checkpoints) { }

void TreeEnemy::die() {
    game_->getEnemies().push_back(PlantEnemy(game_, getCheckpoints()));
    game_->getEnemies().push_back(PlantEnemy(game_, getCheckpoints()));
    game_->getEnemies().push_back(PlantEnemy(game_, getCheckpoints()));
    
    dead = true;
}