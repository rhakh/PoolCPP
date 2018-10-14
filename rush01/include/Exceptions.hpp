/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:32:17 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:34:17 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class TermWinTooSmallException : public std::exception {
	public:
		TermWinTooSmallException();
		TermWinTooSmallException(const TermWinTooSmallException &src);
		~TermWinTooSmallException() throw();
		TermWinTooSmallException &operator=(const TermWinTooSmallException &rhs);
		virtual const char *what() const throw();
};

class OutOfMemoryException : public std::exception {
	public:
		OutOfMemoryException();
		OutOfMemoryException(const OutOfMemoryException &src);
		~OutOfMemoryException() throw();
		OutOfMemoryException &operator=(const OutOfMemoryException &rhs);
		virtual const char *what() const throw();
};