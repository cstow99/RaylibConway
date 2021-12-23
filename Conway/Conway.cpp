#include "Conway.h"
#include <iostream>

Game::Game() : _window(TEMP_WIDTH, TEMP_HEIGHT, TEMP_FPS, "Conway's Game of Life", FULLSCREEN), _loop(_window) {
	std::cout << "Resolution: " << _window.GetSize().GetX() << "x" << _window.GetSize().GetY()
		<< std::endl;

	init();
}

Game::~Game() {
	exit();
}

void Game::init() {
	_window.Create();
	_loop.BeginLoop();
}

void Game::exit() {
	_window.Destroy();
}