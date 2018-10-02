#include "Player.hpp"

Player::Player(void)
	: Element() {
	this->color = PLAYER_COLOR;
	this->form = PLAYER_FORM;
	return;
}

Player::Player(int _y, int _x)
	: Element(_y, _x) {
	this->life = DEFAULT_PLAYER_LIFE;
	this->color = PLAYER_COLOR;
	this->form = PLAYER_FORM;
	return;
}

Player::Player(const Player & src)
{
	*this = src;
	return;
}

Player::~Player(void) {

}

Player&	Player::operator=(const Player & src)
{
	this->x = src.getX();
	this->y = src.getY();
	this->vector = src.getVector();
	this->color = src.getColor();
	this->form = src.getForm();
	this->life = src.getLife();
	return *this;
}

int	Player::doMove(int btnPressCode, int frameNumber) {
	UNUSED(frameNumber);
	if (btnPressCode == ERR)
		return (0);
	if (btnPressCode == KEY_UP && (this->y - 1) > FIELD_START_Y) {
		this->y--;
	}
	else if (btnPressCode == KEY_DOWN && (this->y + 2) < FIELD_HEIGHT) {
		this->y++;
	}
	else if (btnPressCode == KEY_RIGHT && (this->x + 2) < FIELD_LENGTH) {
		this->x++;
	}
	else if (btnPressCode == KEY_LEFT && (this->x - 1) > FIELD_START_X) {
		this->x--;
	}
	else if (btnPressCode == ' ')
		return (PLAYER_PRESS_SPACE);
	return (0);
}
