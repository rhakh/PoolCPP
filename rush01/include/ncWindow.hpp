#ifndef NC_WINDOW_HPP
#define NC_WINDOW_HPP

#include <iostream>
#include <sys/time.h>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "main.hpp"
#include "Exceptions.hpp"

class ncWindow {
	public:
		ncWindow();
		ncWindow(ncWindow const & src);
		~ncWindow();

		ncWindow &operator=(const ncWindow &src);

		int	startWindow();
		int	getpressCode() const;
		int	getTimeInWindow() const;

	private:
		WINDOW *win;

		int	pressCode;
		unsigned frameNumber;

		void printWindow();
		void destroyWindow();
		void createWindow();
};

#endif
