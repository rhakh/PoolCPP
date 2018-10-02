#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed &rhs) {
	std::cout << "Copy constructor called" << std::endl;
	this->rawBits = rhs.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &src) {
	std::cout << "Assignation operator called" << std::endl;
	this->rawBits = src.getRawBits();

	return (*this);
}

int			Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;

	return (this->rawBits);
}

void		Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}
