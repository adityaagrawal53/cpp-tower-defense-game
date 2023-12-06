#include "enemy-plant.hpp"

PlantEnemy::PlantEnemy(Game* game, std::queue<std::pair<int, int>> checkpoints): Enemy(game, 30, 0.5f, 1, 10, 1.0) { }

PlantEnemy::PlantEnemy(Game* game): Enemy(game, 30, 0.5, 1, 10, 1) { }

PlantEnemy::PlantEnemy(Game* game, float x, float y): Enemy(game, 30, 0.5, 1, 10, 1) {
    setPosition(x, y);
}

void PlantEnemy::draw(sf::RenderWindow& window) {
    sf::Texture texture;

    if(!texture.loadFromFile("")) {
        std::cout << "Could not load from " << "" << std::endl;
        return;
    }

    sf::Sprite enemySprite;
    enemySprite.setTexture(texture);
    enemySprite.setOrigin(enemySprite.getGlobalBounds().width, enemySprite.getGlobalBounds().height);
    enemySprite.setPosition(xPos_, yPos_);
    window.draw(enemySprite);
}