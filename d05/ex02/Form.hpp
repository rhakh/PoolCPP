#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

#define ERROR_GRADE_TOO_LOW		"grade to low"
#define ERROR_GRADE_TOO_HIGHT	"grade to hight"

#define UNUSED(var)			{(void)(var);}

class Form {
	const std::string	name;
	const int		signGrade;
	const int		execGrade;
	bool	isSigned;

public:
	Form();
	Form(const Form &src);
	~Form();
	Form		&operator=(const Form &rhs);

	Form(const std::string &_name, int _signGrade, int _execGrade);
	std::string		getName() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;
	bool			getSigned() const;

	void			beSigned(Bureaucrat &br);

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

std::ostream	&operator<<(std::ostream &os, const Form &br);

#endif // FORM_HPP
