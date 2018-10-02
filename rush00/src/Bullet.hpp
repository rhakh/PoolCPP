#ifndef BULLET_HPP
#define BULLET_HPP

#include "Element.hpp"
#include "main.hpp"

class Bullet : public Element {

public:
	Bullet(void);
	Bullet(int _y, int _x, int _vector);
	Bullet(const Bullet &src);
	~Bullet(void);

	Bullet	&operator=(const Bullet &src);

	int		doMove(int btnPressCode, int frameNumber);

};

#endif // BULLET_HPP
