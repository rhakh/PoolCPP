#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main() {
	std::cout << "---------- BUREAUCRATS ----------" << std::endl;
	{
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
	}
	std::cout << "---------- FORMS ----------" << std::endl;
	{
		Form	form("Bill", 100, 50);
		Form	formC(form);
		Form	formE;
		Bureaucrat	b1("Conor", 110);
		Bureaucrat	b2("Conor", 90);

		std::cout << form << std::endl;
		std::cout << formC << std::endl;
		std::cout << formE << std::endl;

		try {
			b1.signForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			b2.signForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			b2.signForm(form);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
	}

	return (0);
}
