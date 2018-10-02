#include "HealthItem.hpp"

HealthItem::HealthItem(void)
	: Element() {

	this->vector = -1;
	this->color = HEALTHITEM_COLOR;
	this->form = HEALTHITEM_FORM;
}

HealthItem::~HealthItem(void) {

}

HealthItem::HealthItem(int _y, int _x)
	: Element(_y, _x) {

	this->vector = -1;
	this->color = HEALTHITEM_COLOR;
	this->form = HEALTHITEM_FORM;
}

HealthItem::HealthItem(HealthItem const &src)
{
	*this = src;
	return;
}

HealthItem&	HealthItem::operator=(const HealthItem &src)
{
	this->x = src.getX();
	this->y = src.getY();
	this->vector = src.getVector();
	this->color = src.getColor();
	this->form = src.getForm();
	this->life = src.getLife();
	return *this;
}

int	HealthItem::doMove(int btnPressCode, int frameNumber) {
	UNUSED(btnPressCode);

	if (frameNumber % 5 == 0)
		return (0);

	if (this->vector == -1 && (this->x - 1) > FIELD_START_X) {
		this->x--;
	}
	else if (this->vector == 1 && (this->x + 2) < FIELD_LENGTH) {
		this->x++;
	}
	else if (this->vector == -1 && (this->x - 1) <= FIELD_START_X)
		return (ELEM_REACH_LEFT_SIDE);
	else if (this->vector == 1 && (this->x + 2) >= FIELD_LENGTH)
		return (ELEM_REACH_RIGHT_SIDE);

	return (0);
}
