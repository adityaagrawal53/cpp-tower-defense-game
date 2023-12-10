#ifndef TOWER_HPP
#define TOWER_HPP


class Game;

class Tower;
class Enemy;



#include <string>
#include "../game/game.hpp"
#include "../enemy/enemy.hpp"

struct TowerPos {
    double x;
    double y;
};

class Tower {
public:
    Tower(Game* game, std::string name, int damage, int hp, double range, int cost, int damageOverTime, TowerPos position);

    // Method to display tower stats
    void printTowerInfo() const;

    // Methods to set and get tower position
    TowerPos getPosition() const;
    void setPosition(TowerPos position);

    // Methods to set tower stats
    std::string getName() const;
    void setName(std::string name);
    int getDamage() const;
    void setDamage(int damage);
    int getHealth() const;
    void setHealth(int hp);
    double getRange() const;
    void setRange(double range);
    int getCost() const;
    void setCost(int cost);
    int getDamageOverTime() const;
    void setDamageOverTime(int damageOverTime);

    //Attack implementation
    std::vector<Enemy*> getEnemiesInRange();
    virtual void attack();

    //Draw
    virtual void draw(sf::RenderWindow& window) = 0;

private:
    std::string name;
    int damage;
    double range;
    int hp;
    int cost;
    int damageOverTime;

    Game* game;

    TowerPos position;
};

#endif
