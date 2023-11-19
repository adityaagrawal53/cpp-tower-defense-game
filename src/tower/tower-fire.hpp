#ifndef TOWER_PLANT_HPP
#define TOWER_PLANT_HPP

#include <string>
#include "tower.hpp"

class Plant : public Tower {
public:
    Plant(std::string name = "Plant", int damage = 5, double range = 2.0, int cost = 25, int damageOverTime = 5);

private:
};

#endif