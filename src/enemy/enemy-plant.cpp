#include "enemy-plant.hpp"

PlantEnemy::PlantEnemy(Game* game, std::queue<std::pair<int, int>> checkpoints): Enemy(game, 30, 0.5f, 1, 10, 1.0, checkpoints) { }

PlantEnemy::PlantEnemy(Game* game): Enemy(game, 30, 0.5, 1, 10, 1, game->getMap().checkpoints) { }

PlantEnemy::PlantEnemy(Game* game, std::queue<Checkpoint> checkpoints, float x, float y): Enemy(game, 30, 0.5, 1, 10, 1, checkpoints) {
    setPosition(x, y);
}