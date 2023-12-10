
#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu(sf::RenderWindow& window);
    void draw();
    int handleInput();
private:
    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Texture startTexture;
    sf::Sprite startButton;
    sf::Texture quitTexture;
    sf::Sprite quitButton;


    float startButtonScale;
    float quitButtonScale;
};
