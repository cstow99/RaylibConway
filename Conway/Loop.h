/*
	Loop class
	
	Sets up the application loop
*/

#ifndef CONWAY_LOOP_H
#define CONWAY_LOOP_H
#include "raylib-wrapper.h"

#include "Events.h"
#include "Gui.h"
#include "Grid.h"
#include "GameOfLife.h"


class Loop {
public:
	Loop(raylib::Window &window);
	~Loop();

	void BeginLoop();

private:
	void init(), update(), draw();

	raylib::Window& _window;
	
	KeyboardEvents _kEvents;
	// Place game's objects here

	Grid _grid;
	GameOfLife _gol;

	Gui _gui;
};

#endif
