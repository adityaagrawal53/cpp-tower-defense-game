#ifndef TOWER_FIRE_HPP
#define TOWER_FIRE_HPP

#include <string>
#include "tower.hpp"

class Fire : public Tower {
public:
    //Tower with higher cost and DoT but lower immediate damage.
    //Fire(std::string name = "Fire", int damage = 5, int hp = 25, double range = 2.0, int cost = 25, int damageOverTime = 5);
    Fire(Game* game): Tower(game, "Fire", 5, 25, 2.0, 25, 5, position){};


    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("map/default/Tower_fire.png")) {
            std::cout << "Could not load FireTower sprite" << std::endl;
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