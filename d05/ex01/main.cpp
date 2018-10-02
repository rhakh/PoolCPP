#include "Bureaucrat.hpp"

int		main() {
	Bureaucrat	hermes("Hermes", 80);
	Bureaucrat	conrad;
	Bureaucrat	tmp;

	conrad = hermes;
	std::cout << hermes << std::endl;
	std::cout << conrad << std::endl;
	std::cout << tmp << std::endl;
	try {
		hermes.incGrade(150);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		hermes.decGrade(150);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
