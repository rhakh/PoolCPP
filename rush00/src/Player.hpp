#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Element.hpp"
# include "main.hpp"

#define DEFAULT_PLAYER_LIFE 3

class Player : public Element {

public:
	Player(void);
	Player(int _y, int _x);
	Player(const Player & src);
	~Player(void);

	Player	&operator=(const Player & src);
	int		doMove(int btnPressCode, int frameNumber);

};

#endif // PLAYER_HPP
