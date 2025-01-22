#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "No-name";
	this->hitPt = 100;
	this->energyPt = 50;
	this->attackDamage = 20;
	this->keeperMode = false;
	std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->hitPt = 100;
	this->energyPt = 50;
	this->attackDamage = 20;
	this->keeperMode = false;
	std::cout << "ScavTrap " << this->_name << " constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref)
{
	this->keeperMode = ref.keeperMode;
	std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& ref)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = ref._name;
	this->hitPt = ref.hitPt;
	this->energyPt = ref.energyPt;
	this->attackDamage = ref.attackDamage;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPt == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is like dead. It can't attack!" << std::endl;
	}
	else if (this->energyPt > 0)
	{
		if (this->attackDamage > 0)
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

void	ScavTrap::guardGate(void)
{
	if (this->keeperMode == false)
	{
		this->keeperMode = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate!" << std::endl;
}
