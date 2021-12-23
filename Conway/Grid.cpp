#include "Grid.h"
#include <cassert>

// Cell class implementation
Grid::Cell::Cell() : _cellExists(false), _cellColor(DEFAULT_CELL_COLOR) {}

void Grid::Cell::SetColor(Color c_input) {
    _cellColor = c_input;
    _cellExists = true;
}

void Grid::Cell::Remove() { _cellExists = false; }

// Grid class implementation
Grid::Grid(Vec2<int> screenPosition, Vec2<int> gridSize, int cellsize, int gridPadding) :
    _screenPos(screenPosition), _width(gridSize.GetX()), _height(gridSize.GetY()),
    _cellSize(cellsize), _padding(gridPadding)
{
    assert(gridSize.GetX() > 0 && gridSize.GetY() > 0 && "Grid: Width or height is less or equal to 0");
    assert(cellsize > 0 && "Grid: Cell size is smaller than 1");
    _cells.resize(_width * _height);
}

void Grid::SetCell(Vec2<int> pos, Color c) {
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < _width && pos.GetY() < _height &&
        "SetCell: X or Y is out of bounds");
    _cells[pos.GetY() * _width + pos.GetX()].SetColor(c);
}

void Grid::DrawCell(Vec2<int> pos) const {
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < _width && pos.GetY() < _height &&
        "DrawCell: X or Y is out of bounds");

    Color cColor = _cells[pos.GetY() * _width + pos.GetX()].GetCellColor();
    Vec2<int> topLeft = _screenPos + _padding + (pos * _cellSize);

    raylib::R_DrawRectangle(topLeft, Vec2{ _cellSize,_cellSize } - _padding, cColor);
}

void Grid::SetCenterCell(Color c) {
    SetCell(GetCenterCell(), c);
}

void Grid::DrawBorder(Color borderColor) const {
    raylib::R_DrawRectangleLinesEx(_screenPos - (_cellSize / 2), Vec2{ _width * _cellSize,_height * _cellSize } + _cellSize, _cellSize / 4, borderColor);
}

void Grid::Draw() const {
    for (int i = 0; i < _height; i++) {       // Y Coordinate
        for (int j = 0; j < _width; j++) {    // X Coordinate
            DrawCell({ j, i }); // Y goes first, then X. Idk why it's like that
        }
    }
    //DrawBorder(WHITE);
}