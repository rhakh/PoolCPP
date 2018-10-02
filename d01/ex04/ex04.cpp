#include <iostream>
#include <string>

int		main(void) {
	std::string	str("HI THIS IS BRAIN");
	std::string	&lstr = str;
	std::string	*pstr = &str;

	std::cout << lstr << std::endl;
	std::cout << *pstr << std::endl;

	return (0);
}
