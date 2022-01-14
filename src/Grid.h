#ifndef CONWAY_GRID_H
#define CONWAY_GRID_H
#include <raylib-cpp.hpp>

#include <vector>
#include "Vec2.h" // Rather than using Raylib-CPP's Vector2 class, instead this will use a custom Vec2 class which can use templates (for instance, Vec2<int>)

inline static const Color DEFAULT_CELL_COLOR = DARKGRAY;

class Grid {
private:
	class Cell {
	public:
		Cell();
		void SetColor(Color c_input);
		void Remove();

		// Getters

		Color GetCellColor() const { return _cellColor; }

	private:
		bool _cellExists;
		Color _cellColor;
	};

public:
	Grid(Vec2<int> screenPos, Vec2<int> gridSize, int cellSize, int padding);
	void SetCell(Vec2<int> pos, Color c);

	// Getters

	Vec2<int> GetGridSize() const { return {_width,_height}; }
	Color GetCellColor(Vec2<int> pos) { return _cells[pos.GetY() * _width + pos.GetX()].GetCellColor(); }

	// Draw calls

	void DrawCell(Vec2<int> pos) const;
	void DrawBorder(Color b_color) const;

	// Draw grid on to window
	void Draw(bool withBorder = false) const;

private:
	std::vector<Cell> _cells;
	const int _width, _height, _cellSize, _padding;
	Vec2<int> _screenPos;
};

#endif