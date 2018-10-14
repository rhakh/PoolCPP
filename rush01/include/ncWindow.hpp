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
		WINDOW *host_win;	// hostname window
		WINDOW *date_win;	// date_window
		WINDOW *cpu_win;
		WINDOW *ram_win;
		WINDOW *net_win;	// network window

		int win_height;	// main window
		int win_length;
		
		int host_win_height;
		int date_win_height;
		int cpu_win_height;
		int ram_win_height;
		int net_win_height;

		int host_win_y;
		int date_win_y;
		int cpu_win_y;
		int ram_win_y;
		int net_win_y;

		unsigned fps;

		int	pressCode;
		unsigned frameNumber;

		void printWindow();
		void destroyWindow();
		void createWindow();
		void setWindowsSizes();
		void allocWindows();
		void refreshWindows();
		void setBorders();
		void drowWindows();
};

#endif
