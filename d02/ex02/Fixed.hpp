#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
	int					rawBits;
	const static int	fraction = 8;

public:
	Fixed();
	Fixed(int _rawBits);
	Fixed(float _rawBits);
	Fixed(const Fixed &src);
	~Fixed();
	Fixed		&operator=(const Fixed &rhs);

	int			getRawBits(void) const;
	void		setRawBits(const int raw);

	int			toInt() const;
	float		toFloat() const;

	bool	operator<(const Fixed &b) const;
	bool	operator>(const Fixed &b) const;
	bool	operator>=(const Fixed &b) const;
	bool	operator<=(const Fixed &b) const;
	bool	operator==(const Fixed &b) const;
	bool	operator!=(const Fixed &b) const;

	Fixed	operator+(const Fixed &b);
	Fixed	operator-(const Fixed &b);
	Fixed	operator*(const Fixed &b);
	Fixed	operator/(const Fixed &b);

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	static	Fixed		&min(Fixed &lhs, Fixed &rhs);
	static	const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
	static	Fixed		&max(Fixed &lhs, Fixed &rhs);
	static	const Fixed	&max(const Fixed &lhs, const Fixed &rhs);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &dt);

#endif // FIXED_HPP
