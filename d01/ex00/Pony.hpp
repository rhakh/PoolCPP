#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

enum ponyColor_e { WHITE, BLACK, BROWN };

const std::string	ponyColorStr[3] = {"white", "black", "brown"};

class Pony {
	int		age;
	int		height;
	int		width;
	int		weight;
	ponyColor_e	color;

public:
	Pony(int _age, int _height, int _width, int _weight, ponyColor_e _color);

	void	saySomething();
};

#endif // PONY_HPP
