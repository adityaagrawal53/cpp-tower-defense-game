#pragma once

#include <queue>
#include <string>

/**
 * \brief class Checkpoint determines how the enemy should move
 * 
 * \param x, y coordinates of checkpoint
 * \param t how long should Enemy stay at checkpoint
*/
struct Checkpoint {
    double x;
    double y;
    int t;              //TODO: implement waiting mechanism
};

/**
 * \brief class Enemy is an abstract class that describes an enemy
 * 
 * Each `Enemy` has an amount of HP(int), movement speed(double), and attack(int).
 * When destroyed, they give a
 * 
 * They move from checkpoint(pair<int, int>) to checkpoint in a straight line until they reach the exit.
 * 
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
     * \param HP enemy health
     * \param speed enemy speed (how fast it moves between checkpoints)
     * \param ATK enemy attack (how much damage it can deal)
     * \param XP enemy XP worth (how much XP enemy gives when destroyed)
    */
    Enemy(int HP, float speed, int ATK, int XP);

    /**
     * \brief Virtual destroyer
    */
    virtual ~Enemy() {};

    /**
     * \brief Returns the Enemy's HP as an integer.
     * 
     * \return Enemy's HP as an integer
    */
    int GetHP() const;

    /**
     * \brief Attack a nearby tower
     * 
     * TODO: Define tower
    */
    //void attack();

  private:
    int HP_;
    float speed_;
    int ATK_;
    std::queue<Checkpoint> checkpoints_;
};
