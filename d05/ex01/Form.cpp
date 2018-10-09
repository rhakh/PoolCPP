#include "Form.hpp"

Form::Form() :
name("noname"), signGrade(LOWEST_GRADE), execGrade(LOWEST_GRADE)
{
	this->isSigned = false;
}

Form::Form(const Form &src) :
name(src.getName()), signGrade(src.getGradeToSign()), execGrade(src.getGradeToExecute())
{
	this->isSigned = src.getSigned();
}

Form::~Form() {}

Form	&Form::operator=(const Form &rhs) {
	this->isSigned = rhs.getSigned();
	return (*this);
}

Form::Form(const std::string &_name, int _signGrade, int _execGrade) :
name(_name), signGrade(_signGrade), execGrade(_execGrade)
{
	this->isSigned = false;

	if (_signGrade > LOWEST_GRADE || _execGrade > LOWEST_GRADE)
		throw Form::GradeTooLowException();

	if (_signGrade < HIGHEST_GRADE || _execGrade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

std::string	Form::getName() const {
	return (this->name);
}

int	Form::getGradeToSign() const {
	return (this->signGrade);
}

int	Form::getGradeToExecute() const {
	return (this->execGrade);
}

bool	Form::getSigned() const {
	return (this->isSigned);
}

std::ostream	&operator<<(std::ostream &os, const Form &fr) {
	os << fr.getName() << " form is " << ((fr.getSigned()) ? "signed, " : "not signed, ")
		<< "sign grade: " << fr.getGradeToSign()
		<< ", exec grade: " << fr.getGradeToExecute();
	return (os);
}

void	Form::beSigned(Bureaucrat &br) {
	if (this->getSigned()) {
		std::cout << "Form '" << this->name
					<< "' already signed." << std::endl;
		return ;
	}
	
	if (br.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	else
		std::cout << "Form '" << this->name
					<< "' signed by '" << br.getName()
					<< "' bureaucrat." << std::endl;
	this->isSigned = true;
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

const char	*Form::GradeTooHighException::what() const throw() {
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

const char	*Form::GradeTooLowException::what() const throw() {
	return (ERROR_GRADE_TOO_LOW);
}
