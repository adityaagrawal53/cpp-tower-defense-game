

#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu(sf::RenderWindow& window);
    void draw();
    int handleInput();

    sf::RenderWindow& window;

    // Background
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    // Buttons
    sf::Texture startTexture;
    sf::Sprite startButton;
    sf::Texture quitTexture;
    sf::Sprite quitButton;
};
