#include "Gui.h"

#include "raylib-wrapper.h"
#include <string>

Gui::Gui(Vec2<int> windowSize) : _width(windowSize.GetX()), _height(windowSize.GetY()) {

}

void drawTitle() {
	std::string msg = "Conway's Game of Life\nPorted to Raylib by ViperSLM";
	// Emulating a drop shadow effect
	raylib::R_DrawText(msg, { 5, 5 }, 20, BLACK);
	raylib::R_DrawText(msg, { 3, 3 }, 20, RAYWHITE);
}

void Gui::Draw() {
	drawTitle();

	raylib::R_DrawFPS({ 3,_height - 20 });
}