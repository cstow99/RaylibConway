// The Conway's Game of Life Algorithm

#ifndef CONWAY_ALGORITHM_H
#define CONWAY_ALGORITHM_H
#include "Grid.h"
#include "Vec2.h"

class C_Algorithm {
public:
	enum GenMode {
		R_PENTONIMO,
		GOSPER_GLIDING_GUN,
		RANDOM
	};

	inline static const Color CELL_COLOR = GOLD;

	C_Algorithm(Grid& grid, Vec2<int> size);

	// Make sure there is only one instance of this class
	C_Algorithm(const C_Algorithm&) = delete;
	C_Algorithm& operator=(const C_Algorithm&) = delete;

	void Clear();
	void Generate(GenMode mode = RANDOM);
	void Draw();

private:
	const int _width, _height;
	int* _output;
	int* _state;

	Grid &_grid;
};

#endif