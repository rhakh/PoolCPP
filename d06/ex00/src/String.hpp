#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Exceptions.hpp"

class String {
	const std::string		str;

public:
	String();
	String(const String &src);
	~String();
	String		&operator=(const String &rhs);

	String(const char *str);
	std::string		getStr() const ;

	/* conversions */
	operator	int() const;
	operator	char() const;
	operator	float() const;
	operator	double() const;
};

#endif // STRING_HPP
