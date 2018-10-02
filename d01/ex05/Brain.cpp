#include "Brain.hpp"

Brain::Brain() {
	mass = rand() % 3;
	volume = rand() % 30;
}

std::string		Brain::identify() {
	std::stringstream	format;

	format << std::hex << this;
	return (format.str());
}
