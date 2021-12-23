#include "GameOfLife.h"
#include "raylib-wrapper.h"

// Added this to avoid the 'memset was not declared in this scope' error in some compilers
#include <cstring>

GameOfLife::GameOfLife(Grid& grid, Vec2<int> size) : _grid(grid),
	_width(size.GetX()), _height(size.GetY()),
	_output(new int[_width * _height]),
	_state(new int[_width * _height])
{
	memset(_output, 0, _width * _height * sizeof(int));
	memset(_state, 0, _width * _height * sizeof(int));
}

void GameOfLife::Clear() {
	for (int i = 0; i < _width * _height; i++) {
		_state[i] = 0;
	}
}

void GameOfLife::Generate(GenMode mode) {
	Clear();
	auto set = [&](int x, int y, std::string s) {
		int p = 0;
		for (auto c : s) {
			_state[y * _width + x + p] = c == '#' ? 1 : 0;
			p++;
		}
	};

	// Default is random
	switch (mode) {
	case R_PENTONIMO:
		set(40, 20, "..##.");
		set(40, 21, ".##..");
		set(40, 22, "..#..");
		break;

	case GOSPER_GLIDING_GUN:
		set(10, 20, "........................#............");
		set(10, 21, "......................#.#............");
		set(10, 22, "............##......##............##.");
		set(10, 23, "...........#...#....##............##.");
		set(10, 24, "##........#.....#...##...............");
		set(10, 25, "##........#...#.##....#.#............");
		set(10, 26, "..........#.....#.......#............");
		set(10, 27, "...........#...#.....................");
		set(10, 28, "............##.......................");
		break;

	case RANDOM:
	default:
		for (int i = 0; i < _width * _height; i++) {
			_state[i] = rand() % 2;
		}
	}
}

void GameOfLife::Draw() {
	auto cell = [&](int x, int y) {
		return _output[y * _width + x];
	};

	// Store output state
	for (int i = 0; i < _width * _height; i++)
		_output[i] = _state[i];

	for(int x = 0; x < _width; x++)
		for (int y = 0; y < _height; y++) {
			int neighbours = cell(x - 1, y - 1) + cell(x - 0, y - 1) + cell(x + 1, y - 1) +		// North-West, North, North-East
							 cell(x - 1, y + 0) + 0 + cell(x + 1, y + 0) +						// Centre-West, Centre, Centre-East
							 cell(x - 1, y + 1) + cell(x + 0, y + 1) + cell(x + 1, y + 1);		// South-West, South, South-East

			if (cell(x, y) == 1)
				_state[y * _width + x] = neighbours == 2 || neighbours == 3;
			else
				_state[y * _width + x] = neighbours == 3;

			if (cell(x, y) == 1)
				_grid.SetCell({ x, y }, CELL_COLOR); // Alive
			else
				_grid.SetCell({ x, y }, DEFAULT_CELL_COLOR); // Dead
		}
}