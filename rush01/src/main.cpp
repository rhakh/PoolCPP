#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <iostream>
#include <string>
#include "main.hpp"
#include "ncWindow.hpp"

void	initWin() {
	try {
		ncWindow win;

		start_color();
		init_pair(TEXT_COLOR, COLOR_CYAN, COLOR_BLACK);
		win.startWindow();
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main() {
	srand(time(NULL));
	resize_term( MIN_WIN_HEIGHT, MIN_WIN_LENGTH );
	initWin();

	return 0;
}

// clang++ -L /opt/X11/lib  -I /opt/X11/include  -lX11 x11.cpp