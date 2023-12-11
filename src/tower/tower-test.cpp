#include "tower-plant.hpp"
#include <iostream>
#include <cassert>

void testPlant() {
    // Create a game instance for testing
    Game* game;

    // Create a Plant (basic) instance
    Plant plant(game);

    // Test getters with default values
    assert(plant.getName() == "Water");
    assert(plant.getDamage() == 10);
    assert(plant.getHealth() == 25);
    assert(plant.getRange() == 2.0);
    assert(plant.getCost() == 10);
    assert(plant.getDamageOverTime() == 0);

    // Add additional tests if needed for specific implementations


    std::cout << "Plant tests passed successfully!" << std::endl;
}

int main() {
    // Run test
    testPlant();

    return 0;
}