#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <iostream>
#include <string>
#include "main.hpp"
#include "Game.hpp"

int pl_height = 0;
int pl_length = 0;
int dt_height = 0;
int dt_length = 0;
int win_heigh = 0;
int win_length = 0;
unsigned fps = 0;

results	initGame() {
	results	res;

	res.score = 0;
	res.exitCode = 0;
	res.time = 0;
	try {
		Game		g;

		start_color();
		init_pair(PLAYER_COLOUR, COLOR_GREEN, COLOR_BLACK);
		init_pair(BULLET_COLOUR, COLOR_YELLOW, COLOR_BLACK);
		init_pair(ENEMY_COLOUR, COLOR_RED, COLOR_BLACK);
		init_pair(STAR_COLOUR, COLOR_WHITE, COLOR_BLACK);
		res.exitCode = g.startGame();
		res.score = g.getScore();
		res.time = g.getTimeInGame();
	}
	catch (std::exception &e) {
		std::cout << "Error: Out of memory" << std::endl;
	}
	return (res);
}

int		main(void) {
	results	res;

	srand (time(NULL));
	resize_term( MIN_WIN_HEIGHT, MIN_WIN_LENGTH );
	res = initGame();

	if (!res.exitCode)
		std::cout << "*** GAME OVER ***" << std::endl;
	else
		std::cout << "*** GAME CLOSED ***" << std::endl;
	std::cout << "Score: " << res.score
					<< ", Time played (sec): " << res.time << std::endl;
	return (0);
}