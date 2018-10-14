#include "ncWindow.hpp"
#include "SysInfo.hpp"

ncWindow::ncWindow() :
win_height(0), win_length(0), host_win_height(0), date_win_height(0),
cpu_win_height(0), ram_win_height(0), net_win_height(0), host_win_y(0),
date_win_y(0), cpu_win_y(0), ram_win_y(0), net_win_y(0), fps(FPS) {
	initscr();
	getmaxyx(stdscr, win_height, win_length);

	this->pressCode = 0;
	this->frameNumber = 0;

	if (win_height < MIN_WIN_HEIGHT || win_length < MIN_WIN_LENGTH) {
		endwin();
		throw TermWinTooSmallException();
	}

	host_win = newwin(host_win_height, win_length, host_win_y, WIN_START_X);
	if (host_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}

	date_win = newwin(date_win_height, win_length, date_win_y, WIN_START_X);
	if (date_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}

	cpu_win = newwin(cpu_win_height, win_length, cpu_win_y, WIN_START_X);
	if (cpu_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}

	ram_win = newwin(ram_win_height, win_length, ram_win_y, WIN_START_X);
	if (ram_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}

	net_win = newwin(net_win_height, win_length, net_win_y, WIN_START_X);
	if (net_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}

	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	refresh();
	refreshWindows();
}

void ncWindow::setBorders() {
	wborder(host_win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(date_win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(cpu_win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(ram_win, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(net_win, 0, 0, 0, 0, 0, 0, 0, 0);
}

ncWindow::ncWindow(ncWindow const &src) :
win_height(0), win_length(0), host_win_height(0), date_win_height(0),
cpu_win_height(0), ram_win_height(0), net_win_height(0), host_win_y(0),
date_win_y(0), cpu_win_y(0), ram_win_y(0), net_win_y(0), fps(FPS) {
	*this = src;
	return;
}

ncWindow &ncWindow::operator=(const ncWindow &src) {
	this->win_height = src.win_height;
	this->win_length = src.win_length;
	this->host_win_height = src.host_win_height;
	this->cpu_win_height = src.cpu_win_height;
	this->ram_win_height = src.ram_win_height;
	this->net_win_height = src.net_win_height;
	this->fps = src.fps;

	host_win = newwin(host_win_height, win_length, host_win_y, WIN_START_X);
	if (host_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}

	date_win = newwin(date_win_height, win_length, date_win_y, WIN_START_X);
	if (date_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}

	cpu_win = newwin(cpu_win_height, win_length, cpu_win_y, WIN_START_X);
	if (cpu_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}

	ram_win = newwin(ram_win_height, win_length, ram_win_y, WIN_START_X);
	if (ram_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}

	net_win = newwin(net_win_height, win_length, net_win_y, WIN_START_X);
	if (net_win == NULL) {
		endwin();
		throw OutOfMemoryException();
	}
	
	setBorders();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	refresh();
	refreshWindows();

	this->pressCode = src.getpressCode();
	this->frameNumber = 0;

	return *this;
}

ncWindow::~ncWindow() {
	if (host_win)
		delwin(host_win);
	if (date_win)
		delwin(date_win);
	if (cpu_win)
		delwin(cpu_win);
	if (ram_win)
		delwin(ram_win);
	if (net_win)
		delwin(net_win);
	endwin();
}

int ncWindow::getpressCode() const {
	return pressCode;
}

int ncWindow::getTimeInWindow() const {
	return (this->frameNumber / fps);
}

void ncWindow::destroyWindow() {
	delwin(host_win);
	delwin(date_win);
	delwin(cpu_win);
	delwin(ram_win);
	delwin(net_win);
	host_win = NULL;
	date_win = NULL;
	cpu_win = NULL;
	ram_win = NULL;
	net_win = NULL;
}

void ncWindow::createWindow() {
	host_win = newwin(host_win_height, win_length, host_win_y, WIN_START_X);
	if (host_win == NULL)
		throw OutOfMemoryException();

	date_win = newwin(date_win_height, win_length, date_win_y, WIN_START_X);
	if (date_win == NULL)
		throw OutOfMemoryException();

	cpu_win = newwin(cpu_win_height, win_length, cpu_win_y, WIN_START_X);
	if (cpu_win == NULL)
		throw OutOfMemoryException();

	ram_win = newwin(ram_win_height, win_length, ram_win_y, WIN_START_X);
	if (ram_win == NULL)
		throw OutOfMemoryException();

	net_win = newwin(net_win_height, win_length, net_win_y, WIN_START_X);
	if (net_win == NULL)
		throw OutOfMemoryException();

	setBorders();
}

void ncWindow::setWindowsSizes() {
	this->host_win_height = this->win_height / 5;
	this->date_win_height = this->host_win_height;
	this->cpu_win_height = this->host_win_height;
	this->ram_win_height = this->host_win_height;
	this->net_win_height = this->host_win_height;
	
	this->host_win_y = WIN_START_Y;
	this->date_win_y = this->host_win_y + this->host_win_height;
	this->cpu_win_y = this->date_win_y + this->date_win_height;
	this->ram_win_y = this->cpu_win_y + this->cpu_win_height;
	this->net_win_y = this->ram_win_y + this->ram_win_height;
}

void ncWindow::allocWindows() {
	if (host_win)
		delwin(host_win);
	host_win = newwin(host_win_height, win_length, host_win_y, WIN_START_X);
	if (host_win == NULL)
		throw OutOfMemoryException();

	if (date_win)
		delwin(date_win);
	date_win = newwin(date_win_height, win_length, date_win_y, WIN_START_X);
	if (date_win == NULL)
		throw OutOfMemoryException();

	if (cpu_win)
		delwin(cpu_win);
	cpu_win = newwin(cpu_win_height, win_length, cpu_win_y, WIN_START_X);
	if (cpu_win == NULL)
		throw OutOfMemoryException();

	if (ram_win)
		delwin(ram_win);
	ram_win = newwin(ram_win_height, win_length, ram_win_y, WIN_START_X);
	if (ram_win == NULL)
		throw OutOfMemoryException();

	if (net_win)
		delwin(net_win);
	net_win = newwin(net_win_height, win_length, net_win_y, WIN_START_X);
	if (net_win == NULL)
		throw OutOfMemoryException();
}

void ncWindow::refreshWindows() {
	wrefresh(host_win);
	wrefresh(date_win);
	wrefresh(cpu_win);
	wrefresh(ram_win);
	wrefresh(net_win);
}

void ncWindow::drowWindows() {
	std::string	line;

	// Borders
	wattron(this->net_win, COLOR_PAIR(BORDER_COLOR) | A_BOLD);
	setBorders();
	wattroff(this->net_win, COLOR_PAIR(BORDER_COLOR) | A_BOLD);

	// Hostname
	wattron(this->host_win, COLOR_PAIR(HOST_COLOR) | A_BOLD);
	line = "Hostname: " + getHostname();
	mvwaddstr(this->host_win, 1, 2, line.c_str());
	line = "Username: " + getUsername();
	mvwaddstr(this->host_win, 2, 2, line.c_str());
	wattroff(this->host_win, COLOR_PAIR(HOST_COLOR) | A_BOLD);

	// Date & time
	wattron(this->date_win, COLOR_PAIR(DATE_COLOR) | A_BOLD);
	line = "Date: " + getDate();
	mvwaddstr(this->date_win, 1, 2, line.c_str());
	line = "Time: " + getTime();
	mvwaddstr(this->date_win, 2, 2, line.c_str());
	wattroff(this->date_win, COLOR_PAIR(DATE_COLOR) | A_BOLD);

	// CPU
	wattron(this->cpu_win, COLOR_PAIR(CPU_COLOR) | A_BOLD);
	line = "CPU model: " + getCPUModel();
	mvwaddstr(this->cpu_win, 1, 2, line.c_str());
	line = "CPU clock speed Hz: " + getCPUClockSpeed();
	mvwaddstr(this->cpu_win, 2, 2, line.c_str());
	line = "CPU cores: " + getCPUCoresNum();
	mvwaddstr(this->cpu_win, 3, 2, line.c_str());
	line = "CPU activity " + getCPUActivity();
	mvwaddstr(this->cpu_win, 4, 2, line.c_str());
	wattroff(this->cpu_win, COLOR_PAIR(CPU_COLOR) | A_BOLD);

	// RAM
	wattron(this->ram_win, COLOR_PAIR(RAM_COLOR) | A_BOLD);
	line = "RAM: " + getRAM();
	mvwaddstr(this->ram_win, 1, 2, line.c_str());
	wattroff(this->ram_win, COLOR_PAIR(RAM_COLOR) | A_BOLD);

	// NET
	wattron(this->net_win, COLOR_PAIR(NET_COLOR) | A_BOLD);
	line = "Network: " + getNetworkThroughput(); 
	mvwaddstr(this->net_win, 1, 2, line.c_str());
	wattroff(this->net_win, COLOR_PAIR(NET_COLOR) | A_BOLD);
}

void ncWindow::printWindow()
{
	getmaxyx(stdscr, this->win_height, this->win_length);

	if (this->win_height < MIN_WIN_HEIGHT || this->win_length < MIN_WIN_LENGTH) {
		endwin();
		throw TermWinTooSmallException();
	}

	setWindowsSizes();
	allocWindows();
	drowWindows();

	refreshWindows();
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