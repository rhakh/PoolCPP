#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <sstream>
#include <iostream>

class Brain {
	int		mass;
	int		volume;

public:
	Brain();
	std::string		identify();
};

#endif // BRAIN_HPP
