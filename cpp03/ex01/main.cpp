#include "ClapTrap.hpp"

int main()
{
	std::string name = "FSM";
	ClapTrap cp(name);

	cp.attack("Byzantium");
	cp.takeDamage(3);
	cp.beRepaired(2);
	cp.attack("Byzantium");
	cp.takeDamage(4);
	cp.beRepaired(2);
	cp.attack("Byzantium");
	cp.takeDamage(5);
	cp.beRepaired(3);
	cp.attack("Byzantium");
	cp.takeDamage(3);
	cp.beRepaired(1);
	cp.attack("Byzantium");
	cp.attack("Byzantium");
	cp.attack("Byzantium");
}