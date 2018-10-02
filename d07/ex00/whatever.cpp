#include <iostream>

template<typename T>
void	swap(T &a, T &b) {
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	&min(T &a, T &b) {
	return ((a < b) ? a : b );
}

template<typename T>
T	&max(T &a, T &b) {
	return ((a > b) ? a : b );
}

int main( void ) {
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	{
		int a = 3;
		int b = 3;

		std::cout << "a = " << a << ", b = " << b << std::endl;

		if (&(::min(a, b)) == &b)
			std::cout << "Min Return second one" << std::endl;
		else
			std::cout << "Min Return first one" << std::endl;

		if (&(::max(a, b)) == &b)
			std::cout << "Max Return second one" << std::endl;
		else
			std::cout << "Max Return first one" << std::endl;

		/*--------------------------------------------------*/

		std::string c = "chaine1";
		std::string d = "chaine1";

		std::cout << "c = " << c << ", d = " << d << std::endl;

		if (&(::min(c, d)) == &d)
			std::cout << "Min Return second one" << std::endl;
		else
			std::cout << "Min Return first one" << std::endl;

		if (&(::max(c, d)) == &d)
			std::cout << "Max Return second one" << std::endl;
		else
			std::cout << "Max Return first one" << std::endl;

	}

	return 0;
}
