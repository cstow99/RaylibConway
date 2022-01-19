#ifndef CONWAY_HELP_H
#define CONWAY_HELP_H
#include <raylib-cpp.hpp>

class HelpMenu {
public:
	HelpMenu(raylib::Window &window);

	void Init(), Update(), Draw();

	bool HelpMenuShown() { return _showHelpMenu; }

private:
	raylib::Window& _window;

	bool _showHelpMenu; // Toggle if F1 is pressed

	raylib::Rectangle _helpWindow;
};

#endif