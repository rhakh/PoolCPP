#include <iostream>
#include <string>
#include <cstdlib>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int     main(void)
{
    srand(time(NULL));
    
    {
        FragTrap    rob1("Bender");
        FragTrap    rob2(rob1);

        rob1.rangedAttack("Wall-e");
        rob1.meleeAttack("Wall-e");

        rob1.tackeDamage(50);
        rob1.tackeDamage(150);
        rob1.tackeDamage(1);

        rob1.beRepaired(50);
        rob1.beRepaired(150);
        rob1.beRepaired(1);

        rob1.vaulthunter_dot_exe("Hercules");
        rob1.vaulthunter_dot_exe("Hercules");
        rob1.vaulthunter_dot_exe("Hercules");
        rob1.vaulthunter_dot_exe("Hercules");
        rob1.vaulthunter_dot_exe("Hercules");
    }
    {
        ScavTrap    rob1("Calculon");
        ScavTrap    rob2(rob1);

        rob1.rangedAttack("Fray");
        rob1.meleeAttack("Fray");

        rob1.tackeDamage(50);
        rob1.tackeDamage(150);
        rob1.tackeDamage(1);

        rob1.beRepaired(50);
        rob1.beRepaired(150);
        rob1.beRepaired(1);

        rob1.challangeNewcomer();
        rob1.challangeNewcomer();
        rob1.challangeNewcomer();
    }
    
    return (0);
}