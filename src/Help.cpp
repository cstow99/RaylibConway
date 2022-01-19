#include "Help.h"

HelpMenu::HelpMenu(raylib::Window& window)
	: _window(window),
	_showHelpMenu(false)
{
	Init();
}

void HelpMenu::Init() {
	_helpWindow.SetSize(_window.GetSize());
}

void HelpMenu::Update() {
	if (IsKeyPressed(KEY_F1)) {
		if (!_showHelpMenu) {
			_showHelpMenu = true;
		}
		else {
			_showHelpMenu = false;
		}
	}
}

void HelpMenu::Draw() {
	if (_showHelpMenu) {
		_helpWindow.Draw({ 0, 0, 0, 180 });
		raylib::DrawText(std::to_string(_window.GetFPS()) + " FPS", 3, 3, 20, WHITE);
	}
}