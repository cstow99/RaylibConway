/*
	Main.cpp
	
	Stores the main function
*/

#include <iostream>
#include <stdexcept>

//#if defined(_WIN32) || defined(_WIN64)
//#include <windows.h>
//#endif

#include "Conway.h"

int main() {
	std::cout << "Raylib - Conway's Game of Life\nWritten by ViperSLM\n" << std::endl;
	try {
		Game game;
	}
	catch (std::exception ex) {
		std::cout << ":( FATAL ERROR: An exception has been thrown and the program must quit."
			<< "\n\nException Details: " << ex.what() << std::endl;
		return -1;
	}
	return 0;
}