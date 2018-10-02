#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static void strtrim(std::string &s) {
	std::string::iterator	i;

	// ltrim
	for (i = s.begin(); i != s.end() && std::isspace(*i); i++)
		;
	s.erase(s.begin(), i);

	// rtrim
	i = s.end();
	i--;
	for (; i != s.begin() && std::isspace(*i); i--)
		;
	i++;
	s.erase(i, s.end());
}

int		main(void) {
	PhoneBook	phoneBook;
	std::string	command;

	while (1) {
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			std::cout << "EOF was found" << std::endl;
			std::cin.clear();
			freopen(NULL, "rw", stdin);
			continue;
		}

		strtrim(command);
		if (!command.compare(ADD_COMMAND))
			phoneBook.add();
		else if (!command.compare(SEARCH_COMMAND))
			phoneBook.search();
		else if (!command.compare(EXIT_COMMAND))
			return (0);
	}
	return (0);
}

//todo: do some with empty lines
