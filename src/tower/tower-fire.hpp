#ifndef TOWER_PLANT_HPP
#define TOWER_PLANT_HPP

#include <string>
#include "tower.hpp"

class Fire : public Tower {
public:
    Fire(std::string name = "Fire", int damage = 5, int hp = 25 double range = 2.0, int cost = 25, int damageOverTime = 5);

private:
};

#endif