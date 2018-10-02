#include "Brain.hpp"
#include "Human.hpp"
#include <iostream>
#include <string>

int		main(void) {
	Human	bob;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}
