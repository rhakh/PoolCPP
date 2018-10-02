#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed &rhs) {
	std::cout << "Copy constructor called" << std::endl;
	this->rawBits = rhs.getRawBits();
}

Fixed::Fixed(int value) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << this->fraction);
}

Fixed::Fixed(float value) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(value * (1 << this->fraction)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &src) {
	std::cout << "Assignation operator called" << std::endl;
	this->rawBits = src.getRawBits();

	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();

	return (os);
}

int			Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;

	return (this->rawBits);
}

void		Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}

int		Fixed::toInt() const {
	return (this->rawBits >> this->fraction);
}

float		Fixed::toFloat() const {
	return ((float)this->rawBits / (1 << this->fraction));
}
