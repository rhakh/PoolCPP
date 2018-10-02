#include "String.hpp"

String::String() {

}

String::String(const String &rhs)
	: str(rhs.getStr()) {

}

String::~String() {
}

String	&String::operator=(const String &src) {
	(void)(src);
	return (*this);
}

String::String(const char *_str)
	: str(_str) {

}

std::string		String::getStr() const {
	return (str);
}

String::operator	int() const {
	int		out;

	try {
		out = std::stoi(this->str);
	}
	catch (std::exception &e) {
		throw ImpossibleException();
	}

	return (out);
}

String::operator	char() const {
	char	out;

	try {
		out = std::stoi(this->str);
	}
	catch (std::exception &e) {
		throw ImpossibleException();
	}

	if (!std::isprint(out))
		throw NonDisplayableException();

	return (out);
}

String::operator	float() const {
	float	out;
	char	*str_end;

	try {
		out = std::strtod(this->str.c_str(), &str_end);
		if (this->str.c_str() == str_end)
			throw ImpossibleException();
	}
	catch (std::exception &e) {
		throw ImpossibleException();
	}

	return (out);
}

String::operator	double() const {
	double	out;
	char	*str_end;

	try {
		out = std::strtod(this->str.c_str(), &str_end);
		if (this->str.c_str() == str_end)
			throw ImpossibleException();
	}
	catch (std::exception &e) {
		throw ImpossibleException();
	}

	return (out);
}
