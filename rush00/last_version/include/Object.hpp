/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 22:59:43 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 22:59:43 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <ncurses.h>
#include <cstdlib>
#include "main.hpp"

class Object {
	public:
		Object();
		Object(int x_, int y_);
		Object(int colour_, int direction_, char shape_, int x_, int y_, int hp_);
		Object(const Object &src);
		virtual ~Object();

		virtual Object &operator=(const Object &src);

		virtual int processMove(int frn, int pressCode);
		virtual void print(WINDOW *win);

		int getX() const;
		int getY() const;
		int getColour() const;
		int getDirection() const;
		int getShape() const;
		int getHP() const;
		void setX(int x);
		void setY(int y);
		void setHP(int hp);

	protected:
		const int colour, direction;
		const char shape;
		int x, y, hp;
};

#endif