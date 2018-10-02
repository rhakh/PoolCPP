#include "Element.hpp"

Element::Element(void) {
	this->x = 0;
	this->y = 0;
	this->vector = 0;
	this->color = ELEMENT_COLOR;
	this->form = ELEMENT_FORM;
	this->life = 0;
	return;
}

Element::Element(int _y, int _x) {
	this->x = _x;
	this->y = _y;
	this->vector = 0;
	this->color = ELEMENT_COLOR;
	this->form = ELEMENT_FORM;
	this->life = 1;
	return;
}

Element::Element(const Element & src) {
	*this = src;
	return;
}

Element::~Element(void) {

}

Element& Element::operator=(const Element & src) {
	this->x = src.getX();
	this->y = src.getY();
	this->vector = src.getVector();
	this->color = src.getColor();
	this->form = src.getForm();
	this->life = src.getLife();
	return *this;
}

int		Element::getX(void) const {

	return (this->x);
}

int		Element::getY(void) const {
	return (this->y);
}

int		Element::getColor(void) const {
	return (this->color);
}

char	Element::getForm(void) const {
	return (this->form);
}

int		Element::getVector(void) const {
	return (this->vector);
}

int		Element::getLife(void) const {
	return (this->life);
}

void	Element::decLife(void) {
	this->life--;
}

void	Element::incLife(int i)
{
	this->life += i;
	return;
}

void	Element::printOut(WINDOW *win) {
	wattron(win, COLOR_PAIR(this->color));
	mvwaddch(win, this->y, this->x, form | A_BOLD);
	wattroff(win, COLOR_PAIR(this->color));
}
