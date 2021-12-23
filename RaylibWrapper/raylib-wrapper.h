#ifndef CPP_RAYLIB_H
#define CPP_RAYLIB_H
extern "C" {
#include <raylib.h>
}
#include "Vec2.h"

#include <string>

namespace raylib {
	// Window class
	class Window {
	public:
		Window(int width, int height, int fps, std::string title, bool fullscreen = false); // Constructor
		~Window(); // Destructor
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		void Create();
		void Destroy();
		void WindowToggleFullscreen();
		bool ShouldClose();

		// Getter functions

		void GetHandle();
		Vec2<int> GetSize();

	private:
		bool _fullScreen;
		const int _width, _height, _fps;
		const std::string _title;
	};

	// Drawing functions
	extern void R_BeginDrawing(); // Begin drawing
	extern void R_EndDrawing(); // End drawing
	extern void R_ClearBackground(Color c); // Clear background and fill with inputted color
	extern void R_DrawText(std::string text, Vec2<int> pos, int size, Color color); // Draw text on to screen
	extern void R_DrawRectangle(Vec2<int> pos, Vec2<int> size, Color color); // Draw a rectangle on the screen
	extern void R_DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> size, float lineThickness, Color color);
	extern void R_DrawFPS(Vec2<int> pos);

	// Keyboard/Mouse Event functions
	extern bool R_KeyPressed(int key);

	// Misc functions
	extern int R_RandomNumber(int min, int max);
}
#endif