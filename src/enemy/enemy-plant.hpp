#ifndef ENEMY_PLANT_HPP
#define ENEMY_PLANT_HPP

#include "enemy.hpp"

class PlantEnemy : public Enemy {
  public:
    /**
     * \brief Default constructor
    */
    PlantEnemy(Game* game, std::queue<std::pair<int, int>> checkpoints);
    
    /**
     * \brief Constructor that sets initial position of PlantEnemy to (x, y)
     *        instead of 1st checkpoint.
    */
    PlantEnemy(Game* game, std::queue<std::pair<int, int>> checkpoints, float x, float y);
};

#endif