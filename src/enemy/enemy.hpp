#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <queue>
#include <vector>
#include <string>
#include <math.h>           //Trigonometric functions
#include <iostream>

//Forward declaration to avoid circular dependency
class Game;

class Tower;

#include "../game/game.hpp"
#include "../tower/tower.hpp"

/**
 * \brief class Enemy is an abstract class that describes an enemy
 * 
 * Each `Enemy` has an amount of HP(int), movement speed(double), attack(int), and range(double).
 * When destroyed, they give a certain amount of coins.
 * 
 * They move from checkpoint(pair<int, int>) to checkpoint in a straight line until they reach the exit.
*/

class Enemy {
  public:
    /**
     * \brief Enemy moves between checkpoints in a straight line
     * Each checkpoint is associated with a coordinate(pair of int)
     * and a pause time(int) which determines how long it stays at that point.
    */
    
    /**
     * \brief Constructs a new Enemy object
     * 
     * \param game  what game it is in (to gain access to other Enemys and Towers)
     * \param HP    enemy health
     * \param speed enemy speed (how fast it moves between checkpoints)
     * \param ATK   enemy attack (how much damage it can deal)
     * \param coins how many coins enemy gives when destroyed
     * \param range detection radius of Enemy
    */
    Enemy(Game* game, int HP, float speed, int ATK, int coins, double range);

    /**
     * \brief Sets position of Enemy to (x, y)
     * 
     * \param x x-coordinate of Enemy
     * \param y y-coordinate of Enemy
    */
    void setPosition(int x, int y);

    /**
     * \brief Returns the Enemy's HP as an integer.
     * 
     * \return Enemy's HP as an integer
    */
    int getHP() const;

    /**
     * \brief Changes the Enemy HP to a certain value.
     *        If HP is set to 0 or less, dies.
     * 
     * \param amount New current HP
    */
    void setHP(int amount);

    /**
     * \brief Returns the Enemy's position as a float.
     * 
     * \return Enemy's position as a float.
    */
    int getXPos() const;
    int getYPos() const;

    /**
     * \brief Moves Enemy.
    */
    void move();
    
    /**
     * \brief Returns a vector of Towers that are in Enemy range.
     * 
     * \return Vector of Towers.
    */
    std::vector<Tower*> getTowersInRange();

    /**
     * \brief Attack a nearby tower(s) (closest Tower by default)
    */
    virtual void attack();

    /**
     * \brief Do something when the enemy dies (sets `dead` to true by default).
    */
    virtual void die();

    /**
     * \brief Checks if Enemy is dead.
     * 
     * \return true if Enemy is dead
     *         false otherwise
    */
    bool isDead() const;

    /**
     * \brief Checks if Enemy has reached its destination. If it did, remove 1 Life Point seal.
     * 
     * \return true if Enemy reached the end
     *         false otherwise
    */
    bool reachedDestination() const;

    /**
     * \brief Returns the Enemy's current Checkpoint list.
     * 
     * \return Enemy's Checkpoint list.
    */
    std::queue<std::pair<int, int>> getCheckpoints() const;

    /**
     * \brief Draws Enemy
     * 
     * \param window Window where Enemy will be drawn 
    */
    virtual void draw(sf::RenderWindow& window) = 0;


  protected:
    int HP_;
    float speed_;
    int ATK_;
    int coins_;
    double range_;
    float xPos_, yPos_;
    std::queue<std::pair<int, int>> checkpoints_;

    Game* game_;
  
    bool dead = false;
};

#endif