#ifndef POWER_FIST_HPP
#define POWER_FIST_HPP

#include "AWeapon.hpp"
#include <iostream>
#include <string>

class PowerFist : public AWeapon{

public:
	PowerFist();
	~PowerFist();
	PowerFist(const PowerFist &src);

	PowerFist	&operator=(const PowerFist &src);

	void		attack() const;
};

#endif // POWER_FIST_HPP
