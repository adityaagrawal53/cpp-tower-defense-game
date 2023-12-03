#include "enemy-plant.hpp"

PlantEnemy::PlantEnemy(Game* game, std::queue<std::pair<int, int>> checkpoints): Enemy(game, 30, 0.5, 1, 10, 1, checkpoints) { }

<<<<<<< HEAD
PlantEnemy(Game* game) { 
    PlantEnemy(game, game.checkpoints)
}

PlantEnemy::PlantEnemy(Game* game, std::queue<Checkpoint> checkpoints, float x, float y): Enemy(game, 30, 0.5, 1, 10, 1, checkpoints) {
=======
PlantEnemy::PlantEnemy(Game* game, std::queue<std::pair<int, int>> checkpoints, float x, float y): Enemy(game, 30, 0.5, 1, 10, 1, checkpoints) {
>>>>>>> refs/remotes/origin/master
    setPosition(x, y);
}