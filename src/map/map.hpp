#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class GridMap {
public:
    GridMap(int gridSize, int windowSize, const std::string& mapFile, const std::vector<std::string>& backgroundImageFiles, int selectedBackgroundIndex);
    void draw(sf::RenderWindow& window);
    void handleMouseInput(sf::Event::MouseButtonEvent& mouseEvent);
    void loadMap(const std::string& mapFile);
    void loadBackgrounds(const std::vector<std::string>& backgroundImageFiles);
    std::vector<std::pair<int, int>> checkpoints;

private:
    int gridSize;
    int windowSize;
    std::vector<std::vector<int>> mapData;
    std::vector<sf::Texture> backgroundImageTextures;
    sf::Sprite backgroundImage;
    

    
    
};

#endif
