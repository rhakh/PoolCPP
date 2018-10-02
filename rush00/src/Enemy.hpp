#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Element.hpp"
#include <cstdlib>

class Enemy : public Element {

public:
	Enemy(void);
	Enemy(int _y, int _x);
	Enemy(const Enemy &src);
	~Enemy(void);

	Enemy	&operator=(const Enemy &src);

	int		doMove(int btnPressCode, int frameNumber);

};

#endif // ENEMY_HPP
