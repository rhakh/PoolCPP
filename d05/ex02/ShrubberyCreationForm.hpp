#ifndef SHRUB_HPP
#define SHRUB_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm   &operator=(const ShrubberyCreationForm &src);

    void execute(const Bureaucrat &exec) const;
};

#endif // SHRUB_HPP