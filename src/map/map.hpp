#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>

class GridMap {
public:
    GridMap(int gridSize, int rows, int cols, const std::vector<std::string>& backgroundImageFiles, const std::string& mapFile, const std::vector<std::string>& towerImageFiles);

    void draw(sf::RenderWindow& window);
    void handleMouseInput(sf::Event& event);

private:
    int gridSize;
    int rows;
    int cols;
    std::vector<std::vector<bool>> grid;
    std::vector<sf::Texture> backgroundTextures;
    sf::Sprite backgroundImageSprite;
    std::vector<sf::Texture> towerTextures;
    sf::Sprite towerSprite;

    void loadMapFromFile(const std::string& mapFile);
    void updateGridImage(int x, int y);
    void updateBackgroundImage();
};
