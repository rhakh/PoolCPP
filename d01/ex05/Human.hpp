#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>
#include "Brain.hpp"

class Human {
	Brain		brain;

public:
	std::string		identify();
	Brain			&getBrain();
};

#endif // HUMAN_HPP
