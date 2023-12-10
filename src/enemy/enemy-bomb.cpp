#include "enemy-bomb.hpp"

BombEnemy::BombEnemy(Game* game): Enemy(game, 30, 0.3, 3, 15, 0.6) { }

void BombEnemy::attack() {
    if(!getTowersInRange().empty()) {
        TowerPos p = getTowersInRange().front()->getPosition();
        std::vector<Tower*> tars;
        for(auto t : game_->getTowers()) {
            // Radius
            double r = 1;
            // Get position of nearby towers in a 1-tile radius
            if(abs(t->getPosition().x - p.x) <= r && abs(t->getPosition().y - p.y) <= r) {
                tars.push_back(t);
            }
        }
        for(auto tar : tars) {
            //Damage nearby towers (1-tile radius)
            tar->setHealth(tar->getHealth() - ATK_);
        }
    }
}