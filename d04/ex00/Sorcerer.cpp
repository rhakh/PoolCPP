#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string _name, std::string _title) {
	name = _name;
	title = _title;
	std::cout << name + ", " + title + ", is born !" << std::endl;
}

Sorcerer::~Sorcerer() {
	std::cout << name + ", " + title +
		", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &src) {
	name = src.getName();
	title = src.getTitle();
	std::cout << name + ", " + title + ", is born !" << std::endl;
}

Sorcerer	&Sorcerer::operator=(const Sorcerer &src) {
	name = src.getName();
	title = src.getTitle();
	return (*this);
}

std::string		Sorcerer::getName() const {
	return (name);
}

std::string		Sorcerer::getTitle() const {
	return (title);
}

std::ostream	&operator<<(std::ostream &os, const Sorcerer &src) {
	os << "I am " + src.getName() + ", " + src.getTitle() + ", and I like ponies !" << std::endl;
	return (os);
}

void		Sorcerer::polymorph(const Victim &src) const {
	src.getPolymorphed();
}

void		Sorcerer::polymorph(const Peon &src) const {
	src.getPolymorphed();
}
