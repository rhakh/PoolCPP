#include "Enemy.hpp"

Enemy::Enemy(void)
	: Element() {

	this->vector = -1;
	this->color = ENEMY_COLOR;
	this->form = ENEMY_FORM;
}

Enemy::~Enemy(void) {

}

Enemy::Enemy(int _y, int _x)
	: Element(_y, _x) {

	this->vector = -1;
	this->color = ENEMY_COLOR;
	this->form = ENEMY_FORM;
}

Enemy::Enemy(Enemy const &src)
{
	*this = src;
	return;
}

Enemy&	Enemy::operator=(const Enemy &src)
{
	this->x = src.getX();
	this->y = src.getY();
	this->vector = src.getVector();
	this->color = src.getColor();
	this->form = src.getForm();
	this->life = src.getLife();
	return *this;
}

int	Enemy::doMove(int btnPressCode, int frameNumber) {
	int		random;

	UNUSED(btnPressCode);

	if (frameNumber % 2 == 0)
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

	random = rand() % 100;
	if (random < 3)
		return (ENEMY_SHOT);

	return (0);
}
