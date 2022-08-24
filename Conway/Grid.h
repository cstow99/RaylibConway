/*
	Grid class
	
	Create a grid of cells which then can be used for multiple purposes
*/

#ifndef CONWAY_GRID_H
#define CONWAY_GRID_H
#include "raylib-wrapper.h"

#include <vector>
#include "Vec2.h"

inline static const Color DEFAULT_CELL_COLOR = DARKGRAY;

class Grid {
private:
    class Cell {
    public:
        Cell();
        void SetColor(Color c_input);
        void Remove();

        // Get color of cell
        Color GetCellColor() const { return _cellColor; }

    private:
        bool _cellExists;
        Color _cellColor;
    };

public:
    // No configuration file yet
    /*void LoadConfig() {
        screenPos.SetX(Config::Read("Grid", "x"));
        screenPos.SetY(Config::Read("Grid", "y"));
    }*/

    Grid(Vec2<int> screenPosition, Vec2<int> gridSize, int cellsize, int padding);
    void SetCell(Vec2<int> pos, Color c);
    void SetCenterCell(Color c);

    // Getter functions

    Vec2<int> GetCenterCell() const { return { ((_width - 2) / 2) + 1,((_height - 2) / 2) + 1 }; }
    Vec2<int> GetGridSize() const { return { _width,_height }; }
    Color GetCellColor(Vec2<int> pos) { return _cells[pos.GetY() * _width + pos.GetX()].GetCellColor(); }


    void DrawCell(Vec2<int> pos) const;
    void DrawBorder(Color borderColor) const;
    
    void Draw() const;

private:
    std::vector<Cell> _cells;
    const int _width, _height, _cellSize, _padding;
    Vec2<int> _screenPos;
};

#endif