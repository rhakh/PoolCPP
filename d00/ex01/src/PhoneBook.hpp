#ifndef _PHONE_BOOK_HPP
#define _PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

#define ADD_COMMAND		"ADD"
#define SEARCH_COMMAND	"SEARCH"
#define EXIT_COMMAND	"EXIT"

const int	contactsSize = 8;

const std::string	columnTitles[4] = {
	"INDEX", "FIRST NAME", "LAST NAME", "NICKNAME"
};

class PhoneBook {
	class Contact	contacts[contactsSize];
	int				iter;

public:
	PhoneBook();
	void	add();
	void	search();
};

#endif /* _PHONE_BOOK_HPP */
