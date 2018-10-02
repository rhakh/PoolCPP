#ifndef HEALTHITEM_HPP
#define HEALTHITEM_HPP

#include "Element.hpp"
#include "Game.hpp"
#include <cstdlib>

class HealthItem : public Element {

public:
	HealthItem(void);
	HealthItem(int _y, int _x);
	HealthItem(const HealthItem &src);
	~HealthItem(void);

	HealthItem	&operator=(const HealthItem &src);

	int		doMove(int btnPressCode, int frameNumber);

};

#endif // HEALTHITEM_HPP