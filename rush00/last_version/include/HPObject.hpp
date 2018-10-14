/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HPObject.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:15:30 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:15:31 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HP_OBJECT_HPP
#define HP_OBJECT_HPP

#include "Object.hpp"

class HPObject : public Object {
	public:
		HPObject();
		HPObject(int x_, int y_);
		HPObject(const HPObject &src);
		~HPObject();
		HPObject &operator=(const HPObject &src);

		int processMove(int frn, int pressCode);
};

#endif