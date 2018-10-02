#include <iostream>
#include <string>
#include <iomanip>
#include "String.hpp"

void	convertion(const char *c_str) {
	String			str(c_str);

	try {
		char	c_out;

		c_out = static_cast<char>(str);
		std::cout << "char: '" << c_out << "'" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}

	try {
		int		i_out;

		i_out = static_cast<int>(str);
		std::cout << "int: " << i_out << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}

	try {
		float	f_out;

		f_out = static_cast<float>(str);
		std::cout << "float: " << std::setprecision(1) << std::fixed << f_out  << 'f' << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}

	try {
		double	d_out;

		d_out = static_cast<double>(str);
		std::cout << "double: " << std::setprecision(1) << std::fixed << d_out << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

int		main(int argc, char **argv) {
	std::string		str;

	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " [numeric value]" << std::endl;
		return (0);
	}
	convertion(argv[1]);

	return (0);
}
