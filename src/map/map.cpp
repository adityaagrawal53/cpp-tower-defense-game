#include "map.hpp"

GridMap::GridMap(int gridSize, int rows, int cols) : gridSize(gridSize), rows(rows), cols(cols) {
    grid.resize(rows, std::vector<bool>(cols, false));
}

void GridMap::draw(sf::RenderWindow& window) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sf::RectangleShape cell(sf::Vector2f(gridSize, gridSize));
            cell.setPosition(j * gridSize, i * gridSize);
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::Black);
            cell.setFillColor(grid[i][j] ? sf::Color::Green : sf::Color::White);
            window.draw(cell);
        }
    }
}

void GridMap::handleMouseInput(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        int x = event.mouseButton.x / gridSize;
        int y = event.mouseButton.y / gridSize;
        if (x >= 0 && x < cols && y >= 0 && y < rows) {
            grid[y][x] = !grid[y][x];
        }
    }
}

