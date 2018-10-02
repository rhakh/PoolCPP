#include "Peon.hpp"

Peon::Peon(std::string _name) : Victim (_name) {
	name = _name;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(const Peon &src) : Victim(src) {
	name = src.getName();
	std::cout << "Zog zog." << std::endl;
}

Peon		&Peon::operator=(const Peon &src) {
	name = src.getName();
	return (*this);
}

std::string		Peon::getName() const {
	return (name);
}

std::ostream	&operator<<(std::ostream &os, const Peon &src) {
	os << "I'm " + src.getName() + " and I like otters !" << std::endl;
	return (os);
}

void		Peon::getPolymorphed() const {
	std::cout << name + " has been turned into a pink pony !" << std::endl;
}
