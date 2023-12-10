#include "enemy.hpp"

/*Enemy::Enemy(Game* game, int HP, float speed, int ATK, int coins, double range, std::queue<std::pair<int, int>> checkpoints): game_(game), HP_(HP), speed_(speed), ATK_(ATK), coins_(coins), range_(range), checkpoints_(checkpoints) {
    //xPos_ = checkpoints.front().x;
    //yPos_ = checkpoints.front().y;
    setPosition(checkpoints_.front().first, checkpoints_.front().second);
}*/

Enemy::Enemy(Game* game, int HP, float speed, int ATK, int coins, double range): game_(game), HP_(HP), speed_(speed), ATK_(ATK), coins_(coins), range_(range), checkpoints_(game->getCheckpoints()) {
    //xPos_ = checkpoints.front().x;
    //yPos_ = checkpoints.front().y;
    setPosition(checkpoints_.front().first, checkpoints_.front().second);
}

/*
Enemy::Enemy(Game* game, const std::string& type) {
    if (type == "p") {        // plant type
        PlantEnemy(*game);
    } else if (type == "b") { // bomb type
        BombEnemy(*game);
    } else if (type == "o") { // boss type
        //will be implemented later 
    } else if (type == "f") { // fire type
        //no
    } else if (type == "g") { // ground type
        //no 
    } else if (type == "m") { // magic type
        //no
    } else if (type == "t") { // tree type
        TreeEnemy(*game);
    } else if (type == "w") { // water type
        //no
    } else { PlantEnemy(*game); }

    setPosition(checkpoints_.front().first, checkpoints_.front().second);
}
*/
void Enemy::setPosition(int x, int y) {
    xPos_ = x;
    yPos_ = y;
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

int Enemy::getXPos() const {
    return checkpoints_.front().first;
}

int Enemy::getYPos() const {
    return checkpoints_.front().second;
}

void Enemy::move() {
    if(!checkpoints_.empty()) {
        std::cout << "checkpoint " << checkpoints_.front().first << " " << checkpoints_.front().second << std::endl;
    }
    
    if(!checkpoints_.empty()) {
        float xDist = checkpoints_.front().first - xPos_;
        float yDist = checkpoints_.front().second - yPos_;

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

std::vector<Tower*> Enemy::getTowersInRange() {
    std::vector<Tower*> inRange = std::vector<Tower*>();
    for(auto t : game_->getTowers()) {
        //get position of tower
        double x = t->getPosition().x;
        double y = t->getPosition().y;
        if(abs(x - xPos_) <= range_ && abs(y - yPos_) <= range_) {
            inRange.push_back(t);
        }
    }
    //Sorting by distance
    float xp = xPos_;
    float yp = yPos_;
    std::sort(inRange.begin(), inRange.end(),
        [xp, yp](const Tower* t1, const Tower* t2) {
            double d1 = sqrt(pow(t1->getPosition().x - xp, 2) + pow(t1->getPosition().y - yp, 2));
            double d2 = sqrt(pow(t2->getPosition().x - xp, 2) + pow(t2->getPosition().y - yp, 2));
            return d1 < d2;
        });
    return inRange;
}

void Enemy::attack() {
    if(!getTowersInRange().empty()) {
        Tower* tar = getTowersInRange().front();
        tar->setHealth(tar->getHealth() - ATK_);
    }
}

void Enemy::die() {
    dead = true;
}

bool Enemy::isDead() const {
    return dead;
}

std::queue<std::pair<int, int>> Enemy::getCheckpoints() const {
    return checkpoints_;
}