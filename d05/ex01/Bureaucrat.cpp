#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("noname"), grade(LOWEST_GRADE) {

}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: name(src.getName()), grade(src.getGrade()) {

}

Bureaucrat::~Bureaucrat() {}

Bureaucrat		&Bureaucrat::operator=(const Bureaucrat &rhs) {
	this->grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade)
	: name(_name) {
	if (_grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = _grade;
}

std::string		Bureaucrat::getName() const {
	return (name);
}

int				Bureaucrat::getGrade() const {
	return (grade);
}

void			Bureaucrat::incGrade(int value) {
	if ((grade - value) < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	grade -= value;
}

void			Bureaucrat::decGrade(int value) {
	if ((grade + value) > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	grade += value;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &br) {
	os << br.getName() << ", bureaucrat grade " << br.getGrade();
	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src) {
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException &rhs) {
	UNUSED(rhs);
	return (*this);
}

const char		*Bureaucrat::GradeTooHighException::what() const throw() {
	return (ERROR_GRADE_TOO_HIGHT);
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src) {
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException &rhs) {
	UNUSED(rhs);
	return (*this);
}

const char		*Bureaucrat::GradeTooLowException::what() const throw() {
	return (ERROR_GRADE_TOO_LOW);
}
