#include "tower.hpp"
#include <iostream>

Tower::Tower(std::string name, int damage, double range, int cost, int damageOverTime): name(name), damage(damage), range(range), cost(cost), damageOverTime(damageOverTime) {}

void Tower::printTowerInfo() const {
    std::cout << "Tower Name: " << name << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Range: " << range << std::endl;
    std::cout << "Cost: " << cost << std::endl;
    std::cout << "Damage Over Time: " << damageOverTime << std::endl;
}

std::string Tower::getName() const {
    return name;
}

void Tower::setName(std::string name) {
    this->name = name;
}

int Tower::getDamage() const {
    return damage;
}

void Tower::setDamage(int damage) {
    this->damage = damage;
}

double Tower::getRange() const {
    return range;
}

void Tower::setRange(double range) {
    this->range = range;
}

int Tower::getCost() const {
    return cost;
}

void Tower::setCost(int cost) {
    this->cost = cost;
}

int Tower::getDamageOverTime() const {
    return damageOverTime;
}

void Tower::setDamageOverTime(int damageOverTime) {
    this->damageOverTime = damageOverTime;
}