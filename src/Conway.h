// Yes, I still use include guards!
#ifndef CONWAY_H
#define CONWAY_H
#include "Help.h"
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

	bool GetPausedState() { return _paused; }

private:
	bool _paused, _nextFrame; // nextFrame variable is only used when simulation is paused
	const int _width = 1280, _height = 1024; // Change the width and height here. Must be divisible by 8! (e.g. 640x480)
	void init(), quit(), startAppLoop(), update(), draw(), drawPauseIcon();

	raylib::Window _window;

	Grid _grid;
	C_Algorithm _gol;
	HelpMenu _helpMenu;
};

#endif