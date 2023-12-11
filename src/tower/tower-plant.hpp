#ifndef TOWER_PLANT_HPP
#define TOWER_PLANT_HPP

#include <string>
#include "tower.hpp"

class Plant : public Tower {
public:
    //The basic tower for our game, low cost, medium damage, medium range, and no DoT
    //Plant(std::string name = "Plant", int damage = 10, int hp = 25, double range = 2.0, int cost = 10, int damageOverTime = 0);
    Plant(Game* game): Tower(game, "Water", 10, 25, 2.0, 10, 0, position){};


    void draw(sf::RenderWindow& window) {
        sf::Texture texture;

        if(!texture.loadFromFile("map/default/Tower_plant.png")) {
            std::cout << "Could not load PlantTower sprite" << std::endl;
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
