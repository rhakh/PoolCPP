#include "Fixed.hpp"

Fixed::Fixed() {
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed &rhs) {
	this->rawBits = rhs.getRawBits();
}

Fixed::Fixed(int value) {
	this->setRawBits(value << this->fraction);
}

Fixed::Fixed(float value) {
	this->setRawBits(roundf(value * (1 << this->fraction)));
}

Fixed::~Fixed() {
}

Fixed	&Fixed::operator=(const Fixed &src) {
	this->rawBits = src.getRawBits();

	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();

	return (os);
}

int			Fixed::getRawBits(void) const {
	return (this->rawBits);
}

void		Fixed::setRawBits(const int raw) {
	this->rawBits = raw;
}

int		Fixed::toInt() const {
	return (this->rawBits >> this->fraction);
}

float		Fixed::toFloat() const {
	return ((float)this->rawBits / (1 << this->fraction));
}

bool	Fixed::operator<(const Fixed &b) const {
	return (this->toFloat() < b.toFloat());
}

bool	Fixed::operator>(const Fixed &b) const {
	return (this->toFloat() > b.toFloat());
}
bool	Fixed::operator>=(const Fixed &b) const {
	return (this->toFloat() >= b.toFloat());
}

bool	Fixed::operator<=(const Fixed &b) const {
	return (this->toFloat() <= b.toFloat());
}

bool	Fixed::operator==(const Fixed &b) const {
	return (this->toFloat() == b.toFloat());
}

bool	Fixed::operator!=(const Fixed &b) const {
	return (this->toFloat() != b.toFloat());
}

Fixed	Fixed::operator+(const Fixed &b) {
	Fixed	result;

	result.setRawBits(this->getRawBits() + b.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &b) {
	Fixed	result;

	result.setRawBits(this->getRawBits() - b.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &b) {
	Fixed	result;

	result.setRawBits((this->getRawBits() * b.getRawBits()) / (1 << this->fraction));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &b) {
	Fixed	result;

	result.setRawBits((this->getRawBits() * (1 << this->fraction)) / b.getRawBits());
	return (result);
}

Fixed	&Fixed::operator++() {
	this->rawBits++;

	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	++(*this);
	return(tmp);
}

Fixed	&Fixed::operator--() {
	this->rawBits--;

	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	--(*this);
	return(tmp);
}

Fixed		&Fixed::min(Fixed &lhs, Fixed &rhs) {
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs) {
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed		&Fixed::max(Fixed &lhs, Fixed &rhs) {
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs) {
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}
