/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:00:55 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:03:44 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"

Boss::Boss() :
Object(BOSS_COLOUR, BACKWARD_DIRECT, BOSS_SHAPE, 0, 0, BOSS_HP) {}

Boss::Boss(int x_, int y_) :
Object(BOSS_COLOUR, BACKWARD_DIRECT, BOSS_SHAPE, x_, y_, BOSS_HP) {}

Boss::Boss(const Boss &src) : Object(src) {}

Boss::~Boss() {}

Boss &Boss::operator=(const Boss &src) {
	Object::operator=(src);
	return *this;
}

int Boss::processMove(int frn, int pressCode) {
	int random = rand() % 100;
	int ret;

	if (frn % 2 == 0)
		return (0);
	
	if (random >= 0 && random < 3) {
		if (this->getY() - 1 > PL_START_Y)
			this->setY(this->getY() - 1);
	}
	else if (random >= 3 && random < 5) {
		if (this->getY() + 1 < pl_height)
			this->setY(this->getY() + 1);
	}
	ret = Object::processMove(frn, pressCode);

	if (ret)
		return (ret);

	if (random < 3)
		return (ENEMY_SHOT);

	return (0);
}
