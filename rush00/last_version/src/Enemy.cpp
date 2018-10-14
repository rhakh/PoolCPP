/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:04:27 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:06:07 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() :
Object(ENEMY_COLOUR, BACKWARD_DIRECT, ENEMY_SHAPE, 0, 0, DEF_HP) {}

Enemy::Enemy(int x_, int y_) :
Object(ENEMY_COLOUR, BACKWARD_DIRECT, ENEMY_SHAPE, x_, y_, DEF_HP) {}

Enemy::Enemy(const Enemy &src) : Object(src) {}

Enemy::~Enemy() {}

Enemy &Enemy::operator=(const Enemy &src) {
	Object::operator=(src);
	return *this;
}

int Enemy::processMove(int frn, int pressCode) {
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