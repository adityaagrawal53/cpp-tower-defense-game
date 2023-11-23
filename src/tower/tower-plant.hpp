#ifndef TOWER_PLANT_HPP
#define TOWER_PLANT_HPP

#include <string>
#include "tower.hpp"

class Plant : public Tower {
public:
    Plant(std::string name = "Plant", int damage = 5, int hp = 25 double range = 2.0, int cost = 10, int damageOverTime = 0);

private:
};

#endif
