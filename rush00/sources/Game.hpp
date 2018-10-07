#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <sys/time.h>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "main.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "node_t.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"
#include "HPObject.hpp"
#include "Star.hpp"
#include "Bullet.hpp"

class Game {

	WINDOW	*win;
	WINDOW	*data_win;
	node_t	*list;

	int			pressCode;
	int			score;
	int			isPaused;
	unsigned	frameNumber;

	void	processMoves();
	void	printWindow();
	void	destroyGame(void);
	void	createGame(void);
	void	createEnemy();
	void	checkForCollisions(void);
	void	deleteDeadObjects(void);
	int		checkObjects(Object *obj1, Object *obj2);

public:
	Game(void);
	Game(Game const & src);
	~Game(void);
	Game	&operator=(const Game &src);

	int		startGame(void);
	int		getpressCode() const;
	int		getScore() const;
	int		getTimeInGame() const;
};

#endif // GAME_HPP
