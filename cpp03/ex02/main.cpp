#include "FragTrap.hpp"

int main()
{
	std::cout << "\033[31mCLAPTRAP TEST\033[0m" << std::endl << std::endl;
	{
		ClapTrap cp("FSM");

		cp.attack("Byzantium");
		cp.takeDamage(3);
		cp.beRepaired(2);
		cp.attack("Byzantium");
		cp.takeDamage(100);
		cp.beRepaired(2);
		cp.attack("Byzantium");
	}
	std::cout << std::endl << "\033[31mSCAVTRAP TEST\033[0m" << std::endl << std::endl;
	{
		ScavTrap sc("Petito");

		sc.guardGate();
		sc.guardGate();
		for (int i = 0; i < 15; i++)
			sc.attack("Someone in the street");
		std::cout << std::endl << "\033[34mI guess this much violance is enough?\033[0m" << std::endl;
		std::cout << "\033[34mJust kidding LOL my turn\033[0m" << std::endl;
		for (int i = 0; i < 10; i++)
			sc.takeDamage(12);
		std::cout << "\033[34mI thinks it's dead!\033[0m" << std::endl;
		sc.beRepaired(10);
		std::cout << "\033[34mDid you really tried that :D\033[0m" << std::endl;
	}
	std::cout << std::endl << "\033[31mFRAGTRAP TEST\033[0m" << std::endl << std::endl;
	{
		FragTrap ft("VIRRAK");

		ft.highFivesGuys();
		ft.takeDamage(20);
		ft.beRepaired(4);
		ft.attack("FLIES");
		ft.takeDamage(95);
		ft.takeDamage(2);
		
		FragTrap second(ft);

		second.takeDamage(35);
		second.attack("Another flies");
		second.beRepaired(15);
	}
	return (0);
}