#include "Fixed.hpp"
#include <iostream>
#include <sstream>

Fixed	parse_fixed(std::string &str, size_t &i);
Fixed	parse_minor(std::string &str, size_t &i);
Fixed	parse_major(std::string &str, size_t &i);

Fixed	parse_number(std::string &str, size_t &i) {
	std::ostringstream	form;
	std::string			str_num;
	float				f_num;

	while (isspace(str[i]))
		i++;
	while (isdigit(str[i]) || str[i] == '.') {
		form << str[i];
		i++;
	}
	str_num = form.str();
	f_num = atof(str_num.c_str());
	return (Fixed(f_num));
}

Fixed	parse_minor(std::string &str, size_t &i) {
	Fixed	a;
	Fixed	b;
	char	oper;

	a = parse_major(str, i);
	while (i < str.size()) {
		while (isspace(str[i]))
			i++;
		oper = str[i];
		if (oper != '+' && oper != '-')
			return (a);
		i++;
		b = parse_major(str, i);
		if (oper == '+')
			a = a + b;
		else
			a = a - b;
	}
	return (a);
}

Fixed	parse_major(std::string &str, size_t &i) {
	Fixed	a;
	Fixed	b;
	char	oper;

	a = parse_fixed(str, i);
	while (i < str.size()) {
		while (isspace(str[i]))
			i++;
		oper = str[i];
		if (oper != '*' && oper != '/')
			return (a);
		i++;
		b = parse_fixed(str, i);
		if (oper == '/') {
			if (b.getRawBits() == 0) {
				std::cout << "Error. Division by zero." << std::endl;
				exit(1);
			}
			a = a / b;
		}
		else
			a = a * b;
	}
	return (a);
}

Fixed	parse_fixed(std::string &str, size_t &i) {
	Fixed	a;

	while (isspace(str[i]))
		i++;
	if (str[i] == '(')  {
		i++;
		a = parse_minor(str, i);
		if (str[i] == ')')
			i++;
		return (a);
	}
	return (parse_number(str, i));
}

Fixed	eval_expr(std::string &str, size_t &i) {
	return (parse_minor(str, i));
}

Fixed	solve(const char *expr) {
	std::string		str(expr);
	size_t			i = 0;

	Fixed res(eval_expr(str, i));
	return (res);
}

int		main(int argc, char **argv) {
	if (argc == 2)
		std::cout << solve(argv[1]) << std::endl;
	else
		std::cout << "Usage: " << argv[0] << " [arithmetic expretion]" <<std::endl;
	return (0);
}
