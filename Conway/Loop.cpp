#include "Loop.h"
Loop::Loop(raylib::Window& window) : _window(window), _gui(_window.GetSize()),

// Objects get initialised here
_grid({ 0, 0 }, {(_window.GetSize().GetX() / 8), (_window.GetSize().GetY() / 8)}, 8, 0),
_gol(_grid, {_grid.GetGridSize().GetX(), _grid.GetGridSize().GetY()}),

_kEvents(_gol)
{}
Loop::~Loop() {}

// Initialise before the loop begins
void Loop::init() {
	_gol.Generate();
}

void Loop::BeginLoop() {
	init();
	while (!_window.ShouldClose()) {
		update();
		draw();
	}
}

void Loop::update() {
	_kEvents.Update();
}

void Loop::draw() {
	raylib::R_BeginDrawing();	
	_grid.Draw();
	_gol.Draw();

	
	// Gui is usually drawn last
	_gui.Draw();
	raylib::R_EndDrawing();
}