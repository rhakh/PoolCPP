#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

#define ERROR_GRADE_TOO_LOW		"Error: Bureaucrat grade to low"
#define ERROR_GRADE_TOO_HIGHT	"Error: Bureaucrat grade to hight"

#define UNUSED(var)			{(void)(var);}

class Form {
	bool	isSigned;
	const int		gradeRequiredToSign;
	const int		gradeRequiredToExecute;
	const std::string	name;

public:
	Form();
	Form(const Form &src);
	~Form();
	Form		&operator=(const Form &rhs);

	Form(const std::string &_name, int _grade);
	std::string		getName() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;
	bool			getSigned() const;

	void			beSigned();

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
