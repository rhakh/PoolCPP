#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>
#include <iostream>
#include <ostream>

class Victim {
	std::string		name;

public:
	Victim(std::string _name);
	virtual ~Victim();
	Victim(const Victim &src);

	Victim		&operator=(const Victim &src);
	std::string	getName() const;
	void		getPolymorphed() const;
};

std::ostream	&operator<<(std::ostream &os, const Victim &src);

#endif // VICTIM_HPP
