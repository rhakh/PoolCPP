#include "RadScorpion.hpp"

RadScorpion::RadScorpion() :
Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

~RadScorpion()
{
	std::cout "* SPROTCH *" << std::endl;
}

RadScorpion(const RadScorpion &src) :
hp(src.getHP()), type(src.getType())
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion	&operator=(const RadScorpion &src)
{
	hp = src.getHP();
	type = src.getType();

	return (*this);
}
