/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:13:34 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:14:41 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.hpp"

Star::Star() :
Object(STAR_COLOUR, BACKWARD_DIRECT, STAR_SHAPE, 0, 0, DEF_HP) {}

Star::Star(int x_, int y_) :
Object(STAR_COLOUR, BACKWARD_DIRECT, STAR_SHAPE, x_, y_, DEF_HP) {}

Star::Star(const Star &src) : Object(src) {}

Star::~Star() {}

Star &Star::operator=(const Star &src) {
	Object::operator=(src);
	return *this;
}