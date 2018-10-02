#include "Pony.hpp"

Pony::Pony(int _age, int _height, int _width, int _weight, ponyColor_e _color) {
		age = _age;
		height = _height;
		width = _width;
		weight = _weight;
		color = _color;
}

void	Pony::saySomething() {
	std::cout << "Hello, I'm pony and my name is Rainbow Dash." << std::endl;
	std::cout << "I'm " << age << " years old. There are my parameters: " <<
		height << " centimeters of tall, " << width << " cm of wide and " <<
		weight << " kilograms of weight. Also I have " << ponyColorStr[color] << " skin." << std::endl;
}
