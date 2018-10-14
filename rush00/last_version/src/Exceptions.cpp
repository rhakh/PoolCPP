/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:32:47 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:33:58 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

TermWinTooSmallException::TermWinTooSmallException() {}

TermWinTooSmallException::TermWinTooSmallException(const TermWinTooSmallException &src) {
	*this = src;
}

TermWinTooSmallException::~TermWinTooSmallException() throw() {}

TermWinTooSmallException &TermWinTooSmallException::operator=(const TermWinTooSmallException &rhs) {
	(void)rhs;
	return *this;
}

const char *TermWinTooSmallException::what() const throw() {
	return ("Terminal size too small");
}

OutOfMemoryException::OutOfMemoryException() {}

OutOfMemoryException::OutOfMemoryException(const OutOfMemoryException &src) {
	*this = src;
}

OutOfMemoryException::~OutOfMemoryException() throw() {}

OutOfMemoryException &OutOfMemoryException::operator=(const OutOfMemoryException &rhs) {
	(void)(rhs);
	return *this;
}

const char *OutOfMemoryException::what() const throw() {
	return ("Out of memory");
}