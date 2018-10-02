#include "SuperMutant.hpp"

SuperMutant::SuperMutant(170, "Super Mutant") :
	Enemy(hp, type) {

	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

~SuperMutant() {
	std::cout "Aaargh ..." << std::endl;
}

SuperMutant(const SuperMutant &src) :
	hp(src.getHP()), type(src.getType()) {

}

SuperMutant	&operator=(const SuperMutant &src) {
	hp = src.getHP();
	type = src.getType();

	return (*this);
}

void		takeDamage(int dmg) {

}
