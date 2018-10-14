/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:04:14 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:04:23 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Object.hpp"

class Enemy : public Object {
	public:
		Enemy();
		Enemy(int x_, int y_);
		Enemy(const Enemy &src);
		~Enemy();

		Enemy &operator=(const Enemy &src);

		int processMove(int frn, int pressCode);
};

#endif