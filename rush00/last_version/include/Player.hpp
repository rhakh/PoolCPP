/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:07:01 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:07:02 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Object.hpp"

class Player : public Object {
	public:
		Player();
		Player(int x_, int y_);
		Player(const Player &src);
		~Player();

		Player &operator=(const Player &src);

		int processMove(int frn, int pressCode);
};

#endif