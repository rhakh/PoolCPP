/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:00:41 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:00:52 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_HPP
# define BOSS_HPP

# include "Object.hpp"

class Boss : public Object {
	public:
		Boss();
		Boss(int x_, int y_);
		Boss(const Boss &src);
		~Boss();

		Boss &operator=(const Boss &src);

		int processMove(int frn, int pressCode);
};

#endif