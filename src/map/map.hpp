#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include "sidemenu.cpp"



class GridMap {
public:
    GridMap(int gridSize, int windowSize, const std::string& mapFile, const std::vector<std::string>& backgroundImageFiles, int selectedBackgroundIndex);
    //draw the gridmap itself
    void draw(sf::RenderWindow& window);
    //Register mouse clicks on the grids and act accordingly
    void handleMouseInput(sf::Event::MouseButtonEvent& mouseEvent);
    //Read the text file that contains the map layout and enemy path
    void loadMap(const std::string& mapFile);
    //Browse through the list of maps and draw the correct map according to the text file
    void loadBackgrounds(const std::vector<std::string>& backgroundImageFiles);
    //coordinates for enemy path
    std::queue<std::pair<int, int>> checkpoints;
    //2d vector of map layout data
    std::vector<std::vector<int>> mapData;
    //set position of the map to arrange the sidemenu
    void setPosition(sf::Vector2f position);

private:
    int gridSize;
    int windowSize;

    std::vector<sf::Texture> backgroundImageTextures;
    sf::Sprite backgroundImage;
    

    
    
};

#endif
