#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#include "Form.hpp"
class Form;

#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

#define ERROR_GRADE_TOO_LOW		"grade to low"
#define ERROR_GRADE_TOO_HIGHT	"grade to hight"

#define UNUSED(var)			{(void)(var);}

class Bureaucrat {
	const std::string	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();
	Bureaucrat		&operator=(const Bureaucrat &rhs);

	Bureaucrat(const std::string &_name, int _grade);
	std::string		getName() const;
	int				getGrade() const;
	void			incGrade(int value);
	void			decGrade(int value);

	void			signForm(Form &from);

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException();
		GradeTooHighException(const GradeTooHighException &src);
		~GradeTooHighException() throw();
		GradeTooHighException	&operator=(const GradeTooHighException &rhs);
		virtual const char		*what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException();
		GradeTooLowException(const GradeTooLowException &src);
		~GradeTooLowException() throw();
		GradeTooLowException	&operator=(const GradeTooLowException &rhs);
		virtual const char		*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &br);

#endif // BUREAUCRAT_HPP
