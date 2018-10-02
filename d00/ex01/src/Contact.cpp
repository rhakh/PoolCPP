#include "Contact.hpp"

void	Contact::fill() {
	for (int i = firstName; i < lastField; i++) {
		std::cout << "Enter " << fieldNames[i] << ": ";
		std::getline(std::cin, this->fields[i]);
		if (std::cin.eof()) {
			std::cout << "EOF was found" << std::endl;
			freopen(NULL, "rw", stdin);
		}
	}
}

Contact::Contact() {

}

void	Contact::printContact() const {
	for (int i = firstName; i < lastField; i++) {
		std::cout << fieldNames[i]
					<< ": "
					<< this->fields[i]
					<< std::endl;
	}
}

std::string		&Contact::getField(contactFields_e field) {
	return (this->fields[field]);
}
