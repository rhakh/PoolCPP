#include "Bullet.hpp"

Bullet::Bullet(void)
	: Element() {

	this->vector = 1;
	this->color = BULLET_COLOR;
	this->form = BULLET_FORM;
	return;
}

Bullet::Bullet(int _y, int _x, int _vector)
	: Element(_y, _x) {

	this->vector = _vector;
	this->color = BULLET_COLOR;
	this->form = BULLET_FORM;
	return;
}

Bullet::~Bullet(void) {

}

Bullet& Bullet::operator=(const Bullet &src)
{
	this->x = src.getX();
	this->y = src.getY();
	this->vector = src.getVector();
	this->color = src.getColor();
	this->form = src.getForm();
	this->life = src.getLife();
	return *this;
}

int	Bullet::doMove(int btnPressCode, int frameNumber) {
	UNUSED(frameNumber);
	UNUSED(btnPressCode);
	
	if (this->vector == 1 && (this->x + 2) < FIELD_LENGTH) {
		this->x++;
	}
	else if (this->vector == -1 && (this->x - 1) > FIELD_START_X) {
		this->x--;
	}
	else if (this->vector == -1 && (this->x - 1) <= FIELD_START_X)
		return (ELEM_REACH_LEFT_SIDE);
	else if (this->vector == 1 && (this->x + 2) >= FIELD_LENGTH)
		return (ELEM_REACH_RIGHT_SIDE);

	return (0);
}
