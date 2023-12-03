#include "enemy-plant.hpp"

PlantEnemy::PlantEnemy(Game* game, std::queue<std::pair<int, int>> checkpoints): Enemy(game, 30, 0.5, 1, 10, 1, checkpoints) { }

PlantEnemy::PlantEnemy(Game* game, std::queue<std::pair<int, int>> checkpoints, float x, float y): Enemy(game, 30, 0.5, 1, 10, 1, checkpoints) {
    setPosition(x, y);
}