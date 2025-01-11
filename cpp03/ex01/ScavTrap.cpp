#include "ScavTrap.hpp"

ScavTrap::ClapTrap::ClapTrap(std::string& name) : _name(name), hitPt(100), energyPt(50), attackDamage(20)
{
	std::cout << "Scavtrap " << name << " has been created!" << std::endl; 
}

ScavTrap::ClapTrap::~ClapTrap()
{
	std::cout << "ScavTrap " << this->_name << " had been destroyed :(" << std::endl;
}

void ScavTrap::ClapTrap::attack(const std::string& target)
{
	if (this->energyPt > 0)
	{
		if (this->hitPt > 0)
		{
			std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
			this->energyPt--;
		}
		else
		{
			std::cout << "ScavTrap " << this->_name << " could not damage " << target << " because of it has no attack damage!" << std::endl;
		}
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " has no energy for attacking to " << target << std::endl;
	}
}