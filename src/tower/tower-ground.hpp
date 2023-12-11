#ifndef TOWER_GROUND_HPP
#define TOWER_GROUND_HPP

#include <string>
#include "tower.hpp"

class Ground : public Tower {
public:
    //Tower with high HP but no attack parameters. Purely defensive.
    //Ground(std::string name = "Ground", int damage = 0, int hp = 500, double range = 0.0, int cost = 15, int damageOverTime = 0);
    Ground(Game* game): Tower(game, "Ground", 0, 500, 0.0, 15, 0, position){};


    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("")) {
            std::cout << "Could not load GroundTower sprite" << std::endl;
            return;
        }

        sf::Sprite towerSprite;
        towerSprite.setTexture(texture);
        towerSprite.setOrigin(towerSprite.getGlobalBounds().width, towerSprite.getGlobalBounds().height);
        towerSprite.setPosition(getPosition().x, getPosition().y);
        window.draw(towerSprite);
    }

private:
};

#endif