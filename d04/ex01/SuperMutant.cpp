#include "SuperMutant.hpp"

SuperMutant::SuperMutant() :
Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

~SuperMutant()
{
	std::cout "Aaargh ..." << std::endl;
}

SuperMutant(const SuperMutant &src) :
hp(src.getHP()), type(src.getType())
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant	&operator=(const SuperMutant &src)
{
	hp = src.getHP();
	type = src.getType();

	return (*this);
}

void		takeDamage(int dmg)
{
	dmg -= 3;
	if (dmg >= 0) {
		this->hp -= dmg;
	}
	(this->hp < 0) ? (this->hp = 0;) : (0);
}
