#include "Conway.h"
#include <string>

int main() {
	Conway conwayGameOfLife;
	return 0;
}

const std::string pausedText = "PAUSED";

Conway::Conway()
	: _window(_width, _height, "Conway's Game of Life"),

	_grid({ 0,0 }, { ((int)_window.GetSize().GetX() / 8), ((int)_window.GetSize().GetY() / 8) }, 8, 1),
	_gol(_grid, {_grid.GetGridSize().GetX(), _grid.GetGridSize().GetY()}),
	_helpMenu(_window), _paused(false), _nextFrame(false)

{
	init();
}

Conway::~Conway() {
	quit();
}

void Conway::init() {
	_window.SetTargetFPS(15);
	_gol.Generate();
	startAppLoop();
}

void Conway::quit() {
	// Turns out that the window class automatically closes itself. Uncommenting the line below will cause an exception
	// _window.Close(); 
}

void Conway::startAppLoop() { // This is where the app's loop is stored. Executes both update() and draw() for every iteration
	while (!_window.ShouldClose()) {
		update();
		
		BeginDrawing();
		draw();
		EndDrawing();
	}
}

void Conway::update() {
	_helpMenu.Update();

	if (!_helpMenu.HelpMenuShown()) {
		if (IsKeyPressed(KEY_ONE)) { _gol.Generate(); if (_paused) _nextFrame = true; }
		if (IsKeyPressed(KEY_TWO)) { _gol.Generate(_gol.R_PENTONIMO); if (_paused) _nextFrame = true; }
		if (IsKeyPressed(KEY_THREE)) { _gol.Generate(_gol.GOSPER_GLIDING_GUN); if (_paused) _nextFrame = true; }

		if (IsKeyPressed(KEY_P)) { // Pause/Unpause
			if (!_paused) {
				_paused = true;
			} else _paused = false;
		}

		// Draw next frame (only works when paused)
		if (_paused && IsKeyPressed(KEY_F)) { _nextFrame = true; }
	}


//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { _window.SetTargetFPS(_window.GetFPS() + 1); }
//	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) { _window.SetTargetFPS(_window.GetFPS() - 1); }
}

void Conway::drawPauseIcon() {
	raylib::DrawText(pausedText, 5, _window.GetHeight() - 28, 32, BLACK);
	raylib::DrawText(pausedText, 3, _window.GetHeight() - 30, 32, WHITE);
}

void Conway::draw() {
	ClearBackground(BLACK);

	_grid.Draw();

	if (!_paused) {
		if (_nextFrame) _nextFrame = false; // Set nextFrame to false if it's true already since it's only used when paused
		_gol.Draw();
	}
	else {
		drawPauseIcon();
		if (_nextFrame) {
			_gol.Draw();
			_nextFrame = false;
		}
	}


	_helpMenu.Draw();
}