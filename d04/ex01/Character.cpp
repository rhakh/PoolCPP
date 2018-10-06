#include "Character.hpp"

Character::Character(const std::string &_name)
name(_name), weapon(NULL), ap(40)
{

}

Character::Character()
name(""), weapon(NULL), ap(40)
{
    
}

Character::Character(const Character &src)
name(src.name), weapon(src.weapon), ap(src.ap)
{

}

Character::~Character()
{

}

Character		&Character::operator=(const Character &rhs)
{
    this->name = rhs.name;
    this->ap = rhs.ap;
    this->weapon = rhs.weapon;
    
    return (*this);
}

void    Character::recoverAP()
{
    this->ap += 10;
    (this->ap > 40) ? (this->ap = 40;) : (0);
}

void    Character::equip(AWeapon *weapon)
{
    if (weapon)
        this->weapon = weapon;
}

void    Character::attack(Enemy *enemy)
{
    if (enemy && this->weapon && this->ap >= this->weapon->getAPcost()) {
        this->ap -= this->weapon->getAPcost();
        enemy->takeDamage(weapon->getDamage());
        std::cout << this->name
                    << " attacks "
                    << enemy->getType()
                    << " with a"
                    << this->weapon->getName()
                    << std::endl;
    }
}

const std::string	&Character::getName() const;

std::ostream    &operator<<(std::ostream &os, const Character &rhs)
{
	if (rhs.getWeapon())
        os << rhs.getName()<< " has "<< rhs.getAP()
            << " AP and wields a " << rhs.getWeapon()->getName()
            << std::endl;
	else
        os << rhs.getName()<< " has "<< rhs.getAP()
            << " AP and is unarmed"
            << std::endl;
	return (os);
}