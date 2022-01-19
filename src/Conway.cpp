#include "Conway.h"

int main() {
	Conway session;
	return 0;
}

Conway::Conway()
	: _window(_width, _height, "Conway's Game of Life"),

	_grid({ 0,0 }, { ((int)_window.GetSize().GetX() / 8), ((int)_window.GetSize().GetY() / 8) }, 8, 1),
	_gol(_grid, {_grid.GetGridSize().GetX(), _grid.GetGridSize().GetY()})

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
	if (IsKeyPressed(KEY_ONE)) { _gol.Generate(); }
	if (IsKeyPressed(KEY_TWO)) { _gol.Generate(_gol.R_PENTONIMO); }
	if (IsKeyPressed(KEY_THREE)) { _gol.Generate(_gol.GOSPER_GLIDING_GUN); }

//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { _window.SetTargetFPS(_window.GetFPS() + 1); }
//	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) { _window.SetTargetFPS(_window.GetFPS() - 1); }
}

void Conway::drawFPS() {
	raylib::DrawText(std::to_string(_window.GetFPS()) + " FPS", 4, 4, 20, BLACK);
	raylib::DrawText(std::to_string(_window.GetFPS()) + " FPS", 3, 3, 20, WHITE);
}

void Conway::draw() {
	ClearBackground(BLACK);

	_grid.Draw();
	_gol.Draw();

	drawFPS();
}