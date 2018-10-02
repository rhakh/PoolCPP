#ifndef MAIN_HPP
#define MAIN_HPP

// Main window
#define FIELD_HEIGHT	22
#define FIELD_LENGTH	80
#define FIELD_START_Y	0
#define FIELD_START_X	0

// Data window
#define DATAF_HEIGHT	3
#define DATAF_LENGTH	FIELD_LENGTH
#define DATAF_START_Y	FIELD_HEIGHT
#define DATAF_START_X	0

// Time constants
#define USEC_IN_SEC		1000000
#define FPS				25

// Element representations
#define ELEMENT_FORM	'$'
#define PLAYER_FORM		'}'
#define BULLET_FORM		'~'
#define ENEMY_FORM		'<'
#define BOSS_FORM		'{'
#define BACKGROUND_FORM	'.'
#define HEALTHITEM_FORM 'H'

// Used for 'error: unused parameter'
#define UNUSED(var)		{(void)var;}

typedef enum GameEvents {
	PLAYER_PRESS_SPACE = 1,
	ELEM_REACH_LEFT_SIDE,
	ELEM_REACH_RIGHT_SIDE,
	ENEMY_SHOT
}	GameEvents;

typedef enum ElementColors {
	ELEMENT_COLOR,
	PLAYER_COLOR,
	ENEMY_COLOR,
	BULLET_COLOR,
	BOSS_COLOR,
	DATA_COLOR,
	BACKGROUND_COLOR,
	HEALTHITEM_COLOR
}	ElementColors;

typedef enum GameErrors {
	OUT_OF_MEMORY,
	TERMINAL_WINDOW_TOO_SMALL
}	GameErrors;

typedef enum GameStatuses {
	GAME_OK,
	GAME_OVER
}	GameStatuses;

typedef struct	result_s {
	int		score;
	int		exitCode;
	int		time;
}				result_t;

#endif // MAIN_HPP
