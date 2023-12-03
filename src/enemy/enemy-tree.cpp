#include "enemy-tree.hpp"

TreeEnemy::TreeEnemy(Game* game, std::queue<Checkpoint> checkpoints): Enemy(game, 100, 0.3, 5, 30, 1, checkpoints) { }

void TreeEnemy::die() {
    game_->getEnemies().push_back(PlantEnemy(game_, getCheckpoints(), getXPos(), getYPos()));
    game_->getEnemies().push_back(PlantEnemy(game_, getCheckpoints(), getXPos() + 3.f, getYPos() + 3.f));
    game_->getEnemies().push_back(PlantEnemy(game_, getCheckpoints(), getXPos() - 3.f, getYPos() - 3.f));
    
    dead = true;
}