/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 22:59:46 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:00:12 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"


void Object::print(WINDOW *win) {
	wattron(win, COLOR_PAIR(this->colour));
	mvwaddch(win, this->y, this->x, this->shape | A_BOLD);
	wattroff(win, COLOR_PAIR(this->colour));
}

int Object::getX() const {
	return this->x;
}

int Object::getY() const {
	return this->y;
}

int Object::getColour() const {
	return this->colour;
}

int Object::getDirection() const {
	return this->direction;
}

int Object::getShape() const {
	return this->shape;
}

int Object::getHP() const {
	return this->hp;
}

void Object::setHP(int hp) {
	this->hp = hp;
}

void Object::setX(int x) {
	this->x = x;
}

void Object::setY(int y) {
	this->y = y;
}

Object::Object() :
colour(DEF_COLOUR), direction(DEF_DIRECT), shape(DEF_SHAPE), x(0), y(0), hp(DEF_HP) {}

Object::Object(int x_, int y_) :
colour(DEF_COLOUR), direction(DEF_DIRECT), shape(DEF_SHAPE), x(x_), y(y_), hp(DEF_HP)
{}

Object::Object(int colour_, int direction_, char shape_, int x_, int y_, int hp_) :
colour(colour_), direction(direction_), shape(shape_), x(x_), y(y_), hp(hp_)
{}

Object::Object(const Object &src) :
colour(DEF_COLOUR), direction(DEF_DIRECT), shape(DEF_SHAPE) {
	*this = src;
}

Object::~Object() {}

Object &Object::operator=(const Object &src) {
	this->x = src.x;
	this->y = src.y;
	this->hp = src.hp;

	return *this;
}

/*
 * return 0 - ok, otherwise look at GameEvents
 */
int Object::processMove(int frn, int pressCode) {
	(void)(pressCode);
	(void)(frn);

	if (this->getDirection() == BACKWARD_DIRECT && (this->getX() - 1 > PL_START_X))
		// this->x--;
		this->setX(x - 1);
	else if (this->getDirection() == FORWARD_DIRECT && (this->getX() + 2 < pl_length))
		// this->x++;
		this->setX(x + 1);
	else if (this->getDirection() == BACKWARD_DIRECT && (this->getX() - 1 <= PL_START_X))
		return OBJECT_REACH_LEFT_SIDE;
	else if (this->getDirection() == FORWARD_DIRECT && (this->getX() + 2 >= pl_length))
		return OBJECT_REACH_RIGHT_SIDE;

	return (0);
}