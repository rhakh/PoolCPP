#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <ncurses.h>
#include "main.hpp"

class Element {

protected:
	int		x;
	int		y;
	int		vector;
	int		color;
	char	form;
	int		life;

public:
	Element(void);
	Element(int _y, int _x);
	Element(const Element & src);
	virtual ~Element(void);
	virtual Element	&operator=(const Element & src);

	virtual int		doMove(int btnPressCode, int frameNumber) = 0;
	virtual void	printOut(WINDOW *win);

	virtual int		getX(void) const;
	virtual int		getY(void) const;
	virtual int		getColor(void) const;
	virtual int		getVector(void) const;
	virtual char 	getForm(void) const;
	virtual int		getLife(void) const;
	void			decLife(void);
	void			incLife(int i);
};

#endif // ELEMENT_HPP
