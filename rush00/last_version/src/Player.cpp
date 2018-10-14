/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:08:36 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:11:08 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() :
Object(PLAYER_COLOUR, BACKWARD_DIRECT, PLAYER_SHAPE, 0, 0, PLAYER_HP) {}

Player::Player(int x_, int y_) :
Object(PLAYER_COLOUR, BACKWARD_DIRECT, PLAYER_SHAPE, x_, y_, PLAYER_HP) {}

Player::Player(const Player &src) : Object(src) {}

Player::~Player() {}

Player   &Player::operator=(const Player &src) {
	Object::operator=(src);
	return *this;
}

int     Player::processMove(int frn, int pressCode) {
	(void)(frn);

	if (pressCode == ERR)
		return 0;
	else if (pressCode == KEY_UP && (this->getY() - 1) > PL_START_Y)
		this->setY(this->getY() - 1);
	else if (pressCode == KEY_DOWN && (this->getY() + 2) < pl_height)
		this->setY(this->getY() + 1);
	else if (pressCode == KEY_RIGHT && (this->getX() + 2) < pl_length)
		this->setX(this->getX() + 1);
	else if (pressCode == KEY_LEFT && (this->getX() - 1) > PL_START_X)
		this->setX(this->getX() - 1);
	else if (pressCode == ' ')
		return PLAYER_SHOT;

	return 0;
}