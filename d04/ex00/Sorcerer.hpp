#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <string>
#include <iostream>
#include <ostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
	std::string		name;
	std::string		title;

public:
	Sorcerer(std::string _name, std::string _title);
	~Sorcerer();
	Sorcerer(const Sorcerer &src);
	Sorcerer	&operator=(const Sorcerer &src);

	std::string 	getName() const;
	std::string 	getTitle() const;
	void			polymorph(const Victim &src) const;
	// void			polymorph(const Peon &src) const;
};

std::ostream	&operator<<(std::ostream &os, const Sorcerer &src);

#endif // SORCERER_HPP
