#ifndef CONWAY_MAIN_H
#define CONWAY_MAIN_H
#include "raylib-wrapper.h"

#include "Loop.h"

// I'm going to eventually setup a config file to take care of these
// Resolution must be divisible by 8 (e.g. 640x480)
#define TEMP_WIDTH 1280
#define TEMP_HEIGHT 1024
#define TEMP_FPS 15
#define FULLSCREEN false

class Game {
public:
	Game();
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

private:
	void init();
	void exit();

	raylib::Window _window;
	Loop _loop;
};

#endif