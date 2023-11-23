#ifndef TOWER_PLANT_HPP
#define TOWER_PLANT_HPP

#include <string>
#include "tower.hpp"

class Water : public Tower {
public:
    Water(std::string name = "Water", int damage = 5, int hp = 20 double range = 4.0, int cost = 15, int damageOverTime = 0);

private:
};

#endif