#include "Grid.h"
#include "raylib-extra.h"

#include <cassert>

// Cell declarations

Grid::Cell::Cell() : _cellExists(false), _cellColor(DEFAULT_CELL_COLOR) {}

void Grid::Cell::SetColor(Color c_input) {
	_cellColor = c_input;
	_cellExists = true;
}

void Grid::Cell::Remove() { _cellExists = false; }

// Grid declarations

Grid::Grid(Vec2<int> screenPos, Vec2<int> gridSize, int cellSize, int padding)
	: _screenPos(screenPos), _width(gridSize.GetX()), _height(gridSize.GetY()),
	  _cellSize(cellSize), _padding(padding)
{
	assert(gridSize.GetX() > 0 && gridSize.GetY() > 0 && "Grid: Width and/or height is less or equal to 0!");
	assert(cellSize > 0 && "Grid: Cell size is less than 1!");

	_cells.resize(_width * _height);
}

void Grid::SetCell(Vec2<int> pos, Color c) {
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < _width && pos.GetY() < _height &&
			"Grid.SetCell: X and/or Y is out of bounds!");

	_cells[pos.GetY() * _width + pos.GetX()].SetColor(c);
}

void Grid::DrawCell(Vec2<int> pos) const {
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < _width && pos.GetY() < _height &&
		"Grid.SetCell: X and/or Y is out of bounds!");

	Color c_color = _cells[pos.GetY() * _width + pos.GetX()].GetCellColor();
	Vec2<int> topLeft = _screenPos + _padding + (pos * _cellSize);

	raylib::DrawRectangle_Vec2Int(topLeft, Vec2{_cellSize,_cellSize} - _padding, c_color);
}

void Grid::DrawBorder(Color b_color) const {
	raylib::DrawRectangleLines_Vec2Int(_screenPos - (_cellSize / 2), Vec2{_width * _cellSize,_height * _cellSize} + _cellSize,_cellSize / static_cast<float>(4),b_color);
}

void Grid::Draw(bool withBorder) const {
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			DrawCell({ x,y });
		}
	}

	if (withBorder) { DrawBorder(WHITE); }
}