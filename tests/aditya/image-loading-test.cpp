#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Image Example");

    // Load an image
    sf::Texture texture;
    if (!texture.loadFromFile("images/angry-man.png")) {
        // Handle error if image loading fails
        return EXIT_FAILURE;
    }

    // Create a sprite and set its texture
    sf::Sprite sprite(texture);

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Display the contents of the window
        window.display();
    }

    return EXIT_SUCCESS;
}
