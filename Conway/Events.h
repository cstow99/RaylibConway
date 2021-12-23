#ifndef CONWAY_EVENTS_H
#define CONWAY_EVENTS_H

#include "GameOfLife.h"


// Mouse & Keyboard Events
class KeyboardEvents {
public:
	KeyboardEvents(GameOfLife &gol);

	void Update();

private:
	void process(int key);

	// Objects go here ( Must be a reference! (e.g Object &object;) )
	GameOfLife& _gol;
};

#endif