#include "raylib-wrapper.h"
#include <cassert>

namespace raylib {
	// Window class
	Window::Window(int width, int height, int fps, std::string title, bool fullscreen) : 
		_fullScreen(fullscreen), _width(width), _height(height), _fps(fps), _title(title)
	{}
	Window::~Window() {}
	void Window::Create() { // Create the window
		InitWindow(_width, _height, _title.c_str());
		SetTargetFPS(_fps);

		if (_fullScreen)
			WindowToggleFullscreen();
	}
	void Window::Destroy() { // Destroy the window
		CloseWindow();
	}
	void Window::WindowToggleFullscreen() {
		if (!IsWindowFullscreen()) {
			SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
			ToggleFullscreen();
		} else {
			SetWindowSize(_width, _height);
			ToggleFullscreen();
		}
	}
	bool Window::ShouldClose() { // Is the window closing?
		return WindowShouldClose();
	}
	void Window::GetHandle() {
		GetWindowHandle();
	}

	Vec2<int> Window::GetSize() { // X = Width, Y = Height
		return {_width, _height};
	}

	// Drawing functions

	void R_BeginDrawing() {
		BeginDrawing();
	}

	void R_EndDrawing() {
		EndDrawing();
	}

	void R_ClearBackground(Color c) {
		ClearBackground(c);
	}

	void R_DrawText(std::string text, Vec2<int> pos, int size, Color color) {
		DrawText(text.c_str(), pos.GetX(), pos.GetY(), size, color);
	}

	void R_DrawRectangle(Vec2<int> pos, Vec2<int> size, Color color) {
		DrawRectangle(pos.GetX(), pos.GetY(), size.GetX(), size.GetY(), color);
	}

	void R_DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> size, float lineThickness, Color color) {
		assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
			pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight() &&
			"raylib::DrawRectangleLinesEx: Attempted to draw outside of screen");

		DrawRectangleLinesEx({ (float)pos.GetX(),(float)pos.GetY(),(float)size.GetX(),(float)size.GetY() }, lineThickness, color);
	}

	void R_DrawFPS(Vec2<int> pos) {
		DrawFPS(pos.GetX(), pos.GetY());
	}

	// Keyboard/Mouse events
	bool R_KeyPressed(int key) {
		return IsKeyPressed(key);
	}


	// Misc

	int R_RandomNumber(int min, int max) {
		return GetRandomValue(min, max);
	}
}