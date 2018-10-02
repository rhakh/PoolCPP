#ifndef PLASMA_RIFLE_HPP
#define PLASMA_RIFLE_HPP

#include "AWeapon.hpp"
#include <iostream>
#include <string>

class PlasmaRifle : public AWeapon{

public:
	PlasmaRifle();
	~PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &src);

	PlasmaRifle	&operator=(const PlasmaRifle &src);

	void		attack() const;
};

#endif // PLASMA_RIFLE_HPP
