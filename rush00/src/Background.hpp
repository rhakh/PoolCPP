#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "Element.hpp"
#include "Game.hpp"
#include <cstdlib>

class Background : public Element {

public:
	Background(void);
	Background(int _y, int _x);
	Background(const Background &src);
	~Background(void);

	Background	&operator=(const Background &src);

	int		doMove(int btnPressCode, int frameNumber);

};

#endif // BACKGROUND_HPP