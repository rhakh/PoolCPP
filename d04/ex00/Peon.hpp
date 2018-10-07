#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include <string>
#include <ostream>

#include "Victim.hpp"

class Peon : public Victim {

public:
	Peon(std::string _name);
	virtual ~Peon();
	Peon(const Peon &src);

	Peon		&operator=(const Peon &src);
	std::string	getName() const;
	void		getPolymorphed() const;
};

std::ostream	&operator<<(std::ostream &os, const Peon &src);

#endif // PEON_HPP
