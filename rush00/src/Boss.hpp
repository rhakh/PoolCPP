#ifndef BOSS_HPP
#define BOSS_HPP

#include "Element.hpp"
#include <cstdlib>

class Boss : public Element {

public:
	Boss(void);
	Boss(int _y, int _x);
	Boss(const Boss &src);
	~Boss(void);

	Boss	&operator=(Boss const &src);

	int		doMove(int btnPressCode, int frameNumber);
	void	printOut(WINDOW *win);

};

#endif // ENEMY_HPP
