#ifndef MAIN_HPP
#define MAIN_HPP

#include <exception>

// Playground window
#define MIN_WIN_HEIGHT	25
#define MIN_WIN_LENGTH	80
#define PL_START_Y	    0
#define PL_START_X	    0

// Data window
#define DATA_WIN_HEIGHT 3
#define DT_START_X      0

// Time constants
#define USEC_IN_SEC		1000000
#define FPS				25

extern int  pl_height;
extern int  pl_length;
extern int  dt_height;
extern int  dt_length;
extern int  win_height;
extern int  win_length;
extern unsigned fps;

typedef enum ObjColours_e {
	DEF_COLOUR,
    ENEMY_COLOUR,
    PLAYER_COLOUR,
    STAR_COLOUR,
    TEXT_COLOUR,
	BULLET_COLOUR,
	BOSS_COLOUR,
	HP_COLOUR
}	ObjColours;

typedef enum Directions_e {
	DEF_DIRECT,
    FORWARD_DIRECT,
    BACKWARD_DIRECT
}	Directions;

typedef enum Shapes_e {
	DEF_SHAPE = '?',
    ENEMY_SHAPE = '<',
    BULLET_SHAPE = '~',
    PLAYER_SHAPE = '}',
    BOSS_SHAPE = '{',
    STAR_SHAPE = '.',
    HP_SHAPE = '+'
}	Shapes;

typedef enum HealthPoints_e {
	DEF_HP = 1,
	PLAYER_HP = 3,
	BOSS_HP = 5
}	HealthPoints;

typedef enum GameEvents_e {
    OBJECT_REACH_LEFT_SIDE = 1,
    OBJECT_REACH_RIGHT_SIDE,
    PLAYER_SHOT,
    ENEMY_SHOT,
}	GameEvents;

typedef struct	results_s {
	int		score;
	int		exitCode;
	int		time;
}				results;

class TermWinTooSmallException : public std::exception {
	public:
		TermWinTooSmallException();
		TermWinTooSmallException(const TermWinTooSmallException &src);
		~TermWinTooSmallException() throw();
		TermWinTooSmallException	&operator=(const TermWinTooSmallException &rhs);
		virtual const char		*what() const throw();
};

class OutOfMemoryException : public std::exception {
	public:
		OutOfMemoryException();
		OutOfMemoryException(const OutOfMemoryException &src);
		~OutOfMemoryException() throw();
		OutOfMemoryException	&operator=(const OutOfMemoryException &rhs);
		virtual const char		*what() const throw();
};

#endif // MAIN_HPP
