#include "Pony.hpp"

void ponyOnTheHeap () {
	Pony	*pony = new Pony(10, 150, 45, 90, WHITE);

	std::cout << "ponyOnTheHeap" << std::endl;
	pony->saySomething();
	delete pony;
}

void ponyOnTheStack () {
	Pony	pony(8, 135, 30, 70, BROWN);

	std::cout << "ponyOnTheStack" << std::endl;
	pony.saySomething();
}

int main(void) {
	ponyOnTheHeap();
	ponyOnTheStack();
	return 0;
}
