#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Victim.hpp"

int main()
{
	{
		Sorcerer robert("Robert", "the Magnificent");

		Victim jim("Jimmy");
		Peon joe("Joe");

		std::cout << robert << jim << joe;

		robert.polymorph(jim);
		robert.polymorph(joe);
	}

	std::cout << "-------------------- Another tests --------------------" << std::endl;
	{

		Sorcerer	bob("Bob", "the Mag");
		Victim		jack("Joe");
		Peon		norm("Norm");

		Sorcerer	bob_c(bob);
		Victim		jack_c(jack);
		Peon		norm_c(norm);

		std::cout << bob_c << std::endl;
		std::cout << jack_c << std::endl;
		std::cout << norm_c << std::endl;
	}

	return (0);
}
