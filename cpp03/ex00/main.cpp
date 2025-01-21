#include "ClapTrap.hpp"

int main()
{
	std::string name = "FSM";
	ClapTrap first(name);
	ClapTrap cp(first);

	cp.attack("Byzantium");
	cp.takeDamage(3);
	cp.beRepaired(2);
	cp.attack("Byzantium");
	cp.takeDamage(100);
	cp.beRepaired(2);
	cp.attack("Byzantium");
}