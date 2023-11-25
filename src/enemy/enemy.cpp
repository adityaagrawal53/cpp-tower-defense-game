#include "enemy.hpp"

Enemy::Enemy(int HP, float speed, int ATK, int coins, std::queue<Checkpoint> checkpoints): HP_(HP), speed_(speed), ATK_(ATK), coins_(coins), checkpoints_(checkpoints) {
    xPos_ = checkpoints.front().x;
    yPos_ = checkpoints.front().y;
}

int Enemy::getHP() const {
    return HP_;
}

void Enemy::setHP(int amount) {
    HP_ = amount;
    if(HP_ <= 0) {
        die();
    }
}

void Enemy::attack(Tower* tower) {
    tower->damageTower(ATK_);
}

float Enemy::getXPos() const {
    return xPos_;
}

float Enemy::getYPos() const {
    return yPos_;
}

void Enemy::move() {
    if(!checkpoints_.empty()) {
        float xDist = checkpoints_.front().x - xPos_;
        float yDist = checkpoints_.front().y - yPos_;

        float xVel, yVel;

        double theta;

        if(xDist == 0) {
            //arctan of infinity is pi/2
            theta = M_PI / 2;
        } else {
            theta = atan(abs(yDist / xDist));
        }

        //Update velocity
        if(abs(xDist) <= abs(speed_ * cos(theta))) {
            xVel = abs(xDist);
        } else {
            xVel = speed_ * cos(theta);
        }

        if(abs(yDist) <= abs(speed_ * sin(theta))) {
            yVel = abs(yDist);
        } else {
            yVel = speed_ * sin(theta);
        }

        //Move in direction
        if(xDist < 0) {
            xPos_ -= xVel;
        } else {
            xPos_ += xVel;
        }

        if(yDist < 0) {
            yPos_ -= yVel;
        } else {
            yPos_ += yVel;
        }

        //Reached checkpoint
        if(xDist == 0 && yDist == 0) {
            checkpoints_.pop();
        }
    }
}

void Enemy::die() {
    dead = true;
}

std::queue<Checkpoint> Enemy::getCheckpoints() const {
    return checkpoints_;
}