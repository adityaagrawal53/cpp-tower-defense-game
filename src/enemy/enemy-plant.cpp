#include "enemy-plant.hpp"

PlantEnemy::PlantEnemy(Game* game): Enemy(game, 30, 5.f, 1, 10, 1) { }

PlantEnemy::PlantEnemy(Game* game, float x, float y): Enemy(game, 30, 0.5, 1, 10, 1) {
    setPosition(x, y);
}