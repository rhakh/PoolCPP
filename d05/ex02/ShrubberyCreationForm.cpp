#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : Form() {
    this->setTarget(target);
}