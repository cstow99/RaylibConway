#ifndef CONWAY_GUI_H
#define CONWAY_GUI_H
#include "Vec2.h"

class Gui {
public:
	Gui(Vec2<int> windowSize);

	void Draw();

private:
	const int _width, _height;
};

#endif