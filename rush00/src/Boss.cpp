#include "Boss.hpp"

Boss::Boss(void)
	: Element() {

	this->vector = -1;
	this->color = BOSS_COLOR;
	this->form = BOSS_FORM;
	this->life = 3;
	return;
}

Boss::Boss(int _y, int _x)
	: Element(_y, _x) {

	this->vector = -1;
	this->color = BOSS_COLOR;
	this->form = BOSS_FORM;
	this->life = 3;
	return;
}

Boss::Boss(Boss const &src)
{
	*this = src;
	return;
}

Boss::~Boss(void) {

}

Boss	&Boss::operator=(Boss const &src)
{
	this->x = src.getX();
	this->y = src.getY();
	this->vector = src.getVector();
	this->color = src.getColor();
	this->form = src.getForm();
	this->life = src.getLife();
	return *this;
}

void	Boss::printOut(WINDOW *win) {
	wattron(win, COLOR_PAIR(this->color));
	mvwaddch(win, this->y, this->x, this->form | A_BOLD);
	if (this->x + 1 < FIELD_LENGTH)
		mvwaddch(win, this->y, this->x + 1, ']' | A_BOLD);
	wattroff(win, COLOR_PAIR(this->color));
}


int	Boss::doMove(int btnPressCode, int frameNumber) {
	int		random;

	UNUSED(btnPressCode);
	
	if (frameNumber % 2 == 0)
		return (0);

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

	random = rand() % 100;
	if (random < 3)
		return (ENEMY_SHOT);

	return (0);
}
