#include "Game.hpp"
#include "Player.hpp"

result_t	initGame() {
	result_t	res;

	res.score = 0;
	res.exitCode = GAME_OK;
	res.time = 0;
	try {
		Game		g;

		start_color();
		init_pair(PLAYER_COLOR, COLOR_GREEN, COLOR_BLACK);
		init_pair(BULLET_COLOR, COLOR_YELLOW, COLOR_BLACK);
		init_pair(ENEMY_COLOR, COLOR_RED, COLOR_BLACK);
		init_pair(BOSS_COLOR, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(DATA_COLOR, COLOR_CYAN, COLOR_BLACK);
		init_pair(BACKGROUND_COLOR, COLOR_WHITE, COLOR_BLACK);
		init_pair(HEALTHITEM_COLOR, COLOR_GREEN, COLOR_BLACK);
		res.exitCode = g.startGame();
		res.score = g.getScore();
		res.time = g.getTimeInGame();
	}
	catch (GameErrors e) {
		if (e == OUT_OF_MEMORY)
			std::cout << "Error: Out of memory" << std::endl;
		else if (e == TERMINAL_WINDOW_TOO_SMALL)
			std::cout << "Error: Terminal window too small" << std::endl;
	}
	return (res);
}

int		main(void) {
	result_t	res;

	srand (time(NULL));
	resize_term( FIELD_HEIGHT, FIELD_LENGTH );
	res = initGame();

	if (res.exitCode == GAME_OVER)
		std::cout << "*** GAME OVER ***" << std::endl;
	else
		std::cout << "*** GAME CLOSED ***" << std::endl;
	std::cout << "Score: " << res.score
					<< ", Time played (sec): " << res.time << std::endl;
	return (0);
}