#include "Exceptions.hpp"

NotANumberException::NotANumberException() {}

NotANumberException::NotANumberException(const NotANumberException &src) {
	*this = src;
}

NotANumberException::~NotANumberException() throw() {}

NotANumberException	&NotANumberException::operator=(const NotANumberException &rhs) {
	UNUSED(rhs);
	return (*this);
}

const char		*NotANumberException::what() const throw() {
	return (ERROR_NAN);
}



NonDisplayableException::NonDisplayableException() {}

NonDisplayableException::NonDisplayableException(const NonDisplayableException &src) {
	*this = src;
}

NonDisplayableException::~NonDisplayableException() throw() {}

NonDisplayableException	&NonDisplayableException::operator=(const NonDisplayableException &rhs) {
	UNUSED(rhs);
	return (*this);
}

const char		*NonDisplayableException::what() const throw() {
	return (ERROR_NON_DISPLAYABLE);
}



ImpossibleException::ImpossibleException() {}

ImpossibleException::ImpossibleException(const ImpossibleException &src) {
	*this = src;
}

ImpossibleException::~ImpossibleException() throw() {}

ImpossibleException	&ImpossibleException::operator=(const ImpossibleException &rhs) {
	UNUSED(rhs);
	return (*this);
}

const char		*ImpossibleException::what() const throw() {
	return (ERROR_IMPOSSIBLE);
}
