#include "Game.hpp"

Game::Game() {
	initscr();
	getmaxyx(stdscr, win_height, win_length);

	this->score = 0;
	this->isPaused = 1;
	this->pressCode = 0;
	this->frameNumber = 0;

	if (win_height < MIN_WIN_HEIGHT || win_length < MIN_WIN_LENGTH) {
		endwin();
		throw TermWinTooSmallException();
	}

	pl_height = win_height - 3;
	pl_length = win_length;
	win = newwin(pl_height, pl_length, PL_START_Y, PL_START_X);
	if (win == NULL) {
		throw OutOfMemoryException();
		endwin();
	}

	dt_height = DATA_WIN_HEIGHT;
	dt_length = win_length;
	data_win = newwin(dt_height, dt_length, pl_height, DT_START_X);
	if (data_win == NULL) {
		throw OutOfMemoryException();
		delwin(win);
		endwin();
	}

	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(data_win, 0, 0, 0, 0, 0, 0, 0, 0);
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	refresh();
	wrefresh(win);
	wrefresh(data_win);
}

Game::Game(Game const &src) {
	*this = src;
	return;
}

Game	&Game::operator=(const Game &src) {
	win = newwin(pl_height, pl_length, PL_START_Y, PL_START_X);
	if (win == NULL)
		throw OutOfMemoryException();

	data_win = newwin(dt_height, dt_length, pl_height, DT_START_X);
	if (data_win == NULL)
		throw OutOfMemoryException();

	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(data_win, 0, 0, 0, 0, 0, 0, 0, 0);
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	refresh();
	wrefresh(win);
	wrefresh(data_win);

	this->pressCode = src.getpressCode();
	this->score = src.getScore();
	this->isPaused = 0;
	this->frameNumber = 0;

	return *this;
}

Game::~Game(void) {
	if (win)
		delwin(win);
	if (data_win)
		delwin(data_win);
	endwin();
}

int		Game::getpressCode() const {
	return(pressCode);
}

int		Game::getScore() const {
	return(score);
}

int		Game::getTimeInGame() const {
	return (this->frameNumber / fps);
}

void	Game::destroyGame(void)
{
	delwin(win);
	delwin(data_win);
	win = NULL;
}

void	Game::createGame(void)
{
	win = newwin(pl_height, pl_length, PL_START_Y, PL_START_X);
	if (win == NULL)
		throw OutOfMemoryException();

	data_win = newwin(dt_height, dt_length, pl_height, DT_START_X);
	if (data_win == NULL)
		throw OutOfMemoryException();

	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(data_win, 0, 0, 0, 0, 0, 0, 0, 0);
}

void	Game::processMoves() {
	node_t		*curr;
	node_t		*next;
	Object		*obj;
	int			code;

	curr = this->list;
	while (curr) {
		obj = curr->obj;
		next = curr->next;

		code = obj->processMove(this->frameNumber, this->pressCode);
		switch (code) {
			case PLAYER_SHOT : {
					/* Player pressed space */
					node_add_tail(
						node_new(
							new Bullet(obj->getX() + 1, obj->getY(), FORWARD_DIRECT)
						),
						this->list
					);
				}
				break ;
			case OBJECT_REACH_LEFT_SIDE :
			case OBJECT_REACH_RIGHT_SIDE : {
					/* delete object */
					node_del_node(curr, &this->list);
					delete curr->obj;
					delete curr;
				}
				break ;
			case ENEMY_SHOT : {
					node_add_tail(
						node_new(
							new Bullet(obj->getX() - 1, obj->getY(), BACKWARD_DIRECT)
						),
						this->list
					);
				}
				break ;
		}
		curr = next;
	}
}

void	Game::printWindow()
{
	std::stringstream	sc;
	std::stringstream	lf;
	std::stringstream	fn;
	std::string			dataStr;
	node_t				*curr, *next;
	Object				*obj;

	curr = this->list;
	while (curr)
	{
		obj = curr->obj;
		next = curr->next;
		if (obj->getHP() <= 0)
		{
			node_del_node(curr, &this->list);
			if (curr->obj->getShape() == BOSS_SHAPE)
				this->score += 3;
			else if (curr->obj->getShape() == ENEMY_SHAPE)
				this->score++;

			delete curr->obj;
			delete curr;
		}
		else if (this->isPaused == 1)
		{
			wattron(this->win, COLOR_PAIR(TEXT_COLOUR) | A_BOLD);
			mvwaddstr(this->win, pl_height / 2, pl_length / 3, "Press SPACE to start.");
			wattroff(this->win, COLOR_PAIR(TEXT_COLOUR) | A_BOLD);
		}
		else
			obj->print(this->win);
		curr = next;
	}

	sc << score;
	lf << this->list->obj->getHP();
	fn << this->frameNumber / fps;
	dataStr = "SCORE: " + sc.str() + ", LIFE: " + lf.str() + ", TIME: " + fn.str();
	if (this->isPaused == 1)
		dataStr += "\t\tPAUSED";
	else
		dataStr += "\t\tPress P for PAUSE";

	wattron(data_win, COLOR_PAIR(TEXT_COLOUR) | A_BOLD);
	mvwaddstr(data_win, 1, 1, dataStr.c_str());
	wattroff(data_win, COLOR_PAIR(TEXT_COLOUR) | A_BOLD);

	wrefresh(win);
	wrefresh(data_win);
}

void	Game::createEnemy() {
	int	random;
	int	start_y;

	random = rand() % 100;
	start_y = (rand() % (pl_height - 2)) + PL_START_Y + 1;
	if (random < 3) {
		node_add_tail(node_new(new Enemy(pl_length - 2, start_y)),
							this->list);
	}
	else if (this->frameNumber % (10 * fps) == 0) {
		node_add_tail(node_new(new Boss(pl_length - 4, start_y)),
							this->list);
	}
	else if (random < 10) {
		node_add_tail(node_new(new Star(pl_length - 2, start_y)),
							this->list);
	}
	else if (this->frameNumber % 300 * fps == 0) {
		node_add_tail(node_new(new HPObject(pl_length - 2, start_y)),
							this->list);
	}
}

int		Game::checkObjects(Object *obj1, Object *obj2) {

	int		x1, x2;
	int		y1, y2;
	char	form1, form2;

	x1 = obj1->getX();
	x2 = obj2->getX();
	y1 = obj1->getY();
	y2 = obj2->getY();
	form1 = obj1->getShape();
	form2 = obj2->getShape();

	if (y1 != y2)
		return (0);

	if (form1 == PLAYER_SHAPE && form2 == BULLET_SHAPE &&
		obj2->getDirection() == -1 && (x1 == x2))
		return (1);
	else if (form1 == BULLET_SHAPE && (form2 == ENEMY_SHAPE || form2 == BOSS_SHAPE) &&
		obj1->getDirection() == 1 && ((x2 - x1 == 1) || (x2 == x1)))
		return (1);
	else if (form2 == BULLET_SHAPE && (form1 == ENEMY_SHAPE || form1 == BOSS_SHAPE) &&
		obj2->getDirection() == 1 && ((x1 - x2 == 1) || (x2 == x1)))
		return (1);
	else if (form1 == PLAYER_SHAPE && (form2 == ENEMY_SHAPE || form2 == BOSS_SHAPE) &&
		(x1 == x2))
		return (1);
	else if (form1 == PLAYER_SHAPE && form2 == HP_SHAPE &&
		((x2 - x1 == 1) || (x2 == x1)))
	{
		obj1->increaseHP();
		obj1->increaseHP();
		return (1);
	}
	return (0);
}

void	Game::checkForCollisions(void) {
	node_t	*curr1, *curr2;
	Object	*obj1, *obj2;

	curr1 = this->list;
	while (curr1)
	{
		obj1 = curr1->obj;
		curr2 = curr1->next;
		while (curr2)
		{
			obj2 = curr2->obj;
			if (checkObjects(obj1, obj2))
			{
				obj1->decreaseHP();
				obj2->decreaseHP();
			}
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}
}

unsigned int    timediff_usec(timeval t1, timeval t2) {
	return ((t2.tv_sec * USEC_IN_SEC + t2.tv_usec) -
			(t1.tv_sec * USEC_IN_SEC + t1.tv_usec));
}

int		Game::startGame(void) {

	Player			*player = new Player(PL_START_X + 1, pl_height / 2);
	struct timeval	start;
	struct timeval	now;

	this->list = node_new(player);

	// untill ESC was pressed
	while ((this->pressCode = getch()) != 27) {
		gettimeofday(&start, NULL);
		gettimeofday(&now, NULL);

		if (this->list->obj->getHP() == 0) {
			node_del_list(this->list);
			return (-1);
		}

		printWindow();

		if (this->pressCode == 'p' && this->isPaused == 0)
			this->isPaused = 1;
		else if ((this->pressCode == 'p' || this->pressCode == ' ')
					&& this->isPaused == 1)
			this->isPaused = 0;
		else if (this->pressCode != 'p' && this->isPaused == 1)
			continue ;

		while (timediff_usec(start, now) <= (USEC_IN_SEC / fps))
			gettimeofday(&now, NULL);

		destroyGame();
		createGame();
		createEnemy();
		processMoves();
		checkForCollisions();
		this->frameNumber++;
	}
	node_del_list(this->list);
	return (0);
}
