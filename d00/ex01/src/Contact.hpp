#ifndef _CONTACT_HPP
#define _CONTACT_HPP

#include <string>
#include <iostream>
#include <sstream>

enum contactFields_e {
	firstName,
	lastName,
	nickname,
	login,
	postalAddress,
	email,
	phoneNumber,
	birthdayDate,
	favoriteMeal,
	underwearColor,
	darkestSecret,
	lastField
};

const std::string	fieldNames[11] = {
	"First name",
	"Last name",
	"Nickname",
	"Login",
	"Postal address",
	"Email",
	"Phone number",
	"Birthday date",
	"Favorite meal",
	"Underwear color",
	"Darkest secret"
};

class Contact {
	std::string	fields[11];

public:
	Contact();

	void	printContact() const;
	void	fill();
	std::string	&getField(contactFields_e = firstName);

};

#endif /* _CONTACT_HPP */
