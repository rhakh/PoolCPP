#include "ncWindow.hpp"
#include "SysInfo.hpp"

ncWindow::ncWindow() {
	initscr();
	getmaxyx(stdscr, win_height, win_length);

	this->pressCode = 0;
	this->frameNumber = 0;

	if (win_height < MIN_WIN_HEIGHT || win_length < MIN_WIN_LENGTH) {
		endwin();
		throw TermWinTooSmallException();
	}

	win = newwin(win_height, win_length, WIN_START_Y, WIN_START_X);
	if (win == NULL) {
		throw OutOfMemoryException();
		endwin();
	}

	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	refresh();
	wrefresh(win);
}

ncWindow::ncWindow(ncWindow const &src) {
	*this = src;
	return;
}

ncWindow &ncWindow::operator=(const ncWindow &src) {
	win = newwin(win_height, win_length, WIN_START_Y, WIN_START_X);
	if (win == NULL)
		throw OutOfMemoryException();

	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	refresh();
	wrefresh(win);

	this->pressCode = src.getpressCode();
	this->frameNumber = 0;

	return *this;
}

ncWindow::~ncWindow() {
	if (win)
		delwin(win);
	endwin();
}

int ncWindow::getpressCode() const {
	return pressCode;
}

int ncWindow::getTimeInWindow() const {
	return (this->frameNumber / fps);
}

void	ncWindow::destroyWindow() {
	delwin(win);
	win = NULL;
}

void	ncWindow::createWindow() {
	win = newwin(win_height, win_length, WIN_START_Y, WIN_START_X);
	if (win == NULL)
		throw OutOfMemoryException();

	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
}

void	ncWindow::printWindow()
{
	getmaxyx(stdscr, win_height, win_length);

	if (win_height < MIN_WIN_HEIGHT || win_length < MIN_WIN_LENGTH) {
		endwin();
		throw TermWinTooSmallException();
	}

	if (win)
		delwin(win);
	win = newwin(win_height, win_length, WIN_START_Y, WIN_START_X);
	if (win == NULL)
		throw OutOfMemoryException();


	wattron(this->win, COLOR_PAIR(TEXT_COLOR) | A_BOLD);
	mvwaddstr(this->win, win_height / 2, win_length / 3, getHostname().c_str());
	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	wattroff(this->win, COLOR_PAIR(TEXT_COLOR) | A_BOLD);

	wrefresh(win);
}

unsigned int timediff_usec(timeval t1, timeval t2) {
	return ((t2.tv_sec * USEC_IN_SEC + t2.tv_usec) -
			(t1.tv_sec * USEC_IN_SEC + t1.tv_usec));
}

int		ncWindow::startWindow() {

	struct timeval	start;
	struct timeval	now;

	while ((this->pressCode = getch()) != 27) {
		gettimeofday(&start, NULL);
		gettimeofday(&now, NULL);

		printWindow();

		while (timediff_usec(start, now) <= (USEC_IN_SEC / fps))
			gettimeofday(&now, NULL);

		destroyWindow();
		createWindow();
		this->frameNumber++;
	}

	return 0;
}