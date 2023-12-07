#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>

class GridMap {
public:
    GridMap(int gridSize, int windowSize, const std::string& mapFile, const std::vector<std::string>& backgroundImageFiles, int selectedBackgroundIndex);
    void draw(sf::RenderWindow& window);
    void handleMouseInput(sf::Event::MouseButtonEvent& mouseEvent);
    void loadMap(const std::string& mapFile);
    void loadBackgrounds(const std::vector<std::string>& backgroundImageFiles);
    std::queue<std::pair<int, int>> checkpoints;
    std::vector<std::vector<int>> mapData;
    void setPosition(sf::Vector2f position);

private:
    int gridSize;
    int windowSize;

    std::vector<sf::Texture> backgroundImageTextures;
    sf::Sprite backgroundImage;
    

    
    
};

#endif
