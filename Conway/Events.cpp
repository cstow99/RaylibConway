#include "Events.h"

#include "raylib-wrapper.h"

KeyboardEvents::KeyboardEvents(GameOfLife& gol) :

	// Object references go here
	_gol(gol)
{}

void KeyboardEvents::Update() {
	int keyPressed = GetKeyPressed();
	if (raylib::R_KeyPressed(keyPressed))
		process(keyPressed);
}

void KeyboardEvents::process(int key) {
	switch (key) {
	// Clear screen
	case KEY_C:
		_gol.Clear();
		break;

	// Generate (Random)
	case KEY_ONE:
		_gol.Generate();
		break;

	// Generate (R-Pentonimo)
	case KEY_TWO:
		_gol.Generate(_gol.R_PENTONIMO);
		break;

	// Generate (Gosper Gliding Gun)
	case KEY_THREE:
		_gol.Generate(_gol.GOSPER_GLIDING_GUN);
		break;
	}
}