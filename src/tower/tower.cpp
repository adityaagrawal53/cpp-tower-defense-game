#include "tower.hpp"
#include <iostream>

Tower::Tower(std::string name, int damage, int hp, double range, int cost, int damageOverTime, TowerPos position): name(name), damage(damage), hp(hp), range(range), cost(cost), damageOverTime(damageOverTime), position(position) {}

void Tower::printTowerInfo() const {
    std::cout << "Tower Name: " << getName() << std::endl;
    std::cout << "Damage: " << getDamage() << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Range: " << getRange() << std::endl;
    std::cout << "Cost: " << getCost() << std::endl;
    std::cout << "Damage Over Time: " << getDamageOverTime() << std::endl;
    std::cout << "Position: (" << getPosition().x << ", " << getPosition().y << ")" << std::endl;
}

TowerPos Tower::getPosition() const {
    return position;
}

void Tower::setPosition(TowerPos position) {
    this->position = position;
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

int Tower::getHealth() const {
    return hp;
}

void Tower::setHealth(int hp) {
    this->hp = hp;
}

void Tower::damageTower(int hp) { 
    this->hp -= hp;
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