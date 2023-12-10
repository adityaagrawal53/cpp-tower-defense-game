#include "tower.hpp"
#include <iostream>
#include <chrono>   //C++ timer utilities to keep track of time in DoT (Damage over Time)
#include <thread>   //Allows for pausing of the Tower thread in DoT implementation

/*
The basic tower class, provides a template for subclasses to fill in stats
The current 5 subclasses include Plant, Water, Fire, Ground, and Magic
Plant is the basic tower
Water is the long range tower
Fire has DoT
Ground is purely defensive with high HP and no attack
Magic attacks all enemies within range
*/

Tower::Tower(Game* game, std::string name, int damage, int hp, double range, int cost, int damageOverTime, TowerPos position): game(game), name(name), damage(damage), hp(hp), range(range), cost(cost), damageOverTime(damageOverTime), position(position) {}

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

std::vector<Enemy*> Tower::getEnemiesInRange() {
    std::vector<Enemy*> inRange = std::vector<Enemy*>();
    for(auto t : game->getEnemies()) {
        //get position of enemy
        double x = t->getYPos();
        double y = t->getXPos();
        if(abs(x - position.x) <= range && abs(y - position.y) <= range) {
            inRange.push_back(t);
        }
    }

    //Sorting by distance
    double xp = position.x;
    double yp = position.y;
    std::sort(inRange.begin(), inRange.end(),
        [xp, yp](Enemy* t1, Enemy* t2) {
            double d1 = sqrt(pow(t1->getXPos() - xp, 2) + pow(t1->getYPos() - yp, 2));
            double d2 = sqrt(pow(t2->getXPos() - xp, 2) + pow(t2->getYPos() - yp, 2));
            return d1 < d2;
        });
    return inRange;
}

void Tower::attack() {
    // Get all enemies in range
    std::vector<Enemy*> enemiesInRange = getEnemiesInRange();

    // Apply immediate damage to the closest enemy
    if (!enemiesInRange.empty()) {
        Enemy* target = enemiesInRange.front();
        target->setHP(target->getHP() - damage);
    }

    // Apply DoT if present
    for (auto& enemy : enemiesInRange) {
        int totalTicks = 5; // Dot ticks for 5 seconds
        int tickDamage = damageOverTime; // Adjust the damage per tick as needed

        // Apply DoT at 1 tick per second
        for (int i = 0; i < totalTicks; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            enemy->setHP(enemy->getHP() - tickDamage);
        }
    }

}