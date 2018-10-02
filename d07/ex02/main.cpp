#include "Array.hpp"
#include <iostream>

class FTclass {
	int		numb;

public:
	FTclass();
	FTclass(const FTclass &ft);
	~FTclass();
	FTclass		&operator=(const FTclass &ft);

	int		getNumb() const;
};

FTclass::FTclass() {
	numb = rand() % 100;
}

FTclass::FTclass(const FTclass &ft) {
	*this = ft;
}

FTclass::~FTclass() {}

FTclass		&FTclass::operator=(const FTclass &ft) {
	this->numb = ft.getNumb();
	return (*this);
}

int		FTclass::getNumb() const {
	return (this->numb);
}

std::ostream		&operator<<(std::ostream &os, FTclass &ft) {
	os << "FTclass entity(" << ft.getNumb() << ")";
	return (os);
}

int		main(void) {
	std::cout << "*** Custom class" << std::endl;
	{
		Array<FTclass>	arr(30);

		for (unsigned int i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << "***" << std::endl;

	/* Exception */
	std::cout << "*** Exception" << std::endl;
	{
		Array<FTclass>	arr(4);

		try {
			for (unsigned int i = 0; i < arr.size() + 1; i++) {
				std::cout << arr[i] << ", ";
			}
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << " out of range" << std::endl;
		}
	}
	std::cout << "***" << std::endl;

	/* Exception NULL*/
	std::cout << "*** Exception NULL" << std::endl;
	{
		Array<FTclass>	arr;

		try {
			std::cout << arr[0] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << " out of range" << std::endl;
		}
	}
	std::cout << "***" << std::endl;
	return (0);
}
