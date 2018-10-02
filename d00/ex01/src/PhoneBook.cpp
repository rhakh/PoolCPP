#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	iter = 0;
}

void	PhoneBook::add() {
	if (iter >= contactsSize) {
		std::cout << "The Phone book are full." << std::endl;
		return ;
	}
	contacts[iter].fill();
	iter++;
}

void PhoneBook::search() {
	std::ostream	cout(nullptr);
	std::string		tmp;

	cout.rdbuf(std::cout.rdbuf());
	cout.width(10);
	cout.flags(std::ios::right);
	for (int i = 0; i < 4; i++) {
		std::cout << "|";
		cout.width(10);
		cout.flags(std::ios::right);
		cout << columnTitles[i];
	}
	std::cout << "|" << std::endl;

	std::cout << "|" <<
		std::setfill('-') << std::setw(10) << "" <<
		"|" <<
		std::setfill('-') << std::setw(10) << "" <<
		"|" <<
		std::setfill('-') << std::setw(10) << "" <<
		"|" <<
		std::setfill('-') << std::setw(10) << "" <<
		"|" << std::endl;

	std::cout << std::setfill(' ');

	for (int i = 0; i < iter; i++) {
		// if fileds size == 0
		if (!this->contacts[i].getField(firstName).size() &&
			!this->contacts[i].getField(lastName).size() &&
			!this->contacts[i].getField(nickname).size())
			continue ;

		std::cout << "|";

		std::cout << std::setw(10);
		std::cout.flags(std::ios::right);
		std::cout << i;

		std::cout << "|";

		std::cout << std::setw(10);
		std::cout.flags(std::ios::right);
		tmp = this->contacts[i].getField(firstName);
		if (tmp.size() > 10)
			tmp.replace(9, tmp.size() - 1, ".");
		std::cout << tmp;

		std::cout << "|";

		std::cout << std::setw(10);
		std::cout.flags(std::ios::right);
		tmp = this->contacts[i].getField(lastName);
		if (tmp.size() > 10)
			tmp.replace(9, tmp.size() - 1, ".");
		std::cout << tmp;

		std::cout << "|";

		std::cout << std::setw(10);
		std::cout.flags(std::ios::right);
		tmp = this->contacts[i].getField(nickname);
		if (tmp.size() > 10)
			tmp.replace(9, tmp.size() - 1, ".");
		std::cout << tmp;

		std::cout << "|" << std::endl;
	}
}
