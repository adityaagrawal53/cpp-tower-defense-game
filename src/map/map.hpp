#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

class GridMap {
public:
    GridMap(int gridSize, int rows, int cols, const std::string& backgroundImageFile, const std::string& mapFile);

    void draw(sf::RenderWindow& window);
    void handleMouseInput(sf::Event& event);

private:
    int gridSize;
    int rows;
    int cols;
    std::vector<std::vector<bool>> grid;
    sf::Texture backgroundImageTexture;
    sf::Sprite backgroundImageSprite;

    void loadMapFromFile(const std::string& mapFile);
};

