#ifndef SUPER_MUTANT_HPP
#define SUPER_MUTANT_HPP

#include "Enemy.hpp"
#include <iostream>
#include <string>


class SuperMutant : public Enemy {

public:
	SuperMutant();
	~SuperMutant();
	SuperMutant(const SuperMutant &src);

	SuperMutant	&operator=(const SuperMutant &src);

	void		takeDamage(int dmg);
};

#endif // SUPER_MUTANT_HPP
