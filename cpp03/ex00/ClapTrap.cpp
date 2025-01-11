#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string& name) : hitPt(10), energyPt(10), attackDamage(0)
{
	this->_name = name;
	std::cout << "ClapTrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPt > 0)
	{
		if (this->hitPt > 0)
		{
			std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
			this->energyPt--;
		}
		else
		{
			std::cout << "ClapTrap " << this->_name << " could not damage " << target << " because of it has no attack damage!" << std::endl;
		}
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has no energy for attacking to " << target << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPt > amount)
		this->hitPt -= amount;
	else if (this->hitPt > 0)
		this->hitPt = 0;
	else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead, stop beating it!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " was attacked and lost " << amount << " hit points, he now has " << this->hitPt << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPt > 0)
	{
		this->hitPt += amount;
		std::cout << "ClapTrap " << this->_name << " gets hit point back in the amount of " << amount << std::endl;
		this->energyPt--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has no energy for repairing!" << std::endl;
	}
}