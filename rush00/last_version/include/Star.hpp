/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:12:16 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:14:44 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_HPP
# define STAR_HPP

# include "Object.hpp"

class Star : public Object {
	public:
		Star();
		Star(int x_, int y_);
		Star(const Star &src);
		~Star();

		Star &operator=(const Star &src);
};

#endif