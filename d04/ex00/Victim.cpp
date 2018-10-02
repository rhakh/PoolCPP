#include "Victim.hpp"

Victim::Victim(std::string _name) {
	name = _name;
	std::cout << "Some random victim called " + name + " just popped !" << std::endl;
}

Victim::~Victim() {
	std::cout << "Victim " + name + " just died for no apparent reason !" << std::endl;
}

Victim::Victim(const Victim &src) {
	name = src.getName();
	std::cout << "Some random victim called " + name + " just popped !" << std::endl;
}

Victim		&Victim::operator=(const Victim &src) {
	name = src.getName();
	return (*this);
}

std::string		Victim::getName() const {
	return (name);
}

std::ostream	&operator<<(std::ostream &os, const Victim &src) {
	os << "I'm " + src.getName() + " and I like otters !" << std::endl;
	return (os);
}

void		Victim::getPolymorphed() const {
	std::cout << name + " has been turned into a cute little sheep !" << std::endl;
}
