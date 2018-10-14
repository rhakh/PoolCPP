#ifndef MAIN_HPP
#define MAIN_HPP

#include <exception>

// Playground window
#define MIN_WIN_HEIGHT	30
#define MIN_WIN_LENGTH	80
#define WIN_START_Y	    0
#define WIN_START_X	    0

// Time constants
#define USEC_IN_SEC		1000000
#define FPS				5

extern int  win_height;
extern int  win_length;
extern unsigned fps;

typedef enum ObjColors_e {
	TEXT_COLOR = 1,
}	ObjColors;

#endif
