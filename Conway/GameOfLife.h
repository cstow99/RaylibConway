/*
	GameOfLife class
	
	The class where the Conway's Game of Life algorithm is stored
*/

#ifndef CONWAY_GAMEOFLIFE_H
#define CONWAY_GAMEOFLIFE_H
#include "Grid.h"
#include "Vec2.h"

#include <string>

class GameOfLife {
public:
	enum GenMode {
		R_PENTONIMO,
		GOSPER_GLIDING_GUN,
		RANDOM
	};

	inline static const Color CELL_COLOR = GOLD;

public:
	GameOfLife(Grid &grid, Vec2<int> size);

	void Clear();
	void Generate(GenMode mode = RANDOM);
	void Draw();
private:
	const int _width, _height;
	int* _output;
	int* _state;

	Grid& _grid;
};

#endif