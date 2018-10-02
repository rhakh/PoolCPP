#include <iostream>
#include <cstdlib>

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

template<typename T>
void		iter(T *arr, size_t size, void (*func)(T &elem)) {
	size_t	i;

	for (i = 0; i < size; i++) {
		func(arr[i]);
	}
}

template<typename T>
void		print(T &a) {
	std::cout << a << ", ";
}

int main( void ) {
	srand(std::time(0));
	{
		std::string		arr[] = {"one", "two", "beer", "-42", "toto"};

		std::cout << "*** std::String array" << std::endl;
		iter<std::string>(arr, sizeof(arr) / sizeof(*arr), print);
		std::cout << std::endl << "***" << std::endl;
	}

	{
		int		arr[] = {42, 21, 402, -42, 84, 96};

		std::cout << "*** int array" << std::endl;
		iter<int>(arr, sizeof(arr) / sizeof(*arr), print);
		std::cout << std::endl << "***" << std::endl;
	}

	{
		FTclass		arr[5];

		std::cout << "*** FTclass array" << std::endl;
		iter<FTclass>(arr, sizeof(arr) / sizeof(*arr), print);
		std::cout << std::endl << "***" << std::endl;
	}

	return 0;
}
