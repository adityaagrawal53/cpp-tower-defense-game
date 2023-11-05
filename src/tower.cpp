#include "tower.hpp"
#include <iostream>

Tower::Tower(std::string name, int damage, double range, int cost) : name(name), damage(damage), range(range), cost(cost) {}

void Tower::printTowerInfo() const {
    std::cout << "Tower Name: " << name << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Range: " << range << std::endl;
    std::cout << "Cost: " << cost << std::endl;
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