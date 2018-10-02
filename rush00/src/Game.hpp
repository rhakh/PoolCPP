#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <sys/time.h>
#include <ncurses.h>
#include "Player.hpp"
#include "Element.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"
#include "Background.hpp"
#include "HealthItem.hpp"
#include "element_node.hpp"
#include <ctime>
#include <cstdlib>
#include <sstream>

class Game {

	WINDOW			*win;
	WINDOW			*data_win;
	element_node_t	*list;

	int		lastBtnPressCode;
	int		score;
	int		isPaused;
	int		frameNumber;

public:
	Game(void);
	Game(Game const & src);
	~Game(void);
	Game	&operator=(const Game &src);

	int		startGame(void);

	void	doMove();
	void	printOutWindow();
	void	destroyGame(void);
	void	createGame(void);
	void	createEnemy();
	void	checkForCollisions(void);
	void	deleteDeadElements(void);
	int		checkElements(Element *elem1, Element *elem2);

	int		getLastBtnPressCode() const;
	int		getScore() const;
	int		getTimeInGame() const;
};

#endif // GAME_HPP
