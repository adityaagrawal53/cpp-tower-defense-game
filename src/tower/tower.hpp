#ifndef TOWER_HPP
#define TOWER_HPP

#include <string>

class Tower {
public:
    Tower(std::string name, int damage, double range, int cost, int damageOverTime);

    // Method to display tower stats
    void printTowerInfo() const;

    // Methods to set tower stats
    std::string getName() const;
    void setName(std::string name);
    int getDamage() const;
    void setDamage(int damage);
    double getRange() const;
    void setRange(double range);
    int getCost() const;
    void setCost(int cost);
    int getDamageOverTime() const;
    void setDamageOverTime(int damageOverTime);

private:
    std::string name;
    int damage;
    double range;
    int cost;
};

#endif
