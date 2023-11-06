#include <SFML/Graphics.hpp>
#include <vector>

class GridMap {
public:
    GridMap(int gridSize, int rows, int cols);

    void draw(sf::RenderWindow& window) ;
       

    void handleMouseInput(sf::Event& event);
      
private:
    int gridSize;
    int rows;
    int cols;
    std::vector<std::vector<bool>> grid;
};

