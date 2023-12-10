#include "enemy-tree.hpp"

TreeEnemy::TreeEnemy(Game* game): Enemy(game, 100, 3.f, 5, 30, 1) { }

void TreeEnemy::die() {
    game_->getEnemies().push_back(new PlantEnemy(game_, getXPos(), getYPos()));
    game_->getEnemies().push_back(new PlantEnemy(game_, getXPos() + 3.f, getYPos() + 3.f));
    game_->getEnemies().push_back(new PlantEnemy(game_, getXPos() - 3.f, getYPos() - 3.f));
    
    dead = true;
}