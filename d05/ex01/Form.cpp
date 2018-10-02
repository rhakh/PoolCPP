#include "Form.hpp"

Form::Form()
	: name("noname"), gradeRequiredToSign(LOWEST_GRADE), gradeRequiredToExecute(LOWEST_GRADE) {
	this->isSigned = 0;
}

Form::Form(const Form &src)
	: name(src.getName()),
	gradeRequiredToSign(src.getGradeToSign()),
	gradeRequiredToExecute(src.getGradeToExecute()) {
	this->isSigned = src.getSigned();
}

Form::~Form() {}

Form		&Form::operator=(const Form &rhs) {
	this->isSigned = rhs.getSigned();
	return (*this);
}

Form::Form(const std::string &_name, int _signGrade, int _execGrade)
	: name(_name), gradeRequiredToSign(_signGrade), gradeRequiredToExecute(_execGrade) {
	this->isSigned = 0;
}

std::string		Form::getName() const {
	return (this->name);
}

int				Form::getGradeToSign() const {
	return (this->gradeRequiredToSign);
}

int				Form::getGradeToExecute() const {
	return (this->gradeRequiredToExecute);
}

bool			Form::getSigned() const {
	return (this->isSigned);
}

std::ostream	&operator<<(std::ostream &os, const Form &fr) {
	os << fr.getName() << " form is " << ((fr.getSigned()) ? "signed. " : "not signed. ")
		<< "Grade for sign: " << fr.getGradeToSign()
		<< ", grade for execute " << fr.getGradeToExecute();
	return (os);
}

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src) {
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException	&Form::GradeTooHighException::operator=(const GradeTooHighException &rhs) {
	UNUSED(rhs);
	return (*this);
}

const char		*Form::GradeTooHighException::what() const throw() {
	return (ERROR_GRADE_TOO_HIGHT);
}

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src) {
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException	&Form::GradeTooLowException::operator=(const GradeTooLowException &rhs) {
	UNUSED(rhs);
	return (*this);
}

const char		*Form::GradeTooLowException::what() const throw() {
	return (ERROR_GRADE_TOO_LOW);
}
