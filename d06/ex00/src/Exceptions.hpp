#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>
#include <iostream>

#define ERROR_NAN	"nan"
#define ERROR_NON_DISPLAYABLE	"Non displayable"
#define ERROR_IMPOSSIBLE	"impossible"

#define UNUSED(var)			{(void)(var);}

class NotANumberException : public std::exception {
public:
	NotANumberException();
	NotANumberException(const NotANumberException &src);
	~NotANumberException() throw();
	NotANumberException	&operator=(const NotANumberException &rhs);
	virtual const char		*what() const throw();
};



class NonDisplayableException : public std::exception {
public:
	NonDisplayableException();
	NonDisplayableException(const NonDisplayableException &src);
	~NonDisplayableException() throw();
	NonDisplayableException	&operator=(const NonDisplayableException &rhs);
	virtual const char		*what() const throw();
};



class ImpossibleException : public std::exception {
public:
	ImpossibleException();
	ImpossibleException(const ImpossibleException &src);
	~ImpossibleException() throw();
	ImpossibleException	&operator=(const ImpossibleException &rhs);
	virtual const char		*what() const throw();
};


#endif // EXCEPTION_HPP
