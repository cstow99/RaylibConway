// Yes, I still use include guards!
#ifndef CONWAY_H
#define CONWAY_H
#include "Grid.h"
#include "C_Algorithm.h"

#include <raylib-cpp.hpp>

class Conway
{
public:
	Conway();

	// Ensure that there is only one instance of this program at a time!
	Conway(const Conway&) = delete;
	Conway& operator=(const Conway&) = delete;

	~Conway();

private:
	const int _width = 640, _height = 480; // Change the width and height here. Must be divisible by 8! (e.g. 640x480)
	void init(), quit(), startAppLoop(), update(), draw(), drawFPS();

	raylib::Window _window;

	Grid _grid;
	C_Algorithm _gol;
};

#endif