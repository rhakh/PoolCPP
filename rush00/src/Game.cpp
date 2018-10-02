#include "Game.hpp"

Game::Game(void) {
	int	x, y;

	initscr();
	getmaxyx(stdscr, y, x);

	this->score = 0;
	this->isPaused = 1;
	this->lastBtnPressCode = 0;
	this->frameNumber = 0;

	if (y < 25 || x < 80) {
		endwin();
		throw TERMINAL_WINDOW_TOO_SMALL;
	}

	win = newwin(FIELD_HEIGHT, FIELD_LENGTH, FIELD_START_Y, FIELD_START_X);
	if (win == NULL) {
		throw OUT_OF_MEMORY;
		endwin();
	}

	data_win = newwin(DATAF_HEIGHT, DATAF_LENGTH, DATAF_START_Y, DATAF_START_X);
	if (data_win == NULL) {
		throw OUT_OF_MEMORY;
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
	win = newwin(FIELD_HEIGHT, FIELD_LENGTH, FIELD_START_Y, FIELD_START_X);
	if (win == NULL)
		throw OUT_OF_MEMORY;

	data_win = newwin(DATAF_HEIGHT, DATAF_LENGTH, DATAF_START_Y, DATAF_START_X);
	if (data_win == NULL)
		throw OUT_OF_MEMORY;

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

	this->lastBtnPressCode = src.getLastBtnPressCode();
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

int		Game::getLastBtnPressCode() const {
	return(lastBtnPressCode);
}

int		Game::getScore() const {
	return(score);
}

int		Game::getTimeInGame() const {
	return (this->frameNumber / FPS);
}

void	Game::destroyGame(void)
{
	delwin(win);
	delwin(data_win);
	win = NULL;
}

void	Game::createGame(void)
{
	win = newwin(FIELD_HEIGHT, FIELD_LENGTH, FIELD_START_Y, FIELD_START_X);

	if (win == NULL)
		throw "Out of memory";
	data_win = newwin(DATAF_HEIGHT, DATAF_LENGTH, DATAF_START_Y, DATAF_START_X);
	if (data_win == NULL)
		throw "Out of memory";

	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(data_win, 0, 0, 0, 0, 0, 0, 0, 0);
}

void	Game::doMove() {
	element_node_t		*curr;
	element_node_t		*next;

	Element				*elem;

	int					code;

	curr = this->list;
	while (curr) {
		elem = curr->elem;
		next = curr->next;

		code = elem->doMove(this->lastBtnPressCode, this->frameNumber);
		switch (code) {
			case PLAYER_PRESS_SPACE : {
					/* Player pressed space */
					elem_node_add_tail(
						elem_node_new(
							new Bullet(elem->getY(), elem->getX() + 1, 1)
						),
						this->list
					);
				}
				break ;
			case ELEM_REACH_LEFT_SIDE :
			case ELEM_REACH_RIGHT_SIDE : {
					/* delete element */
					elem_node_del_node(curr, &this->list);
					delete curr->elem;
					delete curr;
				}
				break ;
			case ENEMY_SHOT : {
					elem_node_add_tail(
						elem_node_new(
							new Bullet(elem->getY(), elem->getX() - 1, -1)
						),
						this->list
					);
				}
				break ;
		}
		curr = next;
	}
}

void	Game::printOutWindow()
{
	element_node_t		*curr, *next;
	std::stringstream	sc;
	std::stringstream	lf;
	std::stringstream	fn;
	std::string			dataStr;
	Element				*elem;

	curr = this->list;
	while (curr)
	{
		elem = curr->elem;
		next = curr->next;
		if (elem->getLife() <= 0)
		{
			elem_node_del_node(curr, &this->list);
			if (curr->elem->getForm() == BOSS_FORM)
				this->score += 3;
			else if (curr->elem->getForm() == ENEMY_FORM)
				this->score++;

			delete curr->elem;
			delete curr;
		}
		else if (this->isPaused == 1)
		{
			wattron(this->win, COLOR_PAIR(DATA_COLOR) | A_BOLD);
			mvwaddstr(this->win, FIELD_HEIGHT / 2, FIELD_LENGTH / 3, "Press SPACE to start.");
			wattroff(this->win, COLOR_PAIR(DATA_COLOR) | A_BOLD);
		}
		else
			elem->printOut(this->win);
		curr = next;
	}

	sc << score;
	lf << this->list->elem->getLife();
	fn << this->frameNumber / FPS;
	dataStr = "SCORE: " + sc.str() + ", LIFE: " + lf.str() + ", TIME: " + fn.str();
	if (this->isPaused == 1)
		dataStr += "\t\tPAUSED";
	else
		dataStr += "\t\tPress P for PAUSE";

	wattron(data_win, COLOR_PAIR(DATA_COLOR) | A_BOLD);
	mvwaddstr(data_win, 1, 1, dataStr.c_str());
	wattroff(data_win, COLOR_PAIR(DATA_COLOR) | A_BOLD);

	wrefresh(win);
	wrefresh(data_win);
}

void	Game::createEnemy() {
	int	random;
	int	start_y;

	random = rand() % 100;
	start_y = (rand() % (FIELD_HEIGHT - 2)) + FIELD_START_Y + 1;
	if (random < 3) {
		elem_node_add_tail(elem_node_new(new Enemy(start_y, FIELD_LENGTH - 2)),
							this->list);
	}
	else if (this->frameNumber % (10 * FPS) == 0) {
		elem_node_add_tail(elem_node_new(new Boss(start_y, FIELD_LENGTH - 4)),
							this->list);
	}
	else if (random < 10) {
		elem_node_add_tail(elem_node_new(new Background(start_y, FIELD_LENGTH - 2)),
							this->list);
	}
	else if (this->frameNumber % 300 * FPS == 0) {
		elem_node_add_tail(elem_node_new(new HealthItem(start_y, FIELD_LENGTH - 2)),
							this->list);
	}
}

int		Game::checkElements(Element *elem1, Element *elem2) {

	int		x1, x2;
	int		y1, y2;
	char	form1, form2;

	x1 = elem1->getX();
	x2 = elem2->getX();
	y1 = elem1->getY();
	y2 = elem2->getY();
	form1 = elem1->getForm();
	form2 = elem2->getForm();

	if (y1 != y2)
		return (0);

	if (form1 == PLAYER_FORM && form2 == BULLET_FORM &&
		elem2->getVector() == -1 && (x1 == x2))
		return (1);
	else if (form1 == BULLET_FORM && (form2 == ENEMY_FORM || form2 == BOSS_FORM) &&
		elem1->getVector() == 1 && ((x2 - x1 == 1) || (x2 == x1)))
		return (1);
	else if (form2 == BULLET_FORM && (form1 == ENEMY_FORM || form1 == BOSS_FORM) &&
		elem2->getVector() == 1 && ((x1 - x2 == 1) || (x2 == x1)))
		return (1);
	else if (form1 == PLAYER_FORM && (form2 == ENEMY_FORM || form2 == BOSS_FORM) &&
		(x1 == x2))
		return (1);
	else if (form1 == PLAYER_FORM && form2 == HEALTHITEM_FORM &&
		((x2 - x1 == 1) || (x2 == x1)))
	{
		elem1->incLife(2);
		return (1);
	}
	return (0);
}

void	Game::checkForCollisions(void) {
	element_node_t		*curr1, *curr2;
	Element				*elem1, *elem2;

	curr1 = this->list;
	while (curr1)
	{
		elem1 = curr1->elem;
		curr2 = curr1->next;
		while (curr2)
		{
			elem2 = curr2->elem;
			if (checkElements(elem1, elem2))
			{
				elem1->decLife();
				elem2->decLife();
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

	Player			*player = new Player(FIELD_HEIGHT / 2, FIELD_LENGTH / 2);
	struct timeval	start;
	struct timeval	now;

	this->list = elem_node_new(player);

	// untill ESC was pressed
	while ((this->lastBtnPressCode = getch()) != 27) {
		gettimeofday(&start, NULL);
		gettimeofday(&now, NULL);

		if (this->list->elem->getLife() == 0) {
			elem_node_del_list(this->list);
			return (GAME_OVER);
		}

		printOutWindow();

		if (this->lastBtnPressCode == 'p' && this->isPaused == 0)
			this->isPaused = 1;
		else if ((this->lastBtnPressCode == 'p' || this->lastBtnPressCode == ' ')
					&& this->isPaused == 1)
			this->isPaused = 0;
		else if (this->lastBtnPressCode != 'p' && this->isPaused == 1)
			continue ;

		while (timediff_usec(start, now) <= (USEC_IN_SEC / FPS))
			gettimeofday(&now, NULL);

		destroyGame();
		createGame();
		createEnemy();
		doMove();
		checkForCollisions();
		this->frameNumber++;
	}
	elem_node_del_list(this->list);
	return (GAME_OK);
}
