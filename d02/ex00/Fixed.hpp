#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
	int					rawBits;
	const static int	fraction = 8;

public:
	Fixed();
	Fixed(const Fixed &src);
	~Fixed();
	Fixed		&operator=(const Fixed &rhs);

	int			getRawBits(void) const;
	void		setRawBits(const int raw);
};

#endif // FIXED_HPP
