#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "Enemy.hpp"
#include "Weapon.hpp"

class Character {

    std::string name;
    AWeapon     *wepon;
    int         ap;
 
public:
	Character();
	Character(const Character &src);
	~Character();
    Character		&operator=(const Character &rhs);
    
    void    recoverAP();
    void    equip(AWeapon *weapon);
    void    attack(Enemy *enemy);
    const std::string	&getName() const;
}

std::ostream    &operator<<(std::ostream &os, const Character &rhs);

#endif // CHARACTER_HPP